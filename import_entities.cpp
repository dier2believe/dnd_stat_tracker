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
    int playerNum;
    int monsterNum;
    string line;
    int health;
    int armor;
    string name;
    string className;
    
    // open the file to read from it
    ifstream fin ("starting_entities.txt");
    // if it doesn't open then throw an exception
    if (fin.fail()) {
        throw(1);
    }
    
    // remove the players title
    fin >> line;
    // remove the number of players
    fin >> playerNum;
    // Get all of the information from the file and create the players
    for (int i = 0; i < playerNum; i++) {
        // get information
        fin >> line;
        fin >> name;
        fin >> line;
        fin >> health;
        fin >> line;
        fin >> armor;
        fin >> line;
        fin >> className;
        // add new player
        (*players)[i].setValues(health, armor, name, className, 0);
    }
    
    // remove the monsters title
    fin >> line;
    // remove the number of monsters
    fin >> monsterNum;
    // Get all of the information from the file and create the monsters
    for (int j = 0; j < monsterNum; j++) {
        // get information
        fin >> line;
        fin >> name;
        fin >> line;
        fin >> health;
        fin >> line;
        fin >> armor;
        fin >> line;
        fin >> className;
        // add new monster
        (*monsters)[j].setValues(health, armor, name, className);
    }
    
    fin.close();  //close file

}



