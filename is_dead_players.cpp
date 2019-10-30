/* Liz Dieringer */
#include "player_class.h"

int playersDead(int playerNum, Player *players) {
    int allDead = playerNum;
    cout << endl << endl << "Total players : " << allDead << endl;
    for (int i = 0; i < playerNum; i++) {
        allDead -= players[i].returnIsDead();
        cout << "returnIsDead = " << players[i].returnIsDead() << endl;
        cout << "player dead" << endl << "total players: " << allDead << endl;
    }
    return allDead;
}
