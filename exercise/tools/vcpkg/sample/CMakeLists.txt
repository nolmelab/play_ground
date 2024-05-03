cmake_minimum_required(VERSION 3.15)
project("sample")

# set(CMAKE_TOOLCHAIN_FILE "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake")
# set(VCPKG_TARGET_TRIPLET "x64-linux")
# include(${CMAKE_TOOLCHAIN_FILE})

find_package(spdlog CONFIG REQUIRED)

add_executable(sample main.cpp)
target_link_libraries(sample PRIVATE spdlog::spdlog)

