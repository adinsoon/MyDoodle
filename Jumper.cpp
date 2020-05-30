#include "Jumper.h"
#include <iostream>

Jumper::Jumper() {
    studentJumper.loadFromFile("..\\icons\\jumper.png");
    position.x = 170;
    position.y = 500;
    format();
}

void Jumper::drawMe(sf::RenderWindow &w1) {
    w1.draw(character);
}

void Jumper::format() {
    character.setTexture(studentJumper);
    character.setScale(0.1,0.1);
    character.setPosition(position.x,position.y);
}

void Jumper::move(int x) {
    position.x += x;
}

void Jumper::jump() {
    control.dCol += 0.2;
    position.y += control.dCol;
    if(position.y > 540)
        setJumpHeight(-8);
    character.setPosition(position.x,position.y);
    if(position.x < 0) {
        position.x = 400;
    }
    else if(position.x > 400) {
        position.x = 0;
    }
}

float Jumper::getJumpHeight() const {
    return control.dCol;
}

void Jumper::setJumpHeight(float n) {
    control.dCol = n;
}


sf::Rect<float> Jumper::getJumperPos() const {
    return character.getGlobalBounds();
}

int Jumper::getJumpRow() const {
    return position.x;
}

int Jumper::getJumpCol() const {
    return position.y;
}

void Jumper::setJumpCol(int n) {
    position.y = n;
}

