/* Liz Dieringer */
#include "player_class.h"
#include "mastery_class.h"

// setup the players if the file input did not work
void setupPlayers(int playerNum, Player **players) {
    // set up the variables to keep track of the user input
    int hea;
    int arm;
    string nam;
    string className;
    
    // ask the user for each value and create the player
    for(int i = 0; i < playerNum; i++) {
        cout << "What is the player's name? ";
        cin >> nam;
        cout << "How much health does " << nam << " have? ";
        cin >> hea;
        cout << "How much armor does " << nam << " have? ";
        cin >> arm;
        cout << "What is " << nam << "'s class? ";
        cin >> className;
        cout << endl;
        
        (*players)[i].setValues(hea, arm, nam, className, 0);
    }
}
