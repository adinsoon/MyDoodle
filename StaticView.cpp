#include "StaticView.h"

StaticView::StaticView() {
    background.loadFromFile("..\\icons\\theme.png");
}

void StaticView::drawTheme(sf::RenderWindow &w1) {
    theme.setTexture(background);
    w1.draw(theme);
}
