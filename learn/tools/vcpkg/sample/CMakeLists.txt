cmake_minimum_required(VERSION 3.22)
project("Sample")

# set(CMAKE_TOOLCHAIN_FILE "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake")
# set(VCPKG_TARGET_TRIPLET "x64-linux")
# include(${CMAKE_TOOLCHAIN_FILE})

find_package(spdlog CONFIG REQUIRED)

add_executable(Sample Main.cpp)
target_link_libraries(Sample PRIVATE spdlog::spdlog)

