#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "Player.h"
#include "Board.h"

int main(int argc, char * argv[])
{
    unsigned int seed;
    /* Simple argument parsing. */
    if (argc > 2)
    {
        std::cout << "This program accepts only one optional unsigned integer argument for the RNG seed.\n";
        return 0;
    }
    else if (argc == 2)
    {
        seed = std::atoi(argv[1]);
        if (seed == 0)
        {
            std::cout << "Either bad input was passed or the seed was manually set to 0. Continuing...\n";
        }
    }
    else
    {
        seed = std::time(nullptr);
    }

    std::srand(seed);
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
        std::cout << "++++++++++\n";
        TurnCount++;
        if (TurnCount > 50)
        {
            GameOver = true;
        }
    }

    return 0;
}