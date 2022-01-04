#include "pieces/PieceUtils.h"

/**
 * Helper function to check a coordinate and determine if the path is blocked.
 */
bool
checkCoord(std::vector<std::pair<int, int>> &PossibleMoves, int Column, int Row, bool Color,
            const std::map<std::pair<int, int>, Piece> &BoardState, Piece CurrentPiece)
{
    std::pair<int, int> PotentialCoord(Column, Row);
    bool kingInCheck;
    /* First, check if this move either puts the king in check or leaves the king in check. */
    std::map<std::pair<int, int>, Piece> TestBoardState(BoardState);
    Board TestBoard = Board(TestBoardState);  // Create  a test board that we will abuse to check for threats to the king.
    std::pair<int, int> OldCoord(CurrentPiece.getColumn(), CurrentPiece.getRow());
    CurrentPiece.setColumn(Column);
    CurrentPiece.setRow(Row);
    // TestBoard.BoardState[PotentialCoord] = CurrentPiece;
    // TestBoard.BoardState[OldCoord] = Piece();
    kingInCheck = TestBoard.checkKingInCheck(Color);
    TestBoard.printBoard();
    if (kingInCheck)
    {
        std::cout << "found king in check\n";
    }

    /* Then, check if there is another piece in the way. */
    Piece PotentialBoardSpot = BoardState.at(PotentialCoord);
    if (PotentialBoardSpot.PieceLabel == PieceType::Empty)
    {
        if (!kingInCheck)
        {
            PossibleMoves.push_back(PotentialCoord);
        }
        return true;
    }
    else if (PotentialBoardSpot.getColor() == Color)
    {
        return false;
    }
    else
    {
        if (!kingInCheck)
        {
            PossibleMoves.push_back(PotentialCoord);
        }
        return false;
    }
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
        OneForward = std::pair<int, int>(InitialColumn, InitialRow - 1);
        TwoForward = std::pair<int, int>(InitialColumn, InitialRow - 2);
        DiagonalRight.second = InitialRow - 1;
        DiagonalLeft.second = InitialRow - 1;
    }
    else
    {
        OneForward = std::pair<int, int>(InitialColumn, InitialRow + 1);
        TwoForward = std::pair<int, int>(InitialColumn, InitialRow + 2);
        DiagonalRight.second = InitialRow + 1;
        DiagonalLeft.second = InitialRow + 1;
    }

    /* Check for a blocked path */
    auto PieceOneForward = BoardState.find(OneForward);
    if (PieceOneForward != BoardState.end() &&
        PieceOneForward->second.PieceLabel == PieceType::Empty)
    {
        PathBlocked = true;
        ValidPossibleMoves.push_back(OneForward);
    }
    else
    {
        PathBlocked = true;
    }

    /* Next, check diagonal moves */
    auto PieceDiagonalLeft = BoardState.find(DiagonalLeft);
    auto PieceDiagonalRight = BoardState.find(DiagonalRight);
    if (PieceDiagonalLeft != BoardState.end() &&
        PieceDiagonalLeft->second.getColor() != Color && 
        PieceDiagonalLeft->second.PieceLabel != PieceType::Empty)
    {
        ValidPossibleMoves.push_back(DiagonalLeft);
    }    
    if (PieceDiagonalRight != BoardState.end() &&
        PieceDiagonalRight->second.getColor() != Color && 
        PieceDiagonalRight->second.PieceLabel != PieceType::Empty)
    {
        ValidPossibleMoves.push_back(DiagonalRight);
    }

    /* Finally, if there is no piece in the way and we are at the starting position,
    try moving two forward */
    if (!PathBlocked && 
        ((Color && InitialRow == MaxLength - 2) || (!Color && InitialRow == 1)) &&
        BoardState.at(TwoForward).PieceLabel == PieceType::Empty)
    {
        ValidPossibleMoves.push_back(TwoForward);
    }

    return ValidPossibleMoves;
}

std::vector<std::pair<int, int>>
possibleRookMoves(Piece Rook, const std::map<std::pair<int, int>, Piece> &BoardState, int MaxWidth, int MaxLength)
{
    std::vector<std::pair<int, int>> PossibleMoves;
    int InitialRow = Rook.getRow();
    int InitialColumn = Rook.getColumn();
    bool Color = Rook.getColor();

    for (int i = InitialRow + 1; i < MaxLength; i++)
    {
        if (!checkCoord(PossibleMoves, InitialColumn, i, Color, BoardState, Rook))
        {
            break;
        }
    }
    for (int i = InitialRow - 1; i >= 0; i--)
    {
        if (!checkCoord(PossibleMoves, InitialColumn, i, Color, BoardState, Rook))
        {
            break;
        }
    }
    for (int i = InitialColumn + 1; i < MaxWidth; i++)
    {
        if (!checkCoord(PossibleMoves, i, InitialRow, Color, BoardState, Rook))
        {
            break;
        }
    }
    for (int i = InitialColumn - 1; i >= 0; i--)
    {
        if (!checkCoord(PossibleMoves, i, InitialRow, Color, BoardState, Rook))
        {
            break;
        }
    }
    
    return PossibleMoves;
}

std::vector<std::pair<int, int>>
possibleBishopMoves(Piece Bishop, const std::map<std::pair<int, int>, Piece> &BoardState, int MaxWidth, int MaxLength)
{
    std::vector<std::pair<int, int>> PossibleMoves;
    int InitialRow = Bishop.getRow();
    int InitialColumn = Bishop.getColumn();
    bool Color = Bishop.getColor();
    
    int i = InitialRow + 1;
    int j = InitialColumn + 1;
    while (i < MaxWidth && j < MaxLength)
    {
        if (!checkCoord(PossibleMoves, j, i, Color, BoardState, Bishop))
        {
            break;
        }
        i++;
        j++;
    }
    
    i = InitialRow + 1;
    j = InitialColumn - 1;
    while (i < MaxWidth && j >= 0)
    {
        if (!checkCoord(PossibleMoves, j, i, Color, BoardState, Bishop))
        {
            break;
        }
        i++;
        j--;
    }

    i = InitialRow - 1;
    j = InitialColumn + 1;
    while (i >= 0 && j < MaxLength)
    {
        if (!checkCoord(PossibleMoves, j, i, Color, BoardState, Bishop))
        {
            break;
        }
        i--;
        j++;
    }

    i = InitialRow - 1;
    j = InitialColumn - 1;
    while (i >= 0 && j >= 0)
    {
        if (!checkCoord(PossibleMoves, j, i, Color, BoardState, Bishop))
        {
            break;
        }
        i--;
        j--;
    }
    
    return PossibleMoves;
}

std::vector<std::pair<int, int>>
possibleQueenMoves(Piece Queen, const std::map<std::pair<int, int>, Piece> &BoardState, int MaxWidth, int MaxLength)
{
    std::vector<std::pair<int, int>> PossibleMovesRook = possibleRookMoves(Queen, BoardState, MaxWidth, MaxLength);
    std::vector<std::pair<int, int>> PossibleMovesBishop = possibleBishopMoves(Queen, BoardState, MaxWidth, MaxLength);
    PossibleMovesRook.insert(PossibleMovesRook.end(), PossibleMovesBishop.begin(), PossibleMovesBishop.end());
    return PossibleMovesRook;
}

std::vector<std::pair<int, int>>
possibleKnightMoves(Piece Knight, const std::map<std::pair<int, int>, Piece> &BoardState, int MaxWidth, int MaxLength)
{
    std::vector<std::pair<int, int>> PossibleMoves;
    int InitialRow = Knight.getRow();
    int InitialColumn = Knight.getColumn();
    bool Color = Knight.getColor();
    std::pair<int, int> PossibleCoord;
    int i;
    int j; 

    /* No choice but to brute force it. We don't care about the return value
    because we can jump pieces with the knight. */
    i = InitialRow + 2;
    j = InitialColumn + 1;
    PossibleCoord = std::pair<int, int>(j, i);
    if (BoardState.count(PossibleCoord) > 0)
    {
        checkCoord(PossibleMoves, j, i, Color, BoardState, Knight);
    }
    i = InitialRow + 2;
    j = InitialColumn - 1;
    PossibleCoord = std::pair<int, int>(j, i);
    if (BoardState.count(PossibleCoord) > 0)
    {
        checkCoord(PossibleMoves, j, i, Color, BoardState, Knight);
    }
    i = InitialRow - 2;
    j = InitialColumn + 1;
    PossibleCoord = std::pair<int, int>(j, i);
    if (BoardState.count(PossibleCoord) > 0)
    {
        checkCoord(PossibleMoves, j, i, Color, BoardState, Knight);
    }
    i = InitialRow - 2;
    j = InitialColumn - 1;
    PossibleCoord = std::pair<int, int>(j, i);
    if (BoardState.count(PossibleCoord) > 0)
    {
        checkCoord(PossibleMoves, j, i, Color, BoardState, Knight);
    }
    i = InitialRow + 1;
    j = InitialColumn + 2;
    PossibleCoord = std::pair<int, int>(j, i);
    if (BoardState.count(PossibleCoord) > 0)
    {
        checkCoord(PossibleMoves, j, i, Color, BoardState, Knight);
    }
    i = InitialRow + 1;
    j = InitialColumn - 2;
    PossibleCoord = std::pair<int, int>(j, i);
    if (BoardState.count(PossibleCoord) > 0)
    {
        checkCoord(PossibleMoves, j, i, Color, BoardState, Knight);
    }
    i = InitialRow - 1;
    j = InitialColumn + 2;
    PossibleCoord = std::pair<int, int>(j, i);
    if (BoardState.count(PossibleCoord) > 0)
    {
        checkCoord(PossibleMoves, j, i, Color, BoardState, Knight);
    }
    i = InitialRow - 1;
    j = InitialColumn - 2;
    PossibleCoord = std::pair<int, int>(j, i);
    if (BoardState.count(PossibleCoord) > 0)
    {
        checkCoord(PossibleMoves, j, i, Color, BoardState, Knight);
    }

    return PossibleMoves;
}

std::vector<std::pair<int, int>>
possibleKingMoves(Piece King, const std::map<std::pair<int, int>, Piece> &BoardState, int MaxWidth, int MaxLength)
{
    std::vector<std::pair<int, int>> PossibleMoves;
    int InitialRow = King.getRow();
    int InitialColumn = King.getColumn();
    bool Color = King.getColor();

    for (int i = InitialRow - 1; i < InitialRow + 2; i++)
    {
        for (int j = InitialColumn - 1; j < InitialColumn + 2; j++)
        {
            if (i >= MaxLength || i < 0 || j >= MaxWidth || j < 0)
            {
                continue;
            }
            checkCoord(PossibleMoves, j, i, Color, BoardState, King);
        }
    }
    return PossibleMoves;
}
