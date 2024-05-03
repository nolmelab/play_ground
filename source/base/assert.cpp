#include <playground/base/assert.hpp>
#include <playground/base/logger.hpp>

#include <cassert>

namespace playground
{

  void Assert::log(bool cond, const char* expr, const char* file, int line)
  {
    if ( !cond )
    {
      auto m = fmt::format("assert failed. expr: {}, file: {}, line: {}", expr, file, line);      
      PG_ERROR(m);
      Logger::get()->flush();
      if ( abort_ )
      {
        assert(!"assert failed");
      }
    }
  }

} // playground