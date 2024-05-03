cmake_minimum_required(VERSION 3.5)
project("step4" VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(math)
add_executable(step4 step4.cpp)

target_link_libraries(step4 math)
target_include_directories(step4 PUBLIC "${PROJECT_SOURCE_DIR}")

# CMAKE_CURRENT_SOURCE_DIR 

#set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
#set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

#include(CMakePrintHelpers)
#cmake_print_variables(gcc_like_cxx)
#cmake_print_variables(msvc_cxx)