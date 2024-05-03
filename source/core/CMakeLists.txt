project("playground_core")

find_package(spdlog CONFIG REQUIRED)
find_package(doctest CONFIG REQUIRED)

# set sources for playground_core
set(SOURCE logger.cpp)

# set library target with sources
add_library(playground_core ${SOURCE})

# add include path
target_include_directories(playground_core PRIVATE "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(playground_core spdlog::spdlog doctest::doctest)


