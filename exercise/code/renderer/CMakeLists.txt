cmake_minimum_required(VERSION 3.15)

find_package(spdlog CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(
    rend 
    main.cpp 
    tgaimage.cpp
    model.cpp
)

set(CMAKE_CXX_FLAGS "-O0 -ggdb -g -pg")

# add include directories, especially playground
target_include_directories(
  rend
  PRIVATE "${CMAKE_SOURCE_DIR}/include"
  PRIVATE "${CMAKE_SOURCE_DIR}/exercise/code"
)

target_link_libraries(rend PRIVATE glm::glm-header-only)