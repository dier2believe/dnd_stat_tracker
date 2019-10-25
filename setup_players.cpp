/* Liz Dieringer */
#include "player_class.h"
#include "mastery_class.h"

void setupPlayers(int playerNum, Player **players) {
    int hea;
    int arm;
    string nam;
    string className;
        
    for(int i = 0; i < playerNum; i++) {
        cout << "What is the player's name? ";
        cin >> nam;
        cout << "How much health does " << nam << " have? ";
        cin >> hea;
        cout << "How much armor does " << nam << " have? ";
        cin >> arm;
        cout << "What is " << nam << "'s class? ";
        cin >> className;
        
        (*players)[i].setValues(hea, arm, nam, className, 0);
    }
}
