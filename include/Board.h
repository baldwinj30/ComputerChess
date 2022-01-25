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
        this->BoardState = BoardState; 
        Width = 8;
        Length = 8;
    }

    /**
     * Build a chess board with all pieces at their initial positions.
     * This initializes the BoardState public variable with all the pieces,
     * and returns true on success.
     */
    bool
    createBoard(int Width, int Length);

    /** 
     * Adds a piece to the BoardState at the given position.
     */
    bool
    createPiece(int X, int Y, PieceType Type, bool Color);

    void
    printBoard();

    /**
     * Check if the king of the given color is in check.
     */
    bool
    checkKingInCheck(bool Color);

    /**
     * Create a new turn in the PGN record.
     */
    void
    newTurn(int TurnNumber) { PGNGameRecord << TurnNumber << ". "; }

    /**
     * Record a piece that made a move in the PGN record.
     */
    void
    recordPiece(Piece RecordPiece) { PGNGameRecord << RecordPiece.getPGNCode(); }

    /**
     * Record the new position of a piece in the PGN record.
     */
    void
    recordMove(std::pair<int, int> Space) { PGNGameRecord << FileMap[Space.first] << RankMap[Space.second] << ' '; };

    /**
     * Note a capture in the PGN record; this requires special notation for pawns vs. other pieces.
     */
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
