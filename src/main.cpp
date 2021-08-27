#include <iostream>
#include <memory>

#include "Player.h"
#include "Board.h"

int main()
{
    bool GameOver = false;
    std::shared_ptr<Board> GameBoard = Board::instance();
    GameBoard->createBoard(8, 8);
    GameBoard->printBoard();
    Player WhitePlayer = Player(true);
    Player BlackPlayer = Player(false);

    while (!GameOver)
    {
        WhitePlayer.makeRandomMove();
        GameBoard->printBoard();
        std::cout << "**********";
        BlackPlayer.makeRandomMove();
        GameBoard->printBoard();
        std::cout << "**********";
        std::cout << "----------";
        GameOver = true;
    }

    return 0;
}