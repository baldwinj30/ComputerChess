#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <vector>
#include <map>

enum PieceType
{
    Empty,
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King
};


/**
 * Represents either a chess piece or an empty spot on the board.
 */
class Piece
{
    public:

    Piece() {}

    Piece(int StartColumn, int StartRow, PieceType Label, bool Team)
    {
        Column = StartColumn;
        Row = StartRow;
        PieceLabel = Label;
        Color = Team;
    }

    int
    getRow() const { return Row; }

    int
    getColumn() const { return Column; }

    void
    setRow(int Row) { this->Row = Row; }

    void
    setColumn(int Column) { this->Column = Column; }

    bool
    getColor() const { return Color; }

    /**
     * Find all the possible moves for the piece at a given board state.
     * 
     * Return the moves as a vector of pairs of final <column, row>.
     */
    std::vector<std::pair<int, int>>
    getPossibleMoves (const std::map<std::pair<int, int>, Piece> &BoardState,
                        int MaxWidth, int MaxLength) const;

    /**
     * Find all the current threats to a piece; primarily to be used for determining
     * check and checkmate on the king.
     */
    // bool
    // checkThreats();

    friend
    std::ostream& operator<<(std::ostream & OutputStream, const Piece &PrintPiece);

    bool operator<(const Piece &RHS) const;

    bool operator==(const Piece &RHS) const;

    /**
     * Return the PGN code for this piece.
     */
    std::string
    getPGNCode();

    PieceType PieceLabel {PieceType::Empty};

    private:
    int Row;
    int Column;
    bool Color;
};

#endif /* PIECE_H */
