#include "pieces/PieceUtils.h"

/**
 * Helper function to ensure that possible moves are within the board.
 * This should always be the last step of running possible moves.
 */
std::vector<std::pair<int, int>>
boardVerification(std::vector<std::pair<int, int>> CandidateMoves, int MaxWidth, int MaxLength)
{
    std::vector<std::pair<int, int>> ValidatedMoves;
    for (unsigned i = 0; i < CandidateMoves.size(); i++)
    {
        int Column = CandidateMoves[i].first;
        int Row = CandidateMoves[i].second;
        if (Row >= MaxLength || Row < 0)
        {
            continue;
        }
        else if (Column >= MaxWidth || Column < 0)
        {
            continue;
        }
        else
        {
            ValidatedMoves.push_back(CandidateMoves[i]);
        }
    }
    return ValidatedMoves;
}


std::vector<std::pair<int, int>>
possiblePawnMoves(Piece Pawn, const std::map<std::pair<int, int>, Piece> &BoardState, int MaxWidth, int MaxLength)
{
    std::vector<std::pair<int, int>> ValidPossibleMoves;
    std::pair<int, int> OneForward;
    std::pair<int, int> TwoForward;
    int InitialRow = Pawn.getRow();
    int InitialColumn = Pawn.getColumn();
    std::pair<int, int> DiagonalRight(InitialColumn + 1, InitialRow);
    std::pair<int, int> DiagonalLeft(InitialColumn - 1, InitialRow);
    bool Color = Pawn.getColor();
    bool PathBlocked;

    /* Set our directional moves based on color */
    if (Pawn.getColor())
    {
        OneForward = std::pair<int, int>(InitialColumn, InitialRow + 1);
        TwoForward = std::pair<int, int>(InitialColumn, InitialRow + 2);
    }
    else
    {
        OneForward = std::pair<int, int>(InitialColumn, InitialRow - 1);
        TwoForward = std::pair<int, int>(InitialColumn, InitialRow - 2);
    }

    /* Check for a blocked path */
    if (BoardState.at(OneForward).PieceLabel != PieceType::Empty)
    {
        PathBlocked = true;
    }
    else
    {
        PathBlocked = false;
        ValidPossibleMoves.push_back(OneForward);
    }

    /* Next, check diagonal moves */
    Piece PieceDiagonalLeft = BoardState.at(DiagonalLeft);
    Piece PieceDiagonalRight = BoardState.at(DiagonalRight);
    if (PieceDiagonalLeft.getColor() != Color && 
        PieceDiagonalLeft.PieceLabel != PieceType::Empty)
    {
        ValidPossibleMoves.push_back(DiagonalLeft);
    }    
    if (PieceDiagonalRight.getColor() != Color && 
        PieceDiagonalRight.PieceLabel != PieceType::Empty)
    {
        ValidPossibleMoves.push_back(DiagonalRight);
    }

    /* Finally, if there is no piece in the way and we are at the home row,
    try moving two forward */
    if (!PathBlocked && 
        ((Color && InitialRow == 1) || (!Color && InitialRow == MaxLength - 2)) &&
        BoardState.at(TwoForward).PieceLabel == PieceType::Empty)
    {
        ValidPossibleMoves.push_back(TwoForward);
    }

    return boardVerification(ValidPossibleMoves, MaxWidth, MaxLength);
}
