/* Liz Dieringer
   Nicole Lord */
#include <iostream>
#include <string>
using namespace std;

#ifndef ENTITY_CPP
#define ENTITY_CPP
class Entity {
protected:
    int health;
    int armor;
    string name;
    int idNum;
    int isDead;
public:
    Entity() {}
    ~Entity() {}
    virtual void setValues(int hea, int arm, string nam);
    string getName();
    int getHealth();
    int getArmor();
    void changeHealth();
    void changeArmor();
    int returnIsDead();
    void isDeadCheck();
    friend ostream& operator<<(ostream &os, const vector<Entity*> &orderArr);
};

void Entity::setValues(int hea, int arm, string nam) {
    health = hea;
    armor = arm;
    name = nam;
}

string Entity::getName() {
    return name;
}

int Entity::getHealth() {
    return health;
}

int Entity::getArmor() {
    return armor;
}

void Entity::changeHealth() {
    int h;
    cout << name << "'s current health is: " << health << endl;
    cout << "How much did " << name << "'s health change? " <<
        "(Negative number for a decrease in health, positive for an increase.) ";
    cin >> h;
    health += h;
}

void Entity::changeArmor() {
    int a;
    cout << name << "'s current armor is: " << armor << endl;
    cout << "How much did " << name << "'s armor change? " <<
        "(Negative number for a decrease in health, positive for an increase.) ";
    cin >> a;
    armor += a;
}

int Entity::returnIsDead() {
    return isDead;
}

void Entity::isDeadCheck() {
    if (health <= 0) {
        isDead = 1;
        cout << "isDead: " << isDead << " should be different " << endl;
        cout << endl << " **** " << name << " has died" << " **** " << endl << endl;
    } else {
        isDead = 0;
    }
}

ostream& operator<<(ostream &os, const vector<Entity*> &orderArr) {
    int entityNum = 0;
    int playerNum = 2;
    int monsterNum = 2;
    entityNum = playerNum + monsterNum;
    for( int i = 0; i < entityNum; i++) {
        os << "Name: " << orderArr[i]->name << endl;
    }
    return os;
}

#endif
