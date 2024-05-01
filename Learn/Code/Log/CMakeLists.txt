cmake_minimum_required(VERSION 3.22)
project("LearnLog" VERSION 0.1)

find_package(spdlog CONFIG REQUIRED)

add_executable(LearnLog Main.cpp)
target_link_libraries(LearnLog PRIVATE spdlog::spdlog)

