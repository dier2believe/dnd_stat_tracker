/* Liz Dieringer */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "player_class.h"
#include "monster_class.h"
using namespace std;

void exportEntities(int playerNum, int monsterNum, Player *players, Monster *monsters) {
    string line;
    int health;
    int armor;
    string name;
    string className;
                       
    
    
    ofstream fout ("ending_entities.txt");  //open file
    if (fout.fail()) {
        throw(1);
    }
    
    fout << " **Players** " << endl << endl;
    for (int i = 0; i < playerNum; i++) {
        fout << "Name: " << players[i].getName() << endl;
        fout << "Health: " << players[i].getHealth() << endl;
        fout << "Armor: " << players[i].getArmor() << endl;
        fout << "Class: " << players[i].getClass() << endl << endl;
    }
    
    fout << " **Monsters** " << endl << endl;
    for (int j = 0; j < monsterNum; j++) {
        fout << "Name: " << monsters[j].getName() << endl;
        fout << "Health: " << monsters[j].getHealth() << endl;
        fout << "Armor: " << monsters[j].getArmor() << endl;
        fout << "Class: " << monsters[j].getType() << endl << endl;
    }
    
    fout.close();   //close file

}


