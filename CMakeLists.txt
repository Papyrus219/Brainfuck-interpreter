cmake_minimum_required(VERSION 3.31)
project(brainfuck)

file(GLOB_RECURSE SRC src/*cpp)
set(SOURCES ${SRC})
add_executable(brainfuck ${SOURCES})
set_target_properties(brainfuck PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/.."
)
