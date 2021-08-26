enum PieceType
{
    WhitePawn,
    WhiteRook,
    WhiteKnight,
    WhiteBishop,
    WhiteKing,
    WhiteQueen,
    BlackPawn,
    BlackRook,
    BlackKnight,
    BlackBishop,
    BlackKing,
    BlackQueen
};

class Piece
{
    public:

    virtual bool
    movePiece() {};

    private:

    int Row;
    int Column;
    bool Color;
    PieceType PieceLabel;
};
