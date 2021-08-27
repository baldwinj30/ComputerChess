#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "Player.h"
#include "Board.h"

int main()
{
    std::srand(std::time(nullptr));
    int TurnCount = 0;
    bool GameOver = false;
    std::shared_ptr<Board> GameBoard = Board::instance();
    GameBoard->createBoard(8, 8);
    Player WhitePlayer = Player(true);
    Player BlackPlayer = Player(false);

    while (!GameOver)
    {
        if (!WhitePlayer.makeRandomMove())
        {
            std::cout << "Stalemate, White can't move\n";
            break;
        }
        GameBoard->printBoard();
        std::cout << "**********\n";
        if (!BlackPlayer.makeRandomMove())
        {
            std::cout << "Stalemate, Black can't move\n";
            break;
        }
        GameBoard->printBoard();
        std::cout << "**********\n";
        std::cout << "----------\n";
        TurnCount++;
        if (TurnCount > 50)
        {
            GameOver = true;
        }
    }

    return 0;
}