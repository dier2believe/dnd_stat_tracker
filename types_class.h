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
    Types(string tynm);
    ~Types() {}
};

Types::Types(string tynm) {
    typeName = tynm;
}
#endif
