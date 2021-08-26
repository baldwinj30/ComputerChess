#ifndef PIECE_H
#define PIECE_H

#include <iostream>

enum PieceType
{
    Pawn,
    Rook,
    Knight,
    Bishop,
    King,
    Queen,
    Empty
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

    int Row;
    int Column;
    bool Color;
    PieceType PieceLabel {PieceType::Empty};
};

#endif /* PIECE_H */
