#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "pieces/Piece.h"
#include "Board.h"

class Player
{
    public:

    Player(bool Color)
    {
        this->Color = Color;
        BoardInstance = Board::instance();
    }

    bool
    makeRandomMove();

    bool Color;

    private:
    std::shared_ptr<Board> BoardInstance;

};

#endif /* PLAYER_H */
