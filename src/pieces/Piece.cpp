#include "pieces/Piece.h"
#include "pieces/PieceUtils.h"
#include "Board.h"

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
                    int MaxWidth, int MaxLength, bool TestForCheck) const
{
    std::vector<std::pair<int, int>> PossibleMoves;
    switch (PieceLabel)
    {
        case PieceType::Pawn: PossibleMoves = possiblePawnMoves(*this, BoardState, MaxWidth, MaxLength, TestForCheck);
            break;
        case PieceType::Rook: PossibleMoves = possibleRookMoves(*this, BoardState, MaxWidth, MaxLength, TestForCheck);
            break;
        case PieceType::Bishop: PossibleMoves = possibleBishopMoves(*this, BoardState, MaxWidth, MaxLength, TestForCheck);
            break;
        case PieceType::Queen: PossibleMoves = possibleQueenMoves(*this, BoardState, MaxWidth, MaxLength, TestForCheck);
            break;
        case PieceType::Knight: PossibleMoves = possibleKnightMoves(*this, BoardState, MaxWidth, MaxLength, TestForCheck);
            break;
        case PieceType::King: PossibleMoves = possibleKingMoves(*this, BoardState, MaxWidth, MaxLength, TestForCheck);
            break;
        default:
            break;
    }
    return PossibleMoves;
}

bool 
Piece::operator<(const Piece &RHS) const
{
    /* White is arbitrarily greater than Black */
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

/**
 * Map the piece labels to Portable Game Notation (PGN) strings
 */
std::map<PieceType, std::string> PGNMap = 
{
    {PieceType::Pawn, ""}, 
    {PieceType::Knight, "N"}, 
    {PieceType::Bishop, "B"}, 
    {PieceType::Rook, "R"}, 
    {PieceType::Queen, "Q"}, 
    {PieceType::King, "K"}
};

std::string
Piece::getPGNCode()
{
    return PGNMap[this->PieceLabel];
}
