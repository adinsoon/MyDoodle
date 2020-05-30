#ifndef MYDOODLE_MOVINGTILES_H
#define MYDOODLE_MOVINGTILES_H
#include "Tiles.h"

struct movementTiles {
    float dRow=0;       // horizontal movement
};

class MovingTiles : public Tiles {
    // max quantity of moving tiles
    const static int maxMovingTiles = 8;

    // current quantity of moving tiles
    int movingTilesQ=1;

    sf::Texture mover;
    sf::Sprite moveTiles[maxMovingTiles];

    // current movement positions
    cord movePos[maxMovingTiles];

    // position during spawn
    cord spawnPos[maxMovingTiles];

    // for horizontal movement
    movementTiles control[maxMovingTiles];

    // controls movement left and right
    bool direction = true;

    // controls how often and how much moving tiles should be spawned during game
    // 1 * 1000 = so at 1000 points a new moving tile will spawn, then 2000 is the new cap and etc
    int scoreMovingLimit = 1;
    int scoreMovingCap = 1000;
public:
    MovingTiles(Scores &s);

    // prepare sprites to be drawn
    void format() override;

    // controls movement of given n-tile
    void horizontalMove(int n);

    void drawMe(int n, sf::RenderWindow &w1);

    // if the character jump higher, the n-tile will move down
    void move(int i, float n) override;

    // return true if n-tile is outside the map
    bool isOutside(int i, int height) const override;

    // re-spawn n-tile
    void relocate(int i, int border);

    // return current quantity of tiles on the map
    int getTilesCount() const override;

    // return positions of n-tile
    int getTileRow(int n) const override;
    int getTileCol(int n) const override;

    // check if the condition is true and if so, increase the quantity of tiles on map
    void grow();
};


#endif //MYDOODLE_MOVINGTILES_H
