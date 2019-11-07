/* Liz Dieringer 
   Nicole Lord */
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
#include "import_entities.cpp"
#include "export_entities.cpp"
using namespace std;

int main() {
    int playerNum;
    int monsterNum;
    int entityNum;
    
    int playersAlive;
    int monstersAlive;
    
    int turnNum = 0;
    char c;
    string trash;
    int done;
    vector<Entity*> orderArr;
    
    
    cout << "How many players do you have? ";
    cin >> playerNum;
    cout << "How many monsters do you have? ";
    cin >> monsterNum;
    Player *players = new Player[playerNum];
    Monster *monsters = new Monster[monsterNum];
    done = 0;
    while (!done) {
        try {
            importEntities(playerNum, monsterNum, &players, &monsters);
            done++;
        }
        catch (int x) {
            cout << "Make sure your file is named 'starting_entities.txt'" << endl;
            cout << "Would you like to manually put in your entites? (y)es or (n)o: ";
            cin >> c;
            if (c == 'y') {
                setupPlayers(playerNum, &players);
                setupMonsters(monsterNum, &monsters);
                done++;
            }
            getline(cin, trash);
        }
    }
    
    entityNum = playerNum + monsterNum;
    
    orderArr = initializeOrder(playerNum, players, monsterNum, monsters);
    cout << endl;
    /*Setting entityNum in the entity class to entityNum*/
    Entity::setEntityNum(entityNum);
    
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
                done = 0;
                getline(cin, trash);
                while (!done) {
                    try {
                        attack(turnNum, orderArr, entityNum);
                        done++;
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
    
    exportEntities(playerNum, monsterNum, players, monsters);
    
    return 0;
}
