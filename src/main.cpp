#include <iostream>
#include <memory>

#include "Player.h"
#include "Board.h"

int main()
{
    bool GameOver = false;
    Player WhitePlayer = Player(true);
    Player BlackPlayer = Player(false);
    std::shared_ptr<Board> GameBoard = Board::instance();
    GameBoard->createBoard(8, 8);
    GameBoard->printBoard();

    while (!GameOver)
    {
        std::cout << "hello world\n";
        GameOver = true;
    }

    return 0;
}