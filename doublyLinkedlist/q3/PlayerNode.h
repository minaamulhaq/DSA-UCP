

class PlayerNode
{
public:
    int playerID;
    int score;
    PlayerNode *next;

    PlayerNode(int id, int s)
    {
        playerID = id;
        score = s;
        next = nullptr;
    }
};
