/* Liz Dieringer */
#include "entity_class.h"
#include "types_class.h"

#ifndef MONSTER_CPP
#define MONSTER_CPP
class Monster : public Entity {
private:
    Types type;
public:
    Monster(int = 10, int = 10, string = "unknown", string = "unknown");
    void setValues(int = 10, int = 10, string = "unknown", string = "unknown");
    ~Monster() {}
};

Monster::Monster(int hea, int arm, string nam, string typeName):type(typeName) {
    health = hea;
    armor = arm;
    name = nam;
}

void Monster::setValues(int hea, int arm, string nam, string typeName) {
    health = hea;
    armor = arm;
    name = nam;
    type.setName(typeName);
}
#endif
