project("playground_core")

find_package(spdlog CONFIG REQUIRED)
find_package(doctest CONFIG REQUIRED)

# set sources for playground_core
set(SOURCE 
  logger.cpp
  assert.cpp
)

# set library target with sources
add_library(playground_base ${SOURCE})

# add include path
target_include_directories(playground_base PRIVATE "${CMAKE_SOURCE_DIR}/include")

# add link libaries
target_link_libraries(playground_base spdlog::spdlog doctest::doctest)


