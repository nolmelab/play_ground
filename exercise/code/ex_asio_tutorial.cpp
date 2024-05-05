#include <doctest/doctest.h>

#include <playground/base/logger.hpp>
#include <boost/asio.hpp>

namespace asio = boost::asio;

TEST_CASE("asio tutorial")
{
  /// timer with an io_context object.
  /**
   * https://think-async.com/Asio/boost_asio_1_30_2/doc/html/boost_asio/reference.html
   * The above link has detailed description of asio classes.
   *
   * # io_context
   *
   *
   */
  SUBCASE("timer.1 - using tiemr synchronously")
  {
    asio::io_context io;

    PG_INFO("preparing steady_timer");

    asio::steady_timer timer(io, asio::chrono::milliseconds(3));
    timer.wait();

    PG_INFO("hello steady_timer");
  }

  SUBCASE("post")
  {
    asio::io_context io;

    io.post([]()
            { PG_INFO("io_context::post"); });

    io.run();

    SUBCASE("understanding internal")
    {
      // template <typename LegacyCompletionHandler>
      // auto io_context::post(LegacyCompletionHandler&& handler)
      // -> decltype(
      //    async_initiate<LegacyCompletionHandler, void ()>(
      //    declval<initiate_post>(), handler, this))
      // {
      //   return async_initiate<LegacyCompletionHandler, void ()>(
      //   initiate_post(), handler, this);
      // }
      //
      /**
       * decltype infers the type of a statment or an expression
       */
      SUBCASE("decltype")
      {
        decltype(1 + 3) v = 0;
      }

      /**
       * why is it required?
       *
       * Converts any type T to a reference type, making it possible to use member functions
       * in the operand of the decltype specifier without the need to go through constructors.
       * std::declval is commonly used in templates where acceptable template parameters
       * may have no constructor in common, but have the same member function whose
       * return type is needed.
       *
       * - used to have a rvalue reference object to deduce member types without constructing an object
       * - it seems like a magic, but it works with a compiler, who knows everything.
       */
      SUBCASE("declval")
      {
        // declval<initiate_post>
      }

      /**
       * a helper function to create a async_result trait object
       *
       * - async_completion<CompletionToken, Signatures...> completion(token)
       * - returns completion.result.get()
       */
      SUBCASE("async_initiate")
      {
        // this is asio level mastery of C++ and conceptual structure design of complicated
        // diverse behavior abstractions on system programming side.
      }
    }
  }

  SUBCASE("timer.2 - using a timer async")
  {
    asio::io_context io;

    asio::steady_timer timer(io, asio::chrono::milliseconds(3));

    PG_INFO("prepare async timer");

    timer.async_wait([](boost::system::error_code ec)
                     { PG_INFO(fmt::format("run async timer. message: {}", ec.message())); });

    io.run();      
  }

  SUBCASE("timer.3 - binding arguments to a completion handler")
  {
    // lambda capture is prefered way for me.
    // std::bind and asio::placeholders are useful
  }

  SUBCASE("timer.5 - synchronising completion handlers in multithreaded programs")
  {
    asio::io_context io;
    asio::strand<asio::io_context::executor_type> strand(asio::make_strand(io));

    asio::steady_timer timer1(io, asio::chrono::milliseconds(1));
    asio::steady_timer timer2(io, asio::chrono::milliseconds(1));

    timer1.async_wait(
        asio::bind_executor(strand, [&timer1](boost::system::error_code ec) {
          PG_INFO("timer1 in strand");
          timer1.expires_after(asio::chrono::milliseconds(1)); }));

    timer1.async_wait(
        asio::bind_executor(strand, [&timer2](boost::system::error_code ec) {
          PG_INFO("timer2 in strand");
          timer2.expires_after(asio::chrono::milliseconds(1)); }));

    io.run();
  }

}

// tcp tutorials

#include <ctime>
#include <array>

using asio::ip::tcp;

TEST_CASE("asio tutorial tcp")
{
  auto make_daytime_string = []() {
    auto now = std::time(0);
    return ctime(&now);
  };

  SUBCASE("daytime client and server - sync")
  {
    asio::io_context io;

    bool stop = false;

    try 
    {
      // server
      // port 13 requires root permission. hence using 1300 instead. 
      tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 1300));

      std::thread thread_server([&io, &acceptor, &stop, &make_daytime_string]() {
        tcp::socket socket(io);
        acceptor.accept(socket);

        std::string daytime(make_daytime_string());
        boost::system::error_code ec;
        asio::write(socket, asio::buffer(daytime), ec);
      });

      // client
      {
        tcp::socket client(io);

        asio::ip::address local = asio::ip::make_address("127.0.0.1");
        tcp::endpoint endpoint(local, 1300);

        client.connect(endpoint);

        std::array<char, 128> buf;
        boost::system::error_code ec;

        auto len = client.read_some(asio::buffer(buf), ec);
        std::string m(buf.data(), len);
        PG_INFO(fmt::format("daytime: {}", m));
      }

      io.run();

      thread_server.join();
    }
    catch ( const std::exception& ex)
    {
      PG_ERROR(fmt::format("{}", ex.what()));
    }
  }

  SUBCASE("daytime client and server - async")
  {
    asio::io_context io;

    try
    {  
      bool server_sent = false;
      // server
      tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 1300));

      tcp::socket socket(io);
      acceptor.async_accept(socket, [&server_sent, &socket, &make_daytime_string](boost::system::error_code ec) {
          std::string daytime(make_daytime_string());
          asio::write(socket, asio::buffer(daytime), ec); // sync write for now
          server_sent = true; 
      });

      bool client_recv = false;
    
      // client
      {
        tcp::socket client(io);

        asio::ip::address local = asio::ip::make_address("127.0.0.1");
        tcp::endpoint endpoint(local, 1300);

        client.async_connect(endpoint, [&client_recv, &client](boost::system::error_code ec){
          std::array<char, 128> buf;
          boost::system::error_code ec2;
          // TODO: socket is in eof state. why?
          // after async_accept is finished, the socket is in estabilshed state
          // but, sometimes (under timing differences) async_connect is called before async_asccept is finished
          // then, client socket is in eof state. hence following read_some finished with eof error
          // that's the current reasoning. therefore, if we use async ops, then we need to have classes 
          // to process states with proper progress.
          auto len = client.read_some(asio::buffer(buf), ec2); // uses a sync read
          std::string m(buf.data(), len);
          PG_INFO(fmt::format("daytime: {}", m));
          client_recv = true;
        });
      }

      while (!server_sent || !client_recv)
      {
        io.run();
      }

      PG_INFO("end of async tcp daytime test");
      playground::Logger::get()->flush();
    }
    catch ( const std::exception& ex)
    {
      PG_ERROR(fmt::format("{}", ex.what()));
    }
  }
}