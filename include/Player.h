#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "pieces/Piece.h"

class Player
{
    public:

    Player(bool Color){
        this->Color = Color;
        createPieces();
    }

    bool Color;
    std::vector<Piece> PlayerPieces;

    private:

    void createPieces();
};

#endif /* PLAYER_H */
