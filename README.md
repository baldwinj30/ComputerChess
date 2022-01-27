# ComputerChess

Two computers playing chess by making random, and mostly legal, moves.

## Environment Guidelines

This program was developed and tested on Ubuntu 18.04 and is compiled with g++. Uses CMake 3.10.

## Compiling and Running

In the root directory, create a `build` directory. Then, run

```sh
cd build
cmake ../
make
```

on initial compile. From then on, you can just run `make`. Run from `build` with `./src/ComputerChess`.

The tests can be run from `./test/board_test`.

## Expected Output

Upon program completion, the final board state will print, as well as the Portable Game Notation (PGN) game 
recording and the random seed for reproducibility.

The chess board prints with two dashes (`--`) to represent an empty space. The upper left corner is the origin.
The occupied spaces have a capital `W` or `B` to represent the color of the piece, and then a lower case letter
to represent the type of piece:

* p - pawn
* n - knight
* k - king
* b - bishop
* r - rook
* q - queen

The game currently ends after 50 turns, or after a stalemate or checkmate whichever occurs first. In the case of a stalemate or checkmate,
text will print out indicating which color couldn't legally move.

Further, the program currently prints out a copy of the game in PGN format at completion. Not all of the output
is necessarily valid, but you can copy and paste it to https://chesstempo.com/pgn-viewer/ to check where the invalid
moves occured and to view the valid moves.

## Todos

Several rules of chess are still currently missing, and some other nice features could be implemented:

* Checkmate has not been tested yet. The number of moves can really blow up as the foolish computers get down to only a few pieces at the end.
* Tests! Right now we do not have a great way to verify how well the rules are being followed,
other than just a visual check. A very nice method would be printing out a string of chess moves
and then replaying them on a chess website. In this case we should also print out the seed for debugging.
* Pawns just kind of end their life on the back row; they do not currently trade in for anything.
* No "en passe" move exists yet for pawns, where they can capture each other if they pass at a certain point.
* No castling exists. This may be the last feature, as it will be a tough one.
