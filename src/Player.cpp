#include "Player.h"
#include "Utils.h"

#include <cstdlib>


/* Helper function to quickly transfer the pieces from a set
to a vector and to find the King */
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

bool
Player::makeRandomMove()
{
    std::vector<Piece> ColorPieces;
    Piece King;
    int Idx;
    bool CanMove = false;
    
    if (Color)
    {
        ColorPieces = getPieces(BoardInstance->WhitePieces, King);
    }
    else
    {
        ColorPieces = getPieces(BoardInstance->BlackPieces, King);
    }

    while (!CanMove)
    {
        Idx = getRandBelow(ColorPieces.size());
    }
}