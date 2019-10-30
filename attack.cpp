/* Liz Dieringer */
#include "entity_class.h"
#include "monster_class.h"
#include "player_class.h"
#include <vector>

void attack(int turnNum, vector<Entity*> &orderArr, int totalEntities) {
    string victimName;
    int victim;
    int damage;
    cout << "Who does " << orderArr[turnNum]->getName() << " want to attack? ";
    cin >> victimName;
    for (int i = 0; i < totalEntities; i++) {
        if (orderArr[i]->getName() == victimName) {
            victim = i;
        }
    }
    orderArr[victim]->changeHealth();
    orderArr[victim]->isDeadCheck();
}
