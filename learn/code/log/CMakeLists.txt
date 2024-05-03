cmake_minimum_required(VERSION 3.15)
project("learn_log" VERSION 0.1)

find_package(spdlog CONFIG REQUIRED)

add_executable(learn_log main.cpp)
target_link_libraries(learn_log PRIVATE spdlog::spdlog)

