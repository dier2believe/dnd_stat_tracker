/* Nicole Lord
   Liz Dieringer */
#include "monster_class.h"

//This function checks to see how many monsters are still alive.
int monstersDead(int monsterNum, Monster *monsters) {
    int i;
    int allDead = monsterNum;
    for (i = 0; i < monsterNum; i++) {
        //Subtracts the monster from the total if it is dead
        allDead -= monsters[i].returnIsDead();
    }
    return allDead;
}
