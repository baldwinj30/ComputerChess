#ifndef UTILS_H
#define UTILS_H

#include "pieces/Piece.h"

#include <vector>
#include <set>

/* Helper function to quickly transfer the pieces from a set
to a vector and to find the King */
std::vector<Piece>
getPieces(std::set<Piece> Pieces, Piece &King);

int
getRandBelow(int Max);

#endif /* UTILS_H */
