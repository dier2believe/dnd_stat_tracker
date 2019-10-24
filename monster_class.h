/* Liz Dieringer 
   Xanth Rossnagle */
#include <iostream>
#include <string>
using namespace std;

#ifndef MONSTER_CPP
#define MONSTER_CPP
class Monster {
private:
    Types type;
    
public:
    Monster(int = 10, int = 10, string = "unknown");
};

Monster::Monster(int hea, int arm, string nam) {
    health = hea;
    armor = arm;
    name = nam;
}
#endif
