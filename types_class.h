/* Xanth Rossnagle
   Liz Dieringer */
#include <iostream>
#include <string>
#include "entity_class.h"
using namespace std;

#ifndef TYPES_CPP
#define TYPES_CPP

class Types {
private:
    string typeName;
public:
    void Types();
}

Types::Types() {
    cout << "What type is the monster? ";
    cin >> typeName;
}
#endif
