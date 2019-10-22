#ifndef PLAYER_CPP
#define PLAYER_CPP
class Player {
private:
    int health;
    int armor;
    string name;
public:
    Player(int hea, int arm, string nam);
    void changeHealth();
    void setArmor();
}

Player::Player(int hea, int arm, string nam) {
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
};

void Player::setArmor() {
    int a;
    cout << name << "'s current armor is: " << armor << endl;
    cout << "How much did the armor change? ";
    cin >> a;
    armor += a;
};
#endif
