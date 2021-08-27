#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "Player.h"
#include "Board.h"

int main()
{
    std::srand(std::time(nullptr));
    bool GameOver = false;
    std::shared_ptr<Board> GameBoard = Board::instance();
    GameBoard->createBoard(8, 8);
    Player WhitePlayer = Player(true);
    Player BlackPlayer = Player(false);

    while (!GameOver)
    {
        WhitePlayer.makeRandomMove();
        GameBoard->printBoard();
        std::cout << "**********\n";
        BlackPlayer.makeRandomMove();
        GameBoard->printBoard();
        std::cout << "**********\n";
        std::cout << "----------\n";
        GameOver = true;
    }

    return 0;
}