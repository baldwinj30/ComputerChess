#include "Player.h"
#include "Utils.h"

#include <cstdlib>
#include <algorithm>

bool
Player::makeRandomMove()
{
    std::vector<Piece> ColorPieces;
    std::vector<std::pair<int, int>> PossibleMoves;
    std::pair<int, int> TheMove;
    Piece King;
    Piece MovePiece;
    int Idx;
    unsigned TotalPieces;
    
    if (Color)
    {
        ColorPieces = getPieces(BoardInstance->WhitePieces, King);
    }
    else
    {
        ColorPieces = getPieces(BoardInstance->BlackPieces, King);
    }
    std::random_shuffle(ColorPieces.begin(), ColorPieces.end());

    TotalPieces = ColorPieces.size();
    Idx = getRandBelow(TotalPieces);
    /* Loop through until we find a move or we have tried all
    possible moves. We may try some moves twice, but for
    this simple application that should be fine. */
    while (PossibleMoves.empty() && Idx < 2*TotalPieces)
    {
        MovePiece = ColorPieces[Idx % TotalPieces];
        PossibleMoves = MovePiece.getPossibleMoves(BoardInstance->BoardState, 
                BoardInstance->Width, BoardInstance->Length);
        Idx++;
    }

    /* If there are no possible moves, then we have a stalemate. */
    if (PossibleMoves.empty())
    {
        return false;
    }
    /* Otherwise, pick a move and execute it */
    Idx = getRandBelow(PossibleMoves.size());
    TheMove = PossibleMoves[Idx];
    /* Take the opposing piece if applicable. We already checked not to run into our own piece. */
    Piece OpposingPiece = BoardInstance->BoardState.at(TheMove);
    if (OpposingPiece.PieceLabel != PieceType::Empty)
    {
        if (Color)
        {
            BoardInstance->BlackPieces.erase(OpposingPiece);
        }
        else
        {
            BoardInstance->WhitePieces.erase(OpposingPiece);
        }
    }
    /* Last color check and update */
    if (Color)
    {
        BoardInstance->WhitePieces.erase(MovePiece);
    }
    else
    {
        BoardInstance->BlackPieces.erase(MovePiece);
    }
    MovePiece.setColumn(TheMove.first);
    MovePiece.setRow(TheMove.second);
    /* Now this is really our last color check and update */
    if (Color)
    {
        BoardInstance->WhitePieces.insert(MovePiece);
    }
    else
    {
        BoardInstance->BlackPieces.insert(MovePiece);
    }
    BoardInstance->BoardState[TheMove] = MovePiece;

    return true;
}