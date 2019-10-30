//Nicole Lord
#include "player_class.h"
#include "monster_class.h"
#include <vector>

void statChange(int turnNumber, vector **orderArr) {
    char userInput;
    cout << "Did " << (*orderArr)[turnNumber].getName() 
        << " health change? (y) for yes and (n) for no";
    cin >> userInput;
    switch(userInput){
        case 'y':
            (*orderArr)[turnNumber].changeHealth();
            break;
        case 'n':
            cout << "Ok. No changes made." << endl;
            break;
    }
    cout << "Did " << (*orderArr)[turnNumber].getName() 
        << " armor change? (y) for yes and (n) for no";
    cin >> userInput;
    switch(userInput){
        case 'y':
            (*orderArr)[turnNumber].changeArmor();
            break;
        case 'n':
            cout << "Ok. No changes made." << endl;
            break;
    }
}