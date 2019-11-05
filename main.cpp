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
#include "is_dead_players.cpp"
#include "is_dead_monsters.cpp"
#include "stat_change.cpp"
#include "attack.cpp"
using namespace std;

int main() {
    int playerNum;
    int userEntityNum; //The users variable to set the total of entities
    int entityNum;
    int monsterNum;
    int playersAlive;
    int monstersAlive;
    int turnNum = 0;
    char c;
    string trash;
    int complete;
    vector<Entity*> orderArr;
    /*
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
    */
    
    
    // TEST FOR NOW
    playerNum = 2;
    monsterNum = 2;
    Player *players = new Player[playerNum];
    players[0].setValues(20, 20, "Tom", "Mage", 0);
    players[1].setValues(20, 20, "Jerry", "Mage", 0);
    Monster *monsters = new Monster[monsterNum];
    monsters[0].setValues(20, 20, "dog", "undead");
    monsters[1].setValues(20, 20, "cat", "undead");
    // Done with test data
    
    
    
    
    
    entityNum = playerNum + monsterNum;
    
    orderArr = initializeOrder(playerNum, players, monsterNum, monsters);
    cout << endl;
    
    /*Asking the user of the tracker how many entities there are going to be or
      better put, how many players and monsters there are in total. */
    cout << "How many entities are there? "; 
    cin >> userEntityNum;
    /*Setting entityNum in the entity class to userEntityNum*/
    Entity::setEntityNum(userEntityNum);
    
    /*This prints out the name of the entity as well as its health and armor in the
      order randomly choosen*/
    cout << "Order after Initiative: " << endl << endl;
    /*By using operation overloading of the insertion operator we can just
      use orderArr*/
    cout << orderArr;  

    
    playersAlive = playerNum;
    monstersAlive = monsterNum;
    while ((playersAlive > 0) && (monstersAlive > 0)) {
        // Turns
        if (orderArr[turnNum]->returnIsDead() == 0) {
            cout << endl << "It is " << orderArr[turnNum]->getName() << "'s turn." << endl;
            cout << "Does " << orderArr[turnNum]->getName() << " want to attack? (y)es or (n)o: ";
            cin >> c;
            if (c == 'y') {
                complete = 0;
                getline(cin, trash);
                while (!complete) {
                    try {
                        attack(turnNum, orderArr, entityNum);
                        complete++;
                    }
                    catch(int x) {
                        cout << "That name was invalid." << endl;
                    }
                }
            }
            statChange(turnNum, orderArr);
        } else {
            cout << endl << "**" << orderArr[turnNum]->getName() << " has died" << "**" << endl << endl;
        }
        
        turnNum++;
        if (turnNum >= entityNum) {
            turnNum = 0;
        }
        playersAlive = playersDead(playerNum, players);
        monstersAlive = monstersDead(monsterNum, monsters);
        cout << endl << endl << "PlayersAlive: " << playersAlive << endl;
        cout << "MonstersAlive: " << monstersAlive << endl << endl;
    }
    
    if (playersAlive == 0) {
        cout << endl << "Players lost..." << endl;
    } else {
        cout << endl << "Monsters lost!" << endl;
    }
    
    return 0;
}
