#include <cstdlib>

#include "Utils.h"


std::vector<Piece>
getPieces(std::set<Piece> Pieces, Piece &King)
{
    std::vector<Piece> FinalPieces;
    for (auto Iterator = Pieces.begin(); Iterator != Pieces.end(); Iterator++)
    {
        FinalPieces.push_back(*Iterator);
        if (Iterator->PieceLabel == PieceType::King)
        {
            King = *Iterator;
        }
    }
    return FinalPieces;
}

int
getRandBelow(int Max)
{
    int RandValue = std::rand();
    return RandValue % Max;
}
