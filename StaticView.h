#ifndef MYDOODLE_STATICVIEW_H
#define MYDOODLE_STATICVIEW_H
#include <SFML/Graphics.hpp>

// background

class StaticView {
    sf::Texture background;
    sf::Sprite theme;
public:
    StaticView();
    void drawTheme(sf::RenderWindow &w1);
};


#endif //MYDOODLE_STATICVIEW_H
