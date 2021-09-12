#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <set>

#include "pieces/Piece.h"


class Board 
{
    public:

    Board(){};

    bool
    createBoard(int Width, int Length);

    bool
    createPiece(int X, int Y, PieceType Type, bool Color);

    void
    printBoard();

    std::map<std::pair<int, int>, Piece> BoardState;
    std::set<Piece> WhitePieces;
    std::set<Piece> BlackPieces;
    int Width;
    int Length;
};

#endif /* BOARD_H */
