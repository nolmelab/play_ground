#include <playground/core/logger.hpp>

#include <spdlog/async.h>
#include <spdlog/async_logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/daily_file_sink.h>

namespace playground 
{
  void Logger::setup()
  {
    get_instance().initialized_ = true;

    spdlog::init_thread_pool(32*1024, 1);
    auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto daily_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>("logs/system.log", 0, 0);
    std::vector<spdlog::sink_ptr> sinks{stdout_sink, daily_sink};

    auto logger = std::make_shared<spdlog::async_logger>(
        "system",
        sinks.begin(),
        sinks.end(),
        spdlog::thread_pool(),
        spdlog::async_overflow_policy::block);

    spdlog::register_logger(logger);
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%L%$][%t] %v");
  }

  std::shared_ptr<spdlog::logger> Logger::get()
  {
    auto& logger = get_instance();
    if (!logger.initialized_)
    {
      setup();
    }

    return spdlog::get("system");
  }

  Logger& Logger::get_instance()
  {
    static Logger instance_;
    return instance_; 
  }

} // playground