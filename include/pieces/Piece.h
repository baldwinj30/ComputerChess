#ifndef PIECE_H
#define PIECE_H

#include <iostream>

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

    bool
    movePiece() {};

    friend
    std::ostream& operator<<(std::ostream & OutputStream, const Piece &PrintPiece);

    bool operator<(const Piece &RHS) const;

    bool operator==(const Piece &RHS) const;

    PieceType PieceLabel {PieceType::Empty};

    private:
    int Row;
    int Column;
    bool Color;
};

#endif /* PIECE_H */
