/* Liz Dieringer */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "player_class.h"
#include "monster_class.h"
using namespace std;

void importEntities(int playerNum, int monsterNum, Player **players, Monster **monsters) {
    string line;
    int health;
    int armor;
    string name;
    string className;
                       
    
    
    ifstream fin ("starting_entities.txt");  //open file
    if (fin.fail()) {
        throw(1);
    }
    
    for (int i = 0; i < playerNum; i++) {
        fin >> line;
        fin >> name;
        fin >> line;
        fin >> health;
        fin >> line;
        fin >> armor;
        fin >> line;
        fin >> className;
        (*players)[i].setValues(health, armor, name, className, 0);
    }
    
    for (int j = 0; j < monsterNum; j++) {
        fin >> line;  //read from file(up to space)
        fin >> name;
        fin >> line;
        fin >> health;
        fin >> line;
        fin >> armor;
        fin >> line;
        fin >> className;
        (*monsters)[j].setValues(health, armor, name, className);
    }
    
    fin.close();   //close file

}



