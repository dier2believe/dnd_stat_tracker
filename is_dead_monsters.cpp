/* Nicole Lord
   Liz Dieringer */
#include "monster_class.h"

int monstersDead(int monsterNum, Monster *monsters) {
    int i;
    int allDead = monsterNum;
    cout << endl << endl << "Total monsters : " << allDead << endl;
    for (i = 0; i < monsterNum; i++) {
        allDead -= monsters[i].returnIsDead();
        cout << "monster dead" << endl << "total monsters: " << allDead << endl;
    }
    return allDead;
}
