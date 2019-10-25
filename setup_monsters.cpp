/* Xanth Rossnagle
   Liz Dieringer */
#include <iostream>
#include <string>
#include "monster_class.h"
using namespace std;

void setupMonsters(int monsterNum, Monster **monsters) {
    int health;
    int armor;
    string name;
    string typeName;
    
    for (int i = 0; i < monsterNum; i++) {
        cout << "What is the monster's name? ";
        cin >> name;
        cout << "What is " << name << "'s health? ";
        cin >> health;
        cout << "What is " << name << "'s armor? ";
        cin >> armor;
        cout << "What is " << name << "'s type? ";
        cin >> typeName;
        
        (*monsters)[i].setValues(health, armor, name, typeName);
    }
}
