#include <doctest/doctest.h>

#include <playground/core/logger.hpp>

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
}