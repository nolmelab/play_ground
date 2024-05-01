cmake_minimum_required(VERSION 3.5)
project("Step2" VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(Math)
add_executable(Step2 Step2.cpp)

target_link_libraries(Step2 Math)
target_include_directories(Step2 PUBLIC "${PROJECT_SOURCE_DIR}")

# CMAKE_CURRENT_SOURCE_DIR 

