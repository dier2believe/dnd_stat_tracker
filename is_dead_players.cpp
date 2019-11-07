/* Liz Dieringer */
#include "player_class.h"

// checks to see how many players are still alive
int playersDead(int playerNum, Player *players) {
    int allDead = playerNum;
    for (int i = 0; i < playerNum; i++) {
        // subtracts a player from the rest if they are dead
        allDead -= players[i].returnIsDead();
    }
    // returns the number of players still alive
    return allDead;
}
