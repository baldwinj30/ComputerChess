#include "pieces/Piece.h"

#include <string>

std::ostream &
operator<<(std::ostream & OutputStream, const Piece &PrintPiece)
{
    std::string OutputString;
    if (PrintPiece.Color)
    {
        OutputString += "W";
    }
    else
    {
        OutputString += "B";
    }
    switch(PrintPiece.PieceLabel)
    {
        case PieceType::Pawn: OutputString += "p";
            break;
        case PieceType::Rook: OutputString += "r";
            break;
        case PieceType::Knight: OutputString += "n";
            break;
        case PieceType::Bishop: OutputString += "b";
            break;
        case PieceType::Queen: OutputString += "q";
            break;
        case PieceType::King: OutputString += "k";
            break;
        case PieceType::Empty: OutputString = "00";
            break;
        default: OutputString = "PRINT ERROR\n";
            break;
    }
    return OutputStream << OutputString;
}