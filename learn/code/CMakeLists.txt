cmake_minimum_required(VERSION 3.15)
project("learn_code" VERSION 0.1)

find_package(spdlog CONFIG REQUIRED)
find_package(doctest CONFIG REQUIRED)

add_executable(
    learn_code 
    main.cpp 
    test_spdlog.cpp
)

target_link_libraries(
    learn_code 
    PRIVATE 
    spdlog::spdlog 
    doctest::doctest
)

