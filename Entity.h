#ifndef MYDOODLE_ENTITY_H
#define MYDOODLE_ENTITY_H
#include <SFML/Graphics.hpp>

// this is an abstract class with virtual methods

struct cord {
    int x;
    int y;
};

class Entity {
protected:
    Entity();
    virtual void format();
    virtual void drawMe();
};


#endif //MYDOODLE_ENTITY_H
