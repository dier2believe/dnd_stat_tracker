/* Xanth Rossnagle
   Liz Dieringer */
#include "monster_class.h"

// set up the monsters manually if needed
void setupMonsters(int monsterNum, Monster **monsters) {
    // variables to get information from the user
    int health;
    int armor;
    string name;
    string typeName;
    
    // loop through to get the information for each monster
    for (int i = 0; i < monsterNum; i++) {
        cout << "What is the monster's name? ";
        cin >> name;
        cout << "What is " << name << "'s health? ";
        cin >> health;
        cout << "What is " << name << "'s armor? ";
        cin >> armor;
        cout << "What is " << name << "'s type? ";
        cin >> typeName;
        
        // set up the monster
        (*monsters)[i].setValues(health, armor, name, typeName);
    }
}
