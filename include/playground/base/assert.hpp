#pragma once

#include <playground/base/macros.hpp>

namespace playground 
{

class Assert
{
public:
  /// log assert failure into system log 
  static void log(bool cond, const char* expr, const char* file, int line);

  /// call assert(). default enabled
  static void set_abort()
  {
    abort_ = true;
  }

  /// disable call assert()
  static void clear_abort()
  {
    abort_ = false;
  }

private:
  static inline bool abort_{true};
};

} // playground

#define PG_ASSERT(cond) if (!(cond)) { \
  playground::Assert::log((cond), #cond, __FILE__, __LINE__); \
}

#define PG_ASSERT_RETURN_IF(cond) if(!(cond)) { \
  playground::Assert::log((cond), #cond, __FILE__, __LINE__); \
  return; \
}

#define PG_ASSERT_RETURN_VALUE_IF(cond, value) if(!(cond)) { \
  playground::Assert::log((cond), #cond, __FILE__, __LINE__); \
  return (value); \
}