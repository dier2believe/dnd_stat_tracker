/* Liz Dieringer */
#include "entity_class.h"
#include "mastery_class.h"

#ifndef PLAYER_CPP
#define PLAYER_CPP
// set up the Player class that inherits from Entity
class Player : public Entity {
private:
    int exp;
    Mastery skills;
public:
    Player(int = 10, int = 10, string = "unknown", string = "unknown", int = 0);
    ~Player() {}
    string getClass();
    void setValues(int = 10, int = 10, string = "unknown", string = "unknown", int = 0);
};

// Default constructor for player with all of its values
Player::Player(int hea, int arm, string nam, string className, int ex):skills(className) {
    health = hea;
    armor = arm;
    name = nam;
    exp = ex;
}

// get the class name which is private
string Player::getClass() {
    return skills.getName();
}

// change all of the values once the player already exists
void Player::setValues(int hea, int arm, string nam, string className, int ex) {
    health = hea;
    armor = arm;
    name = nam;
    exp = ex;
    skills.setName(className);
}

#endif
