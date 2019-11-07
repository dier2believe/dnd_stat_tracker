/* Liz Dieringer */
#include <time.h>
#include <stdlib.h>  // For rand
#include <vector>
#include "entity_class.h"
#include "player_class.h"
#include "monster_class.h"
using namespace std;

// set up the order of the players and monsters for turns
vector<Entity*> initializeOrder(int playerNum, Player *players, int monsterNum, Monster *monsters) {
    // variables to keep track of the loops
    int totalEntities = playerNum + monsterNum;
    int randNumChosen[totalEntities];
    int done = 0;
    int inRandNumChosen = 0;
    int randNum;
    Player player;
    Monster monster;
    
    // set up the end vector that will hold all of the monsters and players
    vector<Entity*> orderArr;
    
    // set up the random number seed based on the time
    srand(time(NULL));
    
    // loop through and initialize the randomNumChosen to 1 (1 = available placement)
    for (int k = 0; k < totalEntities; k++) {
        randNumChosen[k] = 1;
    }
    
    // loop through all of the entities to place them
    for (int i = 0; i < totalEntities; i++) {
        // loop through until the entity goes into a random place
        done = 0;
        while (!done) {
            randNum = rand() % totalEntities;
            // as long as the random placement is available
            if (randNumChosen[randNum]) {
                // if the entity is a player
                if (randNum < playerNum) {
                    // add the player to the vector and make the random number unavailable
                    randNumChosen[randNum] = 0;
                    orderArr.push_back(&players[randNum]);
                } else {
                    // otherwise add the monster to the vector and make the random number unavailable
                    randNumChosen[randNum] = 0;
                    orderArr.push_back(&monsters[(randNum-playerNum)]);
                }
                // once the random number was sucessfully chosen end the loop
                done++;
            }
        }
    }
    
    return orderArr; // return entity vector
}
