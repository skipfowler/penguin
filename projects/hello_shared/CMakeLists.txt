cmake_minimum_required(VERSION 3.15)

project(
  hello_shared
  VERSION ${CMAKE_PROJECT_VERSION}
  LANGUAGES CXX
)

add_library(
  ${PROJECT_NAME} SHARED
  hello_shared.cpp
)

add_library(
  ${PROJECT_NAME}::${PROJECT_NAME} ALIAS
  ${PROJECT_NAME}
)

target_include_directories(
  ${PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
