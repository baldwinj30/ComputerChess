#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <set>
#include <sstream>

#include "pieces/Piece.h"


/**
 * Creates the initial board state, records the game moves, and looks for
 * check and check-mate.
 */
class Board 
{
    public:

    Board(){};

    Board(std::map<std::pair<int, int>, Piece> BoardState) 
    { 
        BoardState = BoardState; 
        Width = 8;
        Length = 8;
    }

    bool
    createBoard(int Width, int Length);

    bool
    createPiece(int X, int Y, PieceType Type, bool Color);

    void
    printBoard();

    /**
     * Check if a king is in check.
     */
    bool
    checkKingInCheck(bool Color);

    void
    newTurn(int TurnNumber) { PGNGameRecord << TurnNumber << ". "; }

    void
    recordPiece(Piece RecordPiece) { PGNGameRecord << RecordPiece.getPGNCode(); }

    void
    recordMove(std::pair<int, int> Space) { PGNGameRecord << FileMap[Space.first] << RankMap[Space.second] << ' '; };

    void
    recordCapture(Piece PieceCapturing);

    void
    printPGN() { std::cout << PGNGameRecord.str() << "\n"; }

    std::map<std::pair<int, int>, Piece> BoardState;
    std::set<Piece> WhitePieces;
    std::set<Piece> BlackPieces;
    int Width;
    int Length;

    private:
    std::ostringstream PGNGameRecord;
    /* Maps rank indices to PGN ranks */
    std::map<int, int> RankMap = {{0, 8}, {1, 7}, {2, 6}, {3, 5}, {4, 4}, {5, 3}, {6, 2}, {7, 1}};
    /* Maps file indices to PGN files */
    std::map<int, char> FileMap = {{0, 'a'}, {1, 'b'}, {2, 'c'}, {3, 'd'}, {4, 'e'}, {5, 'f'}, {6, 'g'}, {7, 'h'}};
};

#endif /* BOARD_H */
