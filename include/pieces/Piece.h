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

    std::vector<std::pair<int, int>>
    getPossibleMoves (const std::map<std::pair<int, int>, Piece> &BoardState,
                        int MaxWidth, int MaxLength);

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
