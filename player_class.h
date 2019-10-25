/* Liz Dieringer 
   Xanth Rossnagle */
#include <iostream>
#include <string>
#include "entity_class.h"
#include "mastery_class.h"
using namespace std;

#ifndef PLAYER_CPP
#define PLAYER_CPP
class Player : public Entity {
private:
    int exp;
    Mastery skills;
public:
    Player(int = 10, int = 10, string = "unknown", string = "unknown", int = 0);
    void setValues(int = 10, int = 10, string = "unknown", string = "unknown", int = 0);
    ~Player() {}
};

Player::Player(int hea, int arm, string nam, string className, int ex):skills(className) {
    health = hea;
    armor = arm;
    name = nam;
    exp = ex;
}

void Player::setValues(int hea, int arm, string nam, string className, int ex) {
    health = hea;
    armor = arm;
    name = nam;
    exp = ex;
    skills.setName(className);
}

#endif
