#include <iostream>
#include <string>
using namespace std;

#ifndef PLAYER_CPP
#define PLAYER_CPP
class Player {
private:
    int health;
    int armor;
    string name;
public:
    Player(int = 100, int = 50, string = "unknown");
    void setValues(int hea, int arm, string nam);
    void changeHealth();
    void changeArmor();
};

Player::Player(int hea, int arm, string nam) {
    health = hea;
    armor = arm;
    name = nam;
}

void Player::setValues(int hea, int arm, string nam) {
    health = hea;
    armor = arm;
    name = nam;
}

void Player::changeHealth() {
    int h;
    cout << name << "'s current health is: " << health << endl;
    cout << "How much did the health change? ";
    cin >> h;
    health += h;
}

void Player::changeArmor() {
    int a;
    cout << name << "'s current armor is: " << armor << endl;
    cout << "How much did the armor change? ";
    cin >> a;
    armor += a;
}
#endif
