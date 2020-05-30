#ifndef MYDOODLE_ITEMS_H
#define MYDOODLE_ITEMS_H
#include "SFML/Graphics.hpp"
#include <string>

struct items_cords {
    int x;
    int y;
};

class Items {
    // rocket
    sf::Texture png_rocket;
    items_cords rockets;

    // spring
    sf::Texture png_spring;
    items_cords springs;
public:
    sf::Sprite spring;
    sf::Sprite rocket;

    Items();

    // draw rocket or spring depending on provided string
    void drawMe(std::string what, sf::RenderWindow &w1);

    // prepare sprites to be drawn
    void format();

    // put it on the map but don't draw
    void spawn(std::string what);

    // move down if character jumps up
    void move(std::string what, float n);

    // return current position relative to window
    sf::Rect<float> getItemPos(std::string what);
};


#endif //MYDOODLE_ITEMS_H
