#include <string>
#include <iostream>
using namespace std;
struct MovieNode
{

    int movieID;
    string movieName;
    float rating;

    MovieNode *prev;
    MovieNode *next;

    MovieNode(int id, string name, float r)
    {
        movieID = id;
        movieName = name;
        rating = r;
        prev = NULL;
        next = NULL;
    }
};