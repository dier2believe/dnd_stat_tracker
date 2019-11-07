/* Liz Dieringer */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "player_class.h"
#include "monster_class.h"
using namespace std;


// Function to import all of the players and monsters
void importEntities(Player **players, Monster **monsters) {
    // variables to keep track of file info
    string line;
    int health;
    int armor;
    string name;
    string className;
    // variables to keep track of loops
    int done = 0;
    int entityNum = 0;
    
    // open the file to read from it
    ifstream fin ("starting_entities.txt");
    // if it doesn't open then throw an exception
    if (fin.fail()) {
        throw(1);
    }
    
    // remove the players line and set up loop variables
    fin >> line;
    done = 0;
    entityNum = 0;
    // Get all of the information from the file and create the players
    while (!done) {
        fin >> line;
        // make sure that there are still players to add
        if (line != "Monsters") {
            // get information
            fin >> name;
            fin >> line;
            fin >> health;
            fin >> line;
            fin >> armor;
            fin >> line;
            fin >> className;
            // add new player
            (*players)[entityNum].setValues(health, armor, name, className, 0);
            entityNum++;
        } else {
            done++;
        }
    }
    
    // set up loop variables
    done = 0;
    entityNum = 0;
    // Get all of the information from the file and create the monsters
    while (!done) {
        fin >> line;
        // make sure that there are still monsters to add
        if (line != "DONE") {
            // get information
            fin >> name;
            fin >> line;
            fin >> health;
            fin >> line;
            fin >> armor;
            fin >> line;
            fin >> className;
            // add new monster
            (*monsters)[entityNum].setValues(health, armor, name, className);
            entityNum++;
        } else {
            done++;
        }
    }
    
    //close file
    fin.close();

}



