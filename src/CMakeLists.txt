add_subdirectory(pieces)

# add the executable
add_executable(ComputerChess 
    Board.cpp
    Player.cpp
    Utils.cpp
    main.cpp)

target_link_libraries(ComputerChess pieces)
target_include_directories(ComputerChess PUBLIC
    ${CMAKE_SOURCE_DIR}/include)