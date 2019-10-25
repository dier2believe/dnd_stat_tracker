/* Xanth Rossnagle
   Liz Dieringer */
#include <iostream>
#include <string>
using namespace std;

#ifndef TYPES_CPP
#define TYPES_CPP

class Types {
private:
    string typeName;
public:
    Types(string name);
    ~Types() {}
    void setName(string name);
};

Types::Types(string name) {
    typeName = name;
}

void Types::setName(string name) {
    typeName = name;
}
#endif
