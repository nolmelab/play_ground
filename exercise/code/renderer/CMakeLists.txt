cmake_minimum_required(VERSION 3.15)

find_package(spdlog CONFIG REQUIRED)

add_executable(
    rend 
    main.cpp 
    tgaimage.cpp
)

# add include directories, especially playground
target_include_directories(
  rend
  PRIVATE "${CMAKE_SOURCE_DIR}/include"
  PRIVATE "${CMAKE_SOURCE_DIR}/exercise/code"
)