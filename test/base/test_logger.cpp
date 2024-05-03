#include <doctest/doctest.h>

#include <playground/base/logger.hpp>

/// test logger 
/**
 * checks with console or system*.log file under logs folder 
 */
TEST_CASE("test_logger")
{
  SUBCASE("basic usage")
  {
    playground::Logger::get()->set_level(spdlog::level::trace);

    PG_TRACE("hello playground logger trace");
    PG_DEBUG("hello playground logger debug");
    PG_INFO("hello playground logger info");
    PG_WARN("hello playground logger warn");
    PG_ERROR("hello playground logger error");

    playground::Logger::get()->flush();
  }

  SUBCASE("change log level")
  {
    playground::Logger::get()->set_level(spdlog::level::trace);
    PG_TRACE("1");

    playground::Logger::get()->set_level(spdlog::level::debug);
    PG_TRACE("2");

    playground::Logger::get()->set_level(spdlog::level::trace);
    PG_TRACE("3");

    playground::Logger::get()->flush();
  }

  SUBCASE("log time test")
  {
    PG_INFO("first");
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    PG_INFO("second");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    PG_INFO("third");

    playground::Logger::get()->flush();
  }

  SUBCASE("thread id test")
  {
    PG_INFO("from main");

    auto thread = std::thread([](){
      PG_INFO("from thread");
    });

    thread.join();
  } 
}