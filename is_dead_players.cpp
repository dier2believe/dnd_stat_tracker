/* Liz Dieringer */
#include "player_class.h"

int playersDead(int playerNum, Player *players) {
    int allDead = playerNum;
    for (int i = 0; i < playerNum; i++) {
        allDead -= players[i].returnIsDead();
    }
    return allDead;
}
