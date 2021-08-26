class Player
{
    public:

    Player(bool Color){
        this->Color = Color;
        createPieces();
    }

    bool Color;

    private:

    void createPieces();
};
