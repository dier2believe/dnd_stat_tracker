/* Nicole Lord
   Liz Dieringer */
#include "monster_class.h"

int monstersDead(int monsterNum, Monster *monsters) {
    int i;
    int allDead = monsterNum;
    for (i = 0; i < monsterNum; i++) {
        allDead -= monsters[i].returnIsDead();
    }
    return allDead;
}
