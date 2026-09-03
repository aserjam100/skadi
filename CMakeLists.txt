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

add_executable(
    skadi
    src/main.cpp
    src/vector_math.cpp
)

target_include_directories(
    skadi
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_compile_options(
    skadi
    PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)
