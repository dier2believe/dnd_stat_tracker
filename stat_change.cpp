/* Nicole Lord
   Liz Dieringer */
#include "entity_class.h"
#include "player_class.h"
#include "monster_class.h"
#include <vector>

void statChange(int turnNumber, vector<Entity> &orderArr) {
    char userInput;
    cout << "Did " << orderArr[turnNumber].getName() 
        << "'s health change? (y)es or (n)o: ";
    cin >> userInput;
    switch(userInput){
        case 'y':
            orderArr[turnNumber].changeHealth();
            break;
        case 'n':
            cout << "Ok. No changes made." << endl;
            break;
    }
    cout << "Did " << orderArr[turnNumber].getName() 
        << "'s armor change? (y)es or (n)o: ";
    cin >> userInput;
    switch(userInput){
        case 'y':
            orderArr[turnNumber].changeArmor();
            break;
        case 'n':
            cout << "Ok. No changes made." << endl;
            break;
    }
    orderArr[turnNumber].isDeadCheck();
}
