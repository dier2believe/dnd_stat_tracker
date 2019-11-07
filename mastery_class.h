/* Liz Dieringer 
   Xanth Rossnagle */
#include <iostream>
#include <string>
using namespace std;

#ifndef MASTERY_CPP
#define MASTERY_CPP
class Mastery {
private:
    string className;
public:
    Mastery(string name);
    ~Mastery() {}
    string getName();
    void setName(string name);
};

Mastery::Mastery(string name) {
    className = name;
}

string Mastery::getName() {
    return className;
}

void Mastery::setName(string name) {
    className = name;
}
#endif
