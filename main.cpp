/* Liz Dieringer */
#include <iostream>
#include <string>
#include <vector>
#include "entity_class.h"
#include "player_class.h"
#include "monster_class.h"
#include "setup_players.cpp"
#include "setup_monsters.cpp"
#include "initialize_order.cpp"
using namespace std;

int main() {
    int playerNum;
    int monsterNum;
    vector<Entity> orderArr;
    
    cout << "How many players do you have? ";
    cin >> playerNum;
    cout << endl;
    Player *players = new Player[playerNum];
    setupPlayers(playerNum, &players);
    cout << endl;
    
    cout << "How many monsters do you have? ";
    cin >> monsterNum;
    cout << endl;
    Monster *monsters = new Monster[monsterNum];
    setupMonsters(monsterNum, &monsters);
    cout << endl;
    
    orderArr = initializeOrder(playerNum, players, monsterNum, monsters);
    cout << endl;
    
    for( int i = 0; i < (playerNum + monsterNum); i++) {
        cout << "Name: " << orderArr[i].getName() << endl;
        cout << "Health: " << orderArr[i].getHealth() << endl;
        cout << "Armor: " << orderArr[i].getArmor() << endl;
    }
    
    return 0;
}
