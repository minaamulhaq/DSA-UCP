#include <iostream>
#include "CircularPlayerList.h"
using namespace std;

int main()
{
    CircularPlayerList game;

    game.addPlayer(1, 50);
    game.addPlayer(2, 70);
    game.addPlayer(3, 40);
    game.addPlayer(4, 90);

    game.displayPlayers();

    game.nextTurn();
    game.nextTurn();

    game.skipPlayer();

    game.removePlayer(2);

    game.displayPlayers();

    game.removePlayer(3);
    game.removePlayer(4);

    return 0;
}