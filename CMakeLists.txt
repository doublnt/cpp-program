cmake_minimum_required(VERSION 3.21)
project(cpp_program)

set(CMAKE_CXX_STANDARD 14)

add_library(cpp_program src/library.cpp main.cpp)
add_executable(cpp_program_exec src/library.cpp main.cpp)