#include <doctest/doctest.h>
#include <playground/base/assert.hpp>

TEST_CASE("assert")
{
  SUBCASE("basic failure")
  {
    PG_ASSERT( 1 > 3);
  }
  
  SUBCASE("call abort on failure")
  {
    // uncomment to test abort with assert()
    // playground::Assert::set_abort();
    PG_ASSERT( 1 > 3);
  }
}