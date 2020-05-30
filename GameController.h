#ifndef MYDOODLE_GAMECONTROLLER_H
#define MYDOODLE_GAMECONTROLLER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "StaticView.h"
#include "Jumper.h"
#include "Tiles.h"
#include "Subtitles.h"
#include "Scores.h"
#include "GameHandler.h"
#include "Manager.h"
#include "MovingTiles.h"
#include "Items.h"

// the bread and butter of the game

class GameController {
    //////////////////
    StaticView &view;
    Jumper &jumpy;
    Tiles &tile;
    MovingTiles &movingTile;
    Subtitles &sub;
    Scores &scor;
    GameHandler &handy;
    Manager &mgr;
    Items &item;
    //////////////////
    sf::Sound sound;
    sf::SoundBuffer jump;
    sf::SoundBuffer loss;
    sf::SoundBuffer rocketjump;
    sf::SoundBuffer springjump;
    ///

    // timers for rocket and spring
    float timer[2];

    // rocket variables
    float rocket_time=25;
    bool show_rocket = false;

    // spring variables
    float spring_time=15;
    bool show_spring = false;

    // how long should be rocket/spring displayed?
    int time_present = 7;

    // invisible border - if the character jump higher, the map will move down
    int border=100;

    // play loss music if its false
    bool played;

    // controls movement of the character
    void jumpyCtrl();

    // controls collision between character and tiles (static+moving)
    void collisionCtrl();

    // if the character jump higher, the map will move down and jumpy/collision included
    void mapCtrl();

    // controls state of game -
    // if running - just play
    // if loss - play music and block gameplay thereby
    void stateCtrl();

    // controls rocket/spring display, spawn and interaction with them
    void itemsCtrl(sf::RenderWindow &w1);
public:
    GameController(StaticView &v, Jumper &j, Tiles &t, MovingTiles &t1,
            Subtitles &s, Scores &sc, GameHandler &h, Manager &m, Items &i);
    void play();
};


#endif //MYDOODLE_GAMECONTROLLER_H
