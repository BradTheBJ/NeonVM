cmake_minimum_required(VERSION 4.1)

project(NeonVM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Recursively grab all source/header files
file(GLOB_RECURSE SRC_FILES
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_SOURCE_DIR}/include/*.hpp"
)

add_executable(NeonVM ${SRC_FILES})
target_include_directories(NeonVM PRIVATE
        "${CMAKE_SOURCE_DIR}/include"
)