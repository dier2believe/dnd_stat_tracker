/* Liz Dieringer */

#include <ctime>
#include <stdlib.h>  // For rand
#include <vector>
#include "entity_class.h"
#include "player_class.h"
#include "monster_class.h"
using namespace std;

vector<Entity> initializeOrder(int playerNum, Player *players, int monsterNum, Monster *monsters) {
    int totalEntities = playerNum + monsterNum;
    int randNumChosen[totalEntities];
    int done = 0;
    int inRandNumChosen = 0;
    int randNum;
    Player player;
    Monster monster;
    vector<Entity> orderArr;
    //srand(time(NULL));
    
    for (int k = 0; k < totalEntities; k++) {
        randNumChosen[k] = 1;
    }
    
    for (int i = 0; i < totalEntities; i++) {
        done = 0;
        while (!done) {
            randNum = rand() % totalEntities;
            cout << "randomNum: " << randNum << endl;
            
            if (randNumChosen[randNum]) {
                if (randNum < playerNum) {
                    cout << "random is less than playerNum" << endl;
                    randNumChosen[randNum] = 0;
                    orderArr.push_back(players[randNum]);
                } else {
                    cout << "random is more than or equal to playerNum" << endl;
                    randNumChosen[randNum] = 0;
                    orderArr.push_back(monsters[(randNum-playerNum)]);
                }
                done++;
            }
        }
    }
    
    return orderArr; // return entity vector
}
