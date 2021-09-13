cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)

# set the project name
project(ComputerChess)

add_subdirectory(src)

target_include_directories(ComputerChess PUBLIC
    include
    "{PROJECT_BINARY_DIR}")
