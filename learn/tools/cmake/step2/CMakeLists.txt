cmake_minimum_required(VERSION 3.5)
project("step2" VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(math)
add_executable(step2 step2.cpp)

target_link_libraries(step2 Math)
target_include_directories(step2 PUBLIC "${PROJECT_SOURCE_DIR}")

# CMAKE_CURRENT_SOURCE_DIR 

