# ComputerChess

Two computers playing chess.

Represent the board as a 2D vector of ints with ones and zeros for piece or no piece;
perhaps make it a singleton just so we have it available everywhere always.

When we check moves, simply ensure that we don't go out of bounds or if we land on
another piece make sure we check that out as well.
