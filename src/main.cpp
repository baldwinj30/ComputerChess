#include <iostream>

#include "Player.h"

int main()
{
    bool GameOver = false;
    Player WhitePlayer = Player(true);
    Player BlackPlayer = Player(false);

    while (!GameOver)
    {
        std::cout << "hello world\n";
        GameOver = true;
    }

    return 0;
}