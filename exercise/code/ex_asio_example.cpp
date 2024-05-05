#include <doctest/doctest.h>

#include <playground/base/logger.hpp>
#include <boost/asio.hpp>

namespace asio = boost::asio;

TEST_CASE("asio examples")
{
  // impl and understand asio tutorials
  SUBCASE("tutorials")
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

      io.post([]() {
        PG_INFO("io_context::post");
      });

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

      timer.async_wait([](boost::system::error_code ec) {
        PG_INFO(fmt::format("run async timer. message: {}", ec.message()));
      });

      io.run();      
    }

    SUBCASE("timer.3 - binding arguments to a completion handler")
    {
      // lambda capture is prefered way for me.
      // std::bind and asio::placeholders are useful
    }


    SUBCASE("timer.5 - synchronising completion handlers in multithreaded programs")
    {
    }
  }
}