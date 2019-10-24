#include <iostream>
#include <string>
using namespace std;

void setupPlayers(int playerNum, Player **players) {
    for(int i = 0; i <= playerNum; i++) {
        int hea;
        int arm;
        string nam;
        cout << "What is the player's name? ";
        cin >> nam;
        cout << "How much health does " << nam << " have? ";
        cin >> hea;
        cout << "How much armor does " << nam << " have? ";
        cin >> arm;
        (*players)[i].setValues(hea, arm, nam);
    }
}
