#include <doctest/doctest.h>

#include <playground/core/logger.hpp>

TEST_CASE("test_logger")
{
  SUBCASE("basic usage")
  {
    PG_INFO("hello playground logger");
    PG_TRACE("hello playground logger trace");
    PG_DEBUG("hello playground logger debug");
    PG_WARN("hello playground logger warn");
    PG_ERROR("hello playground logger error");
  }
}