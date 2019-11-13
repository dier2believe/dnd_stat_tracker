/* Liz Dieringer */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "player_class.h"
#include "monster_class.h"
using namespace std;

// Function to export the players and monsters ending information
void exportEntities(int playerNum, int monsterNum, Player *players, Monster *monsters) {
    // open the file to write to
    ofstream fout ("ending_entities.txt");
    // if the file fails to open then throw an exception
    if (fout.fail()) {
        throw(1);
    }
    
    // Print out all of the players information
    fout << "Players " << playerNum << endl << endl;
    for (int i = 0; i < playerNum; i++) {
        fout << "Name: " << players[i].getName() << endl;
        fout << "Health: " << players[i].getHealth() << endl;
        fout << "Armor: " << players[i].getArmor() << endl;
        fout << "Class: " << players[i].getClass() << endl << endl;
    }
    
    // Print out all of the monsters information
    fout << "Monsters " << monsterNum << endl << endl;
    for (int j = 0; j < monsterNum; j++) {
        fout << "Name: " << monsters[j].getName() << endl;
        fout << "Health: " << monsters[j].getHealth() << endl;
        fout << "Armor: " << monsters[j].getArmor() << endl;
        fout << "Class: " << monsters[j].getType() << endl << endl;
    }
    
    // End the file so they can use it again to import
    fout << "DONE";
    
    fout.close();  //close file

}


