cmake_minimum_required(VERSION 3.10)
project(brainfuck_translator)

set(CMAKE_CXX_STANDARD 17)

add_executable(brainfuck_translator
    src/main.cpp
    src/translator.cpp
)
