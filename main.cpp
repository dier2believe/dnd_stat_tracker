#include <iostream>
#include <string>
#include "player_class.h"
#include "monster_class.h"
#include "setupPlayers.cpp"
using namespace std;

int main() {
    int playerNum;
    
    cout << "How many players do you have? ";
    cin >> playerNum;
    Player *players = new Player[playerNum];
    setupPlayers(playerNum, &players);
    
    return 0;
}

