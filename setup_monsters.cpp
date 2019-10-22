#include <iostream>
#include <string>
using namespace std;

void setupMonsters(int monsterNum, Monster **monsters) {
    int health;
    int armor;
    string name;
    
    for (int i = 0; i < monsterNum; i++) {
        cout << "What is the monster's name? ";
        cin >> name;
        cout << "What is " << name << "'s health? ";
        cin >> health;
        cout << "What is " << name << "'s armor? ";
        cin >> armor;
        
        (*monsters[i]).setValues(health, armor, name);
    }
}
