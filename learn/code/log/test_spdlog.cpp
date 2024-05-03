#include <doctest/doctest.h>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/daily_file_sink.h>

TEST_CASE("spdlog")
{
    /// add multiple sinks. Essential ones are daily file, colored console, async logger
    SUBCASE("multi sinks")
    {

    }
}