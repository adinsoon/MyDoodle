#include "Items.h"
#include <iostream>

Items::Items() {
    png_rocket.loadFromFile("..\\icons\\rocket.png");
    png_spring.loadFromFile("..\\icons\\spring.png");
    format();
}

void Items::drawMe(const std::string& what, sf::RenderWindow &w1) {
    if(what == "rocket")
        w1.draw(rocket);
    if(what == "spring")
        w1.draw(spring);
}

void Items::format() {
    rocket.setTexture(png_rocket);
    spring.setTexture(png_spring);
    rocket.setScale(0.1,0.1);
    spring.setScale(0.2,0.2);
}

void Items::spawn(const std::string& what) {
    if(what == "rocket") {
        rockets.x = rockets.y = 0;
        rockets.x = rand()%400;
        rockets.y = (-(rand()%600));
        rocket.setPosition(rockets.x, rockets.y);
    }
    if(what == "spring"){
        springs.x = springs.y = 0;
        springs.x = rand()%400;
        springs.y = (-(rand()%600));
        spring.setPosition(springs.x, springs.y);
    }
}

void Items::despawn(const std::string& what) {
    if(what == "rocket"){
        rocket.setPosition(-500,-500);
    }
    if(what == "spring"){
        spring.setPosition(-500,-500);
    }
}

void Items::move(const std::string& what, float n) {
    if(what == "rocket"){
        rockets.x = rockets.x;
        rockets.y = rockets.y-n;
        rocket.setPosition(rockets.x, rockets.y);
    }
    if(what == "spring"){
        springs.x = springs.x;
        springs.y = springs.y-n;
        spring.setPosition(springs.x, springs.y);
    }
}

sf::Rect<float> Items::getItemPos(const std::string& what) {
    if(what == "rocket")
        return rocket.getGlobalBounds();
    if(what == "spring")
        return spring.getGlobalBounds();
}

