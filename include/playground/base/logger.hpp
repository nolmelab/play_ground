#pragma once

#include <playground/base/macros.hpp>
#include <spdlog/spdlog.h>
#include <atomic>

namespace playground 
{

/// @brief system logger
/**
 * 
 */
class Logger
{
public:
  static std::shared_ptr<spdlog::logger> get(); 

private:
  static Logger& get_instance();
  static void setup();

private:
  std::atomic<bool> initialized_{false};
};

} // playground

#define PG_TRACE(m) playground::Logger::get()->trace(m)
#define PG_DEBUG(m) playground::Logger::get()->debug(m)
#define PG_INFO(m) playground::Logger::get()->info(m)
#define PG_WARN(m) playground::Logger::get()->warn(m)
#define PG_ERROR(m) playground::Logger::get()->error(m)