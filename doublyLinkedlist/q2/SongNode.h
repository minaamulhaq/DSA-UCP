#include <iostream>
#include <string>
using namespace std;

class SongNode
{
public:
    int songID;
    string songName;
    float duration;

    SongNode *prev;
    SongNode *next;

    SongNode(int id, string name, float d)
    {
        songID = id;
        songName = name;
        duration = d;
        prev = NULL;
        next = NULL;
    }
};
