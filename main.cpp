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
    // Set up the number trackers for all the entities
    int playerNum;
    int monsterNum;
    int entityNum;
    // Set up variables to keep track of living entities
    int playersAlive;
    int monstersAlive;
    // set up random variables used throughout
    int turnNum = 0;
    char c;
    string trash;
    int done;
    // set up vector of all of the monsters and players
    vector<Entity*> orderArr;
    
    // Get the number of players and monsters and set up variables
    cout << "How many players do you have? ";
    cin >> playerNum;
    cout << "How many monsters do you have? ";
    cin >> monsterNum;
    entityNum = playerNum + monsterNum;
    // Create the array of players and monsters
    Player *players = new Player[playerNum];
    Monster *monsters = new Monster[monsterNum];
    
    // loop through to set up the entites
    done = 0;
    while (!done) {
        try {
            // try to import from the file
            importEntities(&players, &monsters);
            done++;
        }
        catch (int x) {
            // if it comes back from an exception it askes if they will put the information in manually
            cout << "Make sure your file is named 'starting_entities.txt'" << endl;
            cout << "Would you like to manually put in your entites? (y)es or (n)o: ";
            cin >> c;
            // if they say yes it calls the functions to manually set the entities up
            if (c == 'y') {
                setupPlayers(playerNum, &players);
                setupMonsters(monsterNum, &monsters);
                done++;
            }
            getline(cin, trash);
        }
    }
    
    // call the function to randomize the order of players and monsters
    orderArr = initializeOrder(playerNum, players, monsterNum, monsters);
    cout << endl;
    //Setting entityNum in the entity class to entityNum
    Entity::setEntityNum(entityNum);
    
    //This prints out the entities information in the random order
    cout << "Order after Initiative: " << endl << endl;
    //using operation overloading of the insertion operator to print them
    cout << orderArr;  

    // set up the initial entites alive to the current entity nums
    playersAlive = playerNum;
    monstersAlive = monsterNum;
    // loop through each turn as long as each group has at least one entity alive
    while ((playersAlive > 0) && (monstersAlive > 0)) {
        // check to see if the current entities turn is alive
        if (orderArr[turnNum]->returnIsDead() == 0) {
            // Prints ther entity's name and askes if they want to attack
            cout << endl << "It is " << orderArr[turnNum]->getName() << "'s turn." << endl;
            cout << "Does " << orderArr[turnNum]->getName() << " want to attack? (y)es or (n)o: ";
            cin >> c;
            
            if (c == 'y') {
                // if they want to attack then call the attack function until they give a valid name
                done = 0;
                getline(cin, trash);
                while (!done) {
                    try {
                        // try to call the attack function
                        attack(turnNum, orderArr, entityNum);
                        // if sucessful then end the loop
                        done++;
                    }
                    catch(int x) {
                        // if it didn't work let the user know and try again
                        cout << "That name was invalid." << endl;
                    }
                }
            }
            // once the entity is done with the attack then ask if the entity's stats changed
            statChange(turnNum, orderArr);
        } else {
            // if the entity is dead let the user know before the next turn
            cout << endl << "**" << orderArr[turnNum]->getName() << " is dead" << "**" << endl << endl;
        }
        
        // next entities turn and loop around if at the end of the list
        turnNum++;
        if (turnNum >= entityNum) {
            turnNum = 0;
        }
        // update which players and monsters are alive and print the output
        playersAlive = playersDead(playerNum, players);
        monstersAlive = monstersDead(monsterNum, monsters);
        cout << endl << endl << "PlayersAlive: " << playersAlive << endl;
        cout << "MonstersAlive: " << monstersAlive << endl << endl;
    }
    
    // once done print if the players won or lost
    if (playersAlive == 0) {
        cout << endl << "Players lost..." << endl;
    } else {
        cout << endl << "Players win!" << endl;
    }
    
    // print the ending stats of the monsters and players for future use
    exportEntities(playerNum, monsterNum, players, monsters);
    
    return 0;
}
