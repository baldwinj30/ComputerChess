#include "Player.h"
#include "Utils.h"

#include <cstdlib>
#include <algorithm>

bool
Player::makeRandomMove()
{
    std::vector<Piece> ColorPieces;
    std::vector<Piece> MovePieces;
    std::set<Piece> OpposingPieces;
    std::vector<std::pair<int, int>> PossibleMoves;
    std::pair<int, int> TheMove;
    Piece King;
    Piece MovePiece;
    int Idx;
    unsigned TotalPieces;
    bool Capture = false;
    
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
    /* Loop through until we have all possible moves. */
    for (int i = 0; i < TotalPieces; i++)
    {
        MovePiece = ColorPieces[i];
        std::vector<std::pair<int, int>> NewMoves = MovePiece.getPossibleMoves(BoardReference.BoardState, 
                BoardReference.Width, BoardReference.Length);
        PossibleMoves.insert(PossibleMoves.end(), NewMoves.begin(), NewMoves.end());
        /* Match this vector with the previous one so that we know which piece is moved. */
        MovePieces.insert(MovePieces.end(), NewMoves.size(), MovePiece);
    }

    /* If there are no possible moves, then we have a stalemate. */
    if (PossibleMoves.empty())
    {
        return false;
    }
    /* Otherwise, pick a move and execute it */
    Idx = getRandBelow(PossibleMoves.size());
    TheMove = PossibleMoves[Idx];
    MovePiece = MovePieces[Idx];
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
        Capture = true;
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
    
    /* Perform PGN bookkeeping */
    BoardReference.recordPiece(MovePiece);
    if (Capture)
    {
        BoardReference.recordCapture(MovePiece);
    }
    BoardReference.recordMove(TheMove);

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
    
    /* Determine if the opposing king is now in check */
    if (BoardReference.checkKingInCheck(Color))
    {
        std::cout << "The king is in check...";
        return false;
    }

    return true;
}