/* Liz Dieringer
   Nicole Lord */
#include <iostream>
#include <string>
using namespace std;

#ifndef ENTITY_CPP
#define ENTITY_CPP
// set up the parent Entity class
class Entity {
protected:
    int health;
    int armor;
    string name;
    static int entityNum;
    int isDead;
public:
    Entity() {}
    ~Entity() {}
    virtual void setValues(int hea, int arm, string nam);
    static void setEntityNum(int x) {entityNum = x;}
    string getName();
    int getHealth();
    int getArmor();
    void changeHealth();
    void changeArmor();
    int returnIsDead();
    void isDeadCheck();
    friend ostream& operator<<(ostream &os, const vector<Entity*> &orderArr);
};

int Entity::entityNum = 0;   //Initializing the number of entities

// default constructor for the Entity class
void Entity::setValues(int hea, int arm, string nam) {
    health = hea;
    armor = arm;
    name = nam;
}

// Functions to get the information from the Entity to print
string Entity::getName() {
    return name;
}

int Entity::getHealth() {
    return health;
}

int Entity::getArmor() {
    return armor;
}

// Functions to change the stats of the Entity individually
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

// Function to return if the Entity is dead
int Entity::returnIsDead() {
    return isDead;
}

// Function to check if the Entity has died
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
    //This function allows us to just call cout << orderArr in main
    int entityNumber = 0;
    //Getting the total of entities from the global entity variable
    entityNumber = Entity::entityNum;
    for( int i = 0; i < entityNumber; i++) {
        //Prints out the name, health, and armor of an enitity.
        os << "Name: " << orderArr[i]->name << endl;
        os << "Health: " << orderArr[i]->getHealth() << endl;
        os << "Armor: " << orderArr[i]->getArmor() << endl << endl;
    }
    return os;
}

#endif
