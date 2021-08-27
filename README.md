# ComputerChess

Two computers playing chess by making random, and mostly legal, moves.

## Environment Guidelines

This program was developed and tested on Ubuntu 18.04 and is compiled with g++.

## Compiling and Running

In the root directory, run `make` to build and `make clean` to clean.

Run `./bin/chess` to run the program with a time-based seed; a single integer argument can be passed
to run the program with a set seed for deterministic output.

## Expected Output

You should see several consecutive scenes from a chess board print to the terminal. You should be able to visually verify
that entirely legal moves are occurring from one step to the next, with the exception of the TODOs below. Above each board
there should be an indication of the piece that moved, and below there should be a separator of asterisks before the next board,
and after White and Black have each taken a turn there will be a separator of plus signs.

The chess board prints with two dashes (`--`) to represent an empty space. The occupied spaces have a capital `W` or `B`
to represent the color of the piece, and then a lower case letter to represent the type of piece:

* p - pawn
* n - knight
* k - king
* b - bishop
* r - rook
* q - queen

The game currently ends after 50 turns, or after a stalemate whichever occurs first. In the case of a stalemate,
text will print out indicating which color couldn't legally move, causing the stalemate.

## Todos

Several rules of chess are still currently missing, and some other nice features could be implemented:

* Check and checkmate are not yet implemented. This is a key part of chess, as we need to be able to win
and make sure we treat the king as the special piece that it is.
* Tests! Right now we do not have a great way to verify how well the rules are being followed,
other than just a visual check. A very nice method would be printing out a string of chess moves
and then replaying them on a chess website. In this case we should also print out the seed for debugging.
* Pawns just kind of end their life on the back row; they do not currently trade in for anything.
* No "en passe" move exists yet for pawns, where they can capture each other if they pass at a certain point.
* No castling exists. This may be the last feature, as it will be a tough one.
