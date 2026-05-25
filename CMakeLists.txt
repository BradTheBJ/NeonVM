cmake_minimum_required(VERSION 4.1)

project(NeonVM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Explicitly list source files for reliable compilation and IDE detection
# This is only temporary
set(SRC_FILES
        src/main.cpp
        src/lexer.cpp
        src/parser.cpp
        src/VM.cpp
)

add_executable(NeonVM ${SRC_FILES})
target_include_directories(NeonVM PRIVATE
        "${CMAKE_SOURCE_DIR}/include"
)