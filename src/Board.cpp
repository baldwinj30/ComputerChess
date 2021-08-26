#include "Board.h"

#include <iostream>

bool
Board::createBoard(int Width, int Length)
{
    if (Width < 8 || Length < 8 || Width != Length)
    {
        return false;
    }
    std::vector<int> EmptyRow(Width);
    std::vector<std::vector<int>> EmptyBoard(Length, EmptyRow);
    std::vector<int> FullRow(Width, 1);
    /* Fill up the board */
    EmptyBoard[0] = FullRow;
    EmptyBoard[1] = FullRow;
    EmptyBoard[Length-1] = FullRow;
    EmptyBoard[Length-2] = FullRow;
    this->BoardState = EmptyBoard;
}

void
Board::printBoard()
{
    for (unsigned i = 0; i < BoardState.size(); ++i)
    {
        std::vector<int> Row = BoardState[i];
        for (unsigned j = 0; j < Row.size(); ++j)
        {
            std::cout << Row[j] << " ";
        }
        std::cout << std::endl;
    }
}
