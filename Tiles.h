#ifndef MYDOODLE_TILES_H
#define MYDOODLE_TILES_H
#include <SFML/Graphics.hpp>
#include "Scores.h"
#include "Entity.h"

class Tiles : public Entity{
protected:
    // max quantity of static tiles
    const static int maxStaticTiles = 20;

    // current quantity of static tiles
    int tilesQ = 12;

    // coordinators of tiles
    cord plats[maxStaticTiles];
    cord position[maxStaticTiles];

    sf::Texture tile;
    sf::Sprite tiles[maxStaticTiles];

    Scores &scr;

    // controls how often and how much moving tiles should be spawned during game
    // 1 * 1000 = so at 1000 points a new moving tile will spawn, then 2000 is the new cap and etc
    int scoreStaticLimit = 1;
    int scoreStaticCap = 1000;
public:
    Tiles(Scores &s);

    // prepare sprites to be drawn
    void format() override;

    virtual void drawMe(int n, sf::RenderWindow &w1);

    // return current quantity of tiles on the map
    virtual int getTilesCount() const;

    // return positions of n-tile
    virtual int getTileRow(int n) const;
    virtual int getTileCol(int n) const;

    // return coordinators of n-tile relative to window
    sf::Rect<float> getTileSize(int n) const;

    // check if the condition is true and if so, reduce the quantity of tiles on map
    void reduce();

    // if the character jump higher, the n-tile will move down
    virtual void move(int i,float n);

    // return true if n-tile is outside the map
    virtual bool isOutside(int i, int height) const;

    // re-spawn n-tile
    virtual void relocate(int i);

    // if case for spawning is correct return true
    bool isStaticCaseGood() const;
};


#endif //MYDOODLE_TILES_H
