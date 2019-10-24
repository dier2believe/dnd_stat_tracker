/* Liz Dieringer 
   Xanth Rossnagle */
#include <iostream>
#include <string>
#include "entity.h"
using namespace std;

#ifndef PLAYER_CPP
#define PLAYER_CPP
class Mastery {
private:
    string className;
public:
    Mastery();
}

Mastery::Mastery() {
    cout << "What's this character's class? ";
    cin >> className;
}

class Player : public entitiy {
private:
    int exp;
    Mastery skills;
public:
    Player(int = 10, int = 10, string = "unknown", int = 0);
    ~Player() {}
};

Entity::Entity(int hea, int arm, string nam, int ex) {
    health = hea;
    armor = arm;
    name = nam;
    exp = ex;
}

#endif
