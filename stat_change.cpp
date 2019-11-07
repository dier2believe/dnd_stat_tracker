/* Nicole Lord
   Liz Dieringer */
#include "entity_class.h"
#include "player_class.h"
#include "monster_class.h"
#include <vector>

//This is the function that handles any status changes to the health or armor of an entity
void statChange(int turnNumber, vector<Entity*> &orderArr) {
    char userInput;
    //Asking if the entity in the order lost/gained health
    cout << "Did " << orderArr[turnNumber]->getName() 
        << "'s health change? (y)es or (n)o: ";
    cin >> userInput;
    switch(userInput){
        case 'y':
            //If health did change, it calls the changeHealth function in the Entity class
            orderArr[turnNumber]->changeHealth();
            break;
        case 'n':
            cout << "Ok. No changes made." << endl;
            break;
    }
    //Asking if the entity in the order lost/gained armor
    cout << "Did " << orderArr[turnNumber]->getName() 
        << "'s armor change? (y)es or (n)o: ";
    cin >> userInput;
    switch(userInput){
        case 'y':
            //If armor did change, it calls the changeHealth function in the Entity class
            orderArr[turnNumber]->changeArmor();
            break;
        case 'n':
            cout << "Ok. No changes made." << endl;
            break;
    }
    //After status changes the function calls the isDeadCheck function to see if the entity has no health and in turn is dead.
    orderArr[turnNumber]->isDeadCheck();
}
