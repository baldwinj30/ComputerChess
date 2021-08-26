#include <vector>
#include <memory>


class Board 
{
    public:

    Board(){};

    static std::shared_ptr<Board>instance()
    {
        static std::shared_ptr<Board> BoardInstance {new Board};
        return BoardInstance;
    }

    bool
    createBoard(int Width, int Length);

    bool
    createPieces();

    void
    printBoard();

    std::vector<std::vector<int>> BoardState;
};
