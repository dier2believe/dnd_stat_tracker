/* Liz Dieringer */
#include "entity_class.h"
#include "monster_class.h"
#include "player_class.h"
#include <vector>

// Function for one Entity to attack another
void attack(int turnNum, vector<Entity*> &orderArr, int totalEntities) {
    // keep track of the victim information
    string victimName;
    int victim = -1;
    
    // ask the user who the entity wants to attack 
    cout << "Who does " << orderArr[turnNum]->getName() << " want to attack? ";
    getline(cin, victimName);
    cout << endl;
    
    // loops through to find which entity has the matching victim name given
    for (int i = 0; i < totalEntities; i++) {
        if (orderArr[i]->getName() == victimName) {
            // set the victim num to the entity that will be attacked
            victim = i;
        }
    }
    // if no name match was found
    if (victim == -1) {
        // throw an exception that they were not found
        throw(1);
    }
    // change the health based on the attack damage
    orderArr[victim]->changeHealth();
    // then check if the victim died
    orderArr[victim]->isDeadCheck();
}
