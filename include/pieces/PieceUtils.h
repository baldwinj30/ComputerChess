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

/**
 * Rooks can move up and down single rows and columns until they run into a piece.
 */
std::vector<std::pair<int, int>>
possibleRookMoves(Piece Rook, const std::map<std::pair<int, int>, Piece> &BoardState, int MaxWidth, int MaxLength);

/**
 * Bishops can move diagonally in any direction until they run into a piece.
 */
std::vector<std::pair<int, int>>
possibleBishopMoves(Piece Bishop, const std::map<std::pair<int, int>, Piece> &BoardState, int MaxWidth, int MaxLength);

/**
 * Queens are simply the combination of bishops and rooks.
 */
std::vector<std::pair<int, int>>
possibleQueenMoves(Piece Queen, const std::map<std::pair<int, int>, Piece> &BoardState, int MaxWidth, int MaxLength);

#endif