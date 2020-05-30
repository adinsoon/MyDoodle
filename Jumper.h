#ifndef MYDOODLE_JUMPER_H
#define MYDOODLE_JUMPER_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Entity.h"

struct movement {
    float dCol=0; // how high character jumps
};

class Jumper : public Entity{
    sf::Texture studentJumper;
    sf::Sprite character;

    // from base class
    cord position;
    movement control;
public:
    Jumper();

    // prepare sprite to be drawn
    void format() override;

    void drawMe(sf::RenderWindow &w1);

    void jump();

    // move left or right
    void move(int x);

    // return how high character jumps currently
    float getJumpHeight() const;

    // set how high character jumps
    void setJumpHeight(float n);

    // set jump position Y axis
    void setJumpCol(int n);

    // get jump X axis
    int getJumpRow() const;
    // get jump Y axis
    int getJumpCol() const;

    // return current position relative to window
    sf::Rect<float> getJumperPos() const;

};


#endif //MYDOODLE_JUMPER_H
