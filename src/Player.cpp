#include "Player.h"
#include "Utils.h"

#include <cstdlib>
#include <algorithm>

bool
Player::makeRandomMove()
{
    std::vector<Piece> ColorPieces;
    std::set<Piece> OpposingPieces;
    std::vector<std::pair<int, int>> PossibleMoves;
    std::pair<int, int> TheMove;
    Piece King;
    Piece MovePiece;
    int Idx;
    unsigned TotalPieces;
    
    if (Color)
    {
        ColorPieces = getPieces(BoardReference.WhitePieces, King);
        OpposingPieces = BoardReference.BlackPieces;
    }
    else
    {
        ColorPieces = getPieces(BoardReference.BlackPieces, King);
        OpposingPieces = BoardReference.WhitePieces;
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
        PossibleMoves = MovePiece.getPossibleMoves(BoardReference.BoardState, 
                BoardReference.Width, BoardReference.Length);
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
    Piece OpposingPiece = BoardReference.BoardState.at(TheMove);
    if (OpposingPiece.PieceLabel != PieceType::Empty)
    {
        if (Color)
        {
            BoardReference.BlackPieces.erase(OpposingPiece);
        }
        else
        {
            BoardReference.WhitePieces.erase(OpposingPiece);
        }
    }
    /* Last color check and update */
    if (Color)
    {
        BoardReference.WhitePieces.erase(MovePiece);
    }
    else
    {
        BoardReference.BlackPieces.erase(MovePiece);
    }
    /* Remove the old position from the board */
    BoardReference.BoardState[
        std::pair<int, int>(MovePiece.getColumn(), MovePiece.getRow())] = Piece();
    MovePiece.setColumn(TheMove.first);
    MovePiece.setRow(TheMove.second);
    /* Now this is really our last color check and update */
    if (Color)
    {
        BoardReference.WhitePieces.insert(MovePiece);
    }
    else
    {
        BoardReference.BlackPieces.insert(MovePiece);
    }
    BoardReference.BoardState[TheMove] = MovePiece;
    std::cout << "move: " << MovePiece <<  " to (" << MovePiece.getColumn() << "," << 
        MovePiece.getRow() << ")" << std::endl;

    return true;
}