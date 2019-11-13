/* Xanth Rossnagle
   Liz Dieringer */
#include <iostream>
#include <string>
using namespace std;

#ifndef TYPES_CPP
#define TYPES_CPP
// class for the monster type
class Types {
private:
    string typeName;
public:
    Types(string name);
    ~Types() {}
    void setName(string name);
    string getName();
};

// constructor
Types::Types(string name) {
    typeName = name;
}

// function to set the name
void Types::setName(string name) {
    typeName = name;
}

// function to get the name
string Types::getName() {
    return typeName;
}
#endif
