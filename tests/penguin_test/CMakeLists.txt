cmake_minimum_required(VERSION 3.15)

project(
  penguin_test
  VERSION ${CMAKE_PROJECT_VERSION}
  LANGUAGES CXX
)

add_executable(
  ${PROJECT_NAME}
  main.cpp
)

target_link_libraries(
  ${PROJECT_NAME} PRIVATE
  penguin::penguin
  Boost::ut
)

add_test(
  NAME ${PROJECT_NAME}
  COMMAND ${PROJECT_NAME}
)