#include <doctest/doctest.h>

#include <playground/base/logger.hpp>
#include <boost/asio.hpp>

namespace asio = boost::asio;

TEST_CASE("asio")
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
      
      asio::steady_timer timer(io, asio::chrono::seconds(3));
      timer.wait();

      PG_INFO("hello steady_timer");
    }
  }

  // impl and understand asio examples
  SUBCASE("examples")
  {


  }


  SUBCASE("c++")
  {
    SUBCASE("why is decay_t required?")
    {
    }

    SUBCASE("how do forward and move work?")
    {

    }
  }

  SUBCASE("c++ 20 coroutine support")
  {
    SUBCASE("coroutine")
    {

    }
  }
}