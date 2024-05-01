cmake_minimum_required(VERSION 3.15)
project("Tools" VERSION 0.1)

# setup vcpkg use
set(CMAKE_TOOLCHAIN_FILE "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_TARGET_TRIPLET "x64-linux")
include(${CMAKE_TOOLCHAIN_FILE})

add_subdirectory(CMake)
add_subdirectory(Vcpkg)

