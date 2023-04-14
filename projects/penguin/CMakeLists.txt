cmake_minimum_required(VERSION 3.15)

project(
  penguin
  VERSION ${CMAKE_PROJECT_VERSION}
  LANGUAGES C
)

if(IS_SHARED)
  set(LIBRARY_TYPE SHARED)
else()
  set(LIBRARY_TYPE STATIC)
endif()

add_library(
  ${PROJECT_NAME} ${LIBRARY_TYPE}
  penguin/penguin_linux.c
  penguin/penguin_windows.c
  penguin/penguin.c
)

add_library(
  ${PROJECT_NAME}::${PROJECT_NAME} ALIAS
  ${PROJECT_NAME}
)

target_include_directories(
  ${PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(
  ${PROJECT_NAME} PRIVATE
  shlwapi
)

set_target_properties(
  ${PROJECT_NAME} PROPERTIES
  PUBLIC_HEADER "penguin.h"
)

install(
  TARGETS ${PROJECT_NAME}
)
