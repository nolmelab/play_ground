project("test_base")

# find vcpkg packages
find_package(spdlog CONFIG REQUIRED)
find_package(doctest CONFIG REQUIRED)

# add test target
add_executable(
  test_base
  main.cpp 
  test_logger.cpp
  test_assert.cpp
)

# add link libraries. playground_core is available with cmake
target_link_libraries(
  test_base
  playground_base 
  spdlog::spdlog 
  doctest::doctest
)

# add include directories, especially playground
target_include_directories(
  test_base 
  PRIVATE "${CMAKE_SOURCE_DIR}/include"
)

