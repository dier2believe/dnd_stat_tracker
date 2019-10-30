//Nicole Lord
#include "monster_class.h"

int isMonsterDead(int monsterNum, Monster *monsters) {
    int i;
    int allDead = monsterNum;
    for (i = 0; i < monsterNum; i++) {
        allDead -= monster[i].isDead;
    }
    return allDead;
}
