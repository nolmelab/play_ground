#include <doctest/doctest.h>

#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#include <spdlog/async_logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/daily_file_sink.h>

TEST_CASE("spdlog")
{
    /// basic colored console 
    SUBCASE("colored console")
    {
        auto console = spdlog::stdout_color_mt("console");
        spdlog::get("console")->info("hello console");
    }

    /// add multiple sinks. Essential ones are daily file, colored console, async logger
    SUBCASE("multi sinks")
    {

    }

    /// Almost the final system logger
    SUBCASE("async logger with multi sinks")
    {
        spdlog::init_thread_pool(32*1024, 1);
        auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        auto daily_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>("logs/system.log", 0, 0);
        std::vector<spdlog::sink_ptr> sinks{stdout_sink, daily_sink};

        auto logger = std::make_shared<spdlog::async_logger>(
            "system", 
            sinks.begin(), 
            sinks.end(), 
            spdlog::thread_pool(), 
            spdlog::async_overflow_policy::block
        );

        spdlog::register_logger(logger);

        spdlog::get("system")->info("hello system");
    }

    /// set custom pattern
    SUBCASE("set custom pattern")
    {
        spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
        spdlog::get("console")->info("hello console");
    }
}