#include "pieces/Piece.h"
#include "pieces/PieceUtils.h"

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
        case PieceType::Empty: OutputString = "--";
            break;
        default: OutputString = "PRINT ERROR\n";
            break;
    }
    return OutputStream << OutputString;
}

std::vector<std::pair<int, int>>
Piece::getPossibleMoves (const std::map<std::pair<int, int>, Piece> &BoardState,
                    int MaxWidth, int MaxLength)
{
    std::vector<std::pair<int, int>> PossibleMoves;
    switch (PieceLabel)
    {
        case PieceType::Pawn: PossibleMoves = possiblePawnMoves(*this, BoardState, MaxWidth, MaxLength);
            break;
        default:
            break;
    }
    return PossibleMoves;
}

bool 
Piece::operator<(const Piece &RHS) const
{
    /* White is greater than Black */
    if (Color < RHS.Color)
    {
        return true;
    }
    else if (Color > RHS.Color)
    {
        return false;
    }

    if (PieceLabel < RHS.PieceLabel)
    {
        return true;
    }
    else if (PieceLabel > RHS.PieceLabel)
    {
        return false;
    }

    if (Row < RHS.Row)
    {
        return true;
    }
    else if (Row > RHS.Row)
    {
        return false;
    }

    if (Column < RHS.Column)
    {
        return true;
    }
    else if (Column > RHS.Column)
    {
        return false;
    }

    return false;
}

bool
Piece::operator==(const Piece &RHS) const
{
    if (this->Color == RHS.Color && this->Row == RHS.Row 
        && this->Column == RHS.Column && this->PieceLabel == RHS.PieceLabel)
    {
        return true;
    }
    
    return false;
}
