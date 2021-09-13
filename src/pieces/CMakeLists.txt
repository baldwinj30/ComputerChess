add_library(pieces
    Piece.cpp
    PieceUtils.cpp)

target_include_directories(pieces PUBLIC
    ${CMAKE_SOURCE_DIR}/include)