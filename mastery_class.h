/* Liz Dieringer 
   Xanth Rossnagle */
#include <iostream>
#include <string>
#include "entity.h"
using namespace std;

#ifndef MASTERY_CPP
#define MASTERY_CPP
class Mastery {
private:
    string className;
public:
    Mastery();
}

Mastery::Mastery() {
    cout << "What's this character's class? ";
    cin >> className;
}
#endif
