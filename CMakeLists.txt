cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 23)

project(
  penguin
  VERSION 1.0.0.0
  LANGUAGES C CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

find_package(ut REQUIRED CONFIG)

# Projects
add_subdirectory(projects/penguin)
add_subdirectory(projects/hello_shared)

# Tests
enable_testing()
add_subdirectory(tests/penguin_test)
