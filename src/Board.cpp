#include "Board.h"

#include <iostream>

bool
Board::checkKingInCheck(bool Color)
{
    std::vector<std::pair<int, int>> ThreatMoves;
    Piece King;
    for (auto CurrentPiece : BoardState)
    {
        /* If the space is empty, then continue on. */
        if (CurrentPiece.second.PieceLabel == PieceType::Empty)
        {
            continue;
        }
        /* Gather the potentially threatening moves. */
        else if (CurrentPiece.second.getColor() != Color)
        {
            std::vector<std::pair<int, int>> CurrentPossibleThreats = 
                CurrentPiece.second.getPossibleMoves(this->BoardState, this->Width, this->Length, false);
            ThreatMoves.insert(ThreatMoves.end(), CurrentPossibleThreats.begin(), CurrentPossibleThreats.end());
        }
        /* Find the king. */
        else if (CurrentPiece.second.PieceLabel == PieceType::King)
        {
            King = CurrentPiece.second;
        }
    }
    /* Now check if any threatening moves could get the king. */
    for (auto Move : ThreatMoves)
    {
        if (King.getColumn() == Move.first && King.getRow() == Move.second)
        {
            return true;
        }
    }
    return false;
}

bool
Board::createBoard(int Width, int Length)
{
    /* Define the initial columns for each piece. */
    int RookColumn1 = 0;
    int RookColumn2 = Width - 1;
    int KnightColumn1 = 1;
    int KnightColumn2 = Width - 2;
    int BishopColumn1 = 2;
    int BishopColumn2 = Width - 3;
    int QueenColumn = 3;
    int KingColumn = Width - 4;

    if (Width < 8 || Length < 8 || Width != Length)
    {
        return false;
    }
    this->Width = Width;
    this->Length = Length;

    /* Create the starting positions of the pieces; or an empty board space */
    for (unsigned i = 0; i < Length; ++i)
    {
        for (unsigned j = 0; j < Width; ++j)
        {
            if (i == 0 || i == Length - 1)
            {
                bool Color = i == Length - 1;
                if (j == RookColumn1 || j == RookColumn2)
                {
                    createPiece(j, i, PieceType::Rook, Color);
                }
                else if (j == KnightColumn1 || j == KnightColumn2)
                {
                    createPiece(j, i, PieceType::Knight, Color);
                }
                else if (j == BishopColumn1 || j == BishopColumn2)
                {
                    createPiece(j, i, PieceType::Bishop, Color);
                }
                else if (j == QueenColumn)
                {
                    createPiece(j, i, PieceType::Queen, Color);
                }
                else if (j == KingColumn)
                {
                    createPiece(j, i, PieceType::King, Color);
                }
                else
                {
                    BoardState[std::pair<int, int>(j, i)];
                }
            }
            else if (i == 1 || i == Length - 2)
            {
                createPiece(j, i, PieceType::Pawn, i == Length - 2);
            }
            else
            {
                BoardState[std::pair<int, int>(j, i)];
            }
        }
    }
}

bool
Board::createPiece(int X, int Y, PieceType Type, bool Color)
{
    Piece NewPiece = Piece(X, Y, Type, Color);
    BoardState[std::pair<int, int>(X, Y)] = NewPiece;
    if (Color)
    {
        WhitePieces.insert(NewPiece);
    }
    else
    {
        BlackPieces.insert(NewPiece);
    }
}

void
Board::printBoard()
{
    for (unsigned i = 0; i < Length; ++i)
    {
        for (unsigned j = 0; j < Width; ++j)
        {
            std::cout << BoardState[std::pair<int, int>(j, i)] << " ";
        }
        std::cout << std::endl;
    }
}


void
Board::recordCapture(Piece PieceCapturing)
{
    if (PieceCapturing.PieceLabel == PieceType::Pawn)
    {
        PGNGameRecord << FileMap[PieceCapturing.getColumn()];
    }
    PGNGameRecord << "x";
}