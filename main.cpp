#include <iostream>
#include <string>
#include "player_class.h"
#include "monster_class.h"
#include "setup_players.cpp"
#include "setup_monsters.cpp"
using namespace std;

int main() {
    int playerNum;
    int monsterNum;
    
    cout << "How many players do you have? ";
    cin >> playerNum;
    Player *players = new Player[playerNum];
    setupPlayers(playerNum, &players);
    
    cout << "How many monsters do you have? ";
    cin >> monsterNum;
    Monster *monsters = new Monster[monsterNum];
    setupMonsters(monsterNum, &monsters);
    return 0;
}
