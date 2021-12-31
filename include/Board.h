#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <set>
#include <sstream>

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

    void
    newTurn(int TurnNumber) { PGNGameRecord << TurnNumber << ". "; }

    void
    recordPiece(std::string PieceCode) { PGNGameRecord << PieceCode << " "; }

    void
    recordCapture() { PGNGameRecord << "x"; }

    void
    printPGN() { std::cout << PGNGameRecord.str() << "\n"; }

    std::map<std::pair<int, int>, Piece> BoardState;
    std::set<Piece> WhitePieces;
    std::set<Piece> BlackPieces;
    int Width;
    int Length;

    private:
    std::ostringstream PGNGameRecord;
};

#endif /* BOARD_H */
