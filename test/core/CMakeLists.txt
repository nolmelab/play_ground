project("test_core")

# find vcpkg packages
find_package(spdlog CONFIG REQUIRED)
find_package(doctest CONFIG REQUIRED)

# add test target
add_executable(test_core main.cpp test_logger.cpp)

# add link libraries. playground_core is available with cmake
target_link_libraries(test_core playground_core spdlog::spdlog doctest::doctest)

# add include directories, especially playground
target_include_directories(test_core PRIVATE "${CMAKE_SOURCE_DIR}/include")

