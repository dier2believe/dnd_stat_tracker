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
    Mastery(string clNm);
    ~Mastery() {}
};

Mastery::Mastery(string clNm) {
    className = clNm;
}
#endif
