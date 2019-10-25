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
    void setName(string name);
};

Mastery::Mastery(string name) {
    className = name;
}

void Mastery::setName(string name) {
    className = name;
}
#endif
