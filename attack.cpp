/* Liz Dieringer */
#include "entity_class.h"
#include "monster_class.h"
#include "player_class.h"
#include <vector>

void attack(int turnNum, vector<Entity*> &orderArr, int totalEntities) {
    string victimName;
    int victim = -1;
    int damage;
    cout << "Who does " << orderArr[turnNum]->getName() << " want to attack? ";
    getline(cin, victimName);
    cout << endl;
    for (int i = 0; i < totalEntities; i++) {
        if (orderArr[i]->getName() == victimName) {
            victim = i;
        }
    }
    if (victim == -1) {
        throw(1);
    }
    orderArr[victim]->changeHealth();
    orderArr[victim]->isDeadCheck();
}
