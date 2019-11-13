/* Liz Dieringer 
   Xanth Rossnagle */
#include <iostream>
#include <string>
using namespace std;

#ifndef MASTERY_CPP
#define MASTERY_CPP
// class for the player class (normally called class in dnd)
class Mastery {
private:
    string className;
public:
    Mastery(string name);
    ~Mastery() {}
    string getName();
    void setName(string name);
};

// constructor
Mastery::Mastery(string name) {
    className = name;
}

// function to get the name
string Mastery::getName() {
    return className;
}

// function to set the name
void Mastery::setName(string name) {
    className = name;
}
#endif
