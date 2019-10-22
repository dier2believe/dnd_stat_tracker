#include <iostream>
#include <string>
using namespace std;

#ifndef MONSTER_CPP
#define MONSTER_CPP
class Monster {
private:
    int health;
    int armor;
    string name;
public:
    Monster(int = 10, int = 10, string = "unknown");
    void setValues(int hea, int arm, string nam);
    void changeHealth();
    void changeArmor();
};

Monster::Monster(int hea, int arm, string nam) {
    health = hea;
    armor = arm;
    name = nam;
}

void Monster::setValues(int hea, int arm, string nam) {
    health = hea;
    armor = arm;
    name = nam;
}
void Monster::changeHealth() {
    int h;
    cout << name << "'s current health is: " << health << endl;
    cout << "How much did the health change? ";
    cin >> h;
    health += h;
}

void Monster::changeArmor() {
    int a;
    cout << name << "'s current armor is: " << armor << endl;
    cout << "How much did the armor change? ";
    cin >> a;
    armor += a;
}
#endif
