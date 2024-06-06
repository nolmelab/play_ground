cmake_minimum_required(VERSION 3.15)
project("ex_code" VERSION 0.1)

add_subdirectory(collision)

find_package(spdlog CONFIG REQUIRED)
find_package(doctest CONFIG REQUIRED)
find_package(unofficial-sodium CONFIG REQUIRED)

add_executable(
    ex_code 
    main.cpp 
    ex_spdlog.cpp
    ex_asio_reading.cpp
    ex_asio_tutorial.cpp
    ex_asio_example.cpp
    ex_c++.cpp
    sodium/ex_sodium.cpp
    chat/chat_server.cpp
    chat/chat_client.cpp
)

target_link_libraries(
    ex_code 
    PRIVATE 
    spdlog::spdlog 
    doctest::doctest
    unofficial-sodium::sodium
    playground_base
)

# add include directories, especially playground
target_include_directories(
  ex_code
  PRIVATE "${CMAKE_SOURCE_DIR}/include"
  PRIVATE "${CMAKE_SOURCE_DIR}/exercise/code"
)