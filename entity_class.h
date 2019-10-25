/* Liz Dieringer 
   Xanth Rossnagle */
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
public:
    ~Entity() {}
    virtual void setValues(int hea, int arm, string nam);
    void changeHealth();
    void changeArmor();
};

void Entity::setValues(int hea, int arm, string nam) {
    health = hea;
    armor = arm;
    name = nam;
}

void Entity::changeHealth() {
    int h;
    cout << name << "'s current health is: " << health << endl;
    cout << "How much did the health change? ";
    cin >> h;
    health += h;
}

void Entity::changeArmor() {
    int a;
    cout << name << "'s current armor is: " << armor << endl;
    cout << "How much did the armor change? ";
    cin >> a;
    armor += a;
}
#endif
