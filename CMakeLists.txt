cmake_minimum_required(VERSION 3.20)

project(
    skadi
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(
    skadi_core
    src/vector_math.cpp
    src/vector_index.cpp
)

target_include_directories(
    skadi_core
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_compile_options(
    skadi_core
    PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

add_executable(
    skadi
    src/main.cpp
)

target_link_libraries(
    skadi
    PRIVATE
    skadi_core
)

add_executable(
    vector_math_test
    tests/vector_math_test.cpp
)

target_link_libraries(
    vector_math_test
    PRIVATE
    skadi_core
)

add_executable(
  vector_index_test
  tests/vector_index_test.cpp
)

target_link_libraries(
  vector_index_test
  PRIVATE
  skadi_core
)

