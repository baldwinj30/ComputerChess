cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_STANDARD 11)

# set the project name
project(ComputerChess)

add_subdirectory(src)
add_subdirectory(test)

target_include_directories(ComputerChess PUBLIC
    "{PROJECT_BINARY_DIR}")
