cmake_minimum_required(VERSION 3.15)
project("ex_code" VERSION 0.1)

find_package(spdlog CONFIG REQUIRED)
find_package(doctest CONFIG REQUIRED)

add_executable(
    ex_code 
    main.cpp 
    ex_spdlog.cpp
    ex_asio_reading.cpp
    ex_asio_tutorial.cpp
)

target_link_libraries(
    ex_code 
    PRIVATE 
    spdlog::spdlog 
    doctest::doctest
    playground_base
)

# add include directories, especially playground
target_include_directories(
  ex_code
  PRIVATE "${CMAKE_SOURCE_DIR}/include"
)