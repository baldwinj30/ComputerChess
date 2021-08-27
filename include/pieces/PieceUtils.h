#ifndef PIECEUTILS_H
#define PIECEUTILS_H

#include "Piece.h"
#include "Board.h"

#include <vector>

/**
 * The possible moves always depend on color, but for pawns it is a little bit different.
 * They can only move up OR down the board depending on their starting color, but not both.
 * No other pieces have a directive to only move in one direction.
 */
std::vector<std::pair<int, int>>
possiblePawnMoves(Piece Pawn, const std::map<std::pair<int, int>, Piece> &BoardState, int MaxWidth, int MaxLength);



#endif