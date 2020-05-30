#include <iostream>
#include "MovingTiles.h"
#include <ctime>

void set_timeMove() {
    srand(time(NULL));
}

MovingTiles::MovingTiles(Scores &s) : Tiles(s) {
    set_timeMove();
    mover.loadFromFile("..\\icons\\moving.png");
    format();
}

void MovingTiles::format() {
    for (int i = 0; i < maxMovingTiles; i++) {
        moveTiles[i].setScale(0.4, 0.2);
        moveTiles[i].setTexture(mover);
        movePos[i].x = spawnPos[i].x = rand()%350;
        int placeholder = (540/tilesQ)*i;
        movePos[i].y = spawnPos[i].y = rand()%1+placeholder;
        //moveTiles[i].setPosition(movePos[i].x,movePos[i].y);
    }
}

void MovingTiles::drawMe(int n, sf::RenderWindow &w1) {
    if(isStaticCaseGood())
        w1.draw(moveTiles[n]);
}

void MovingTiles::horizontalMove(int n) {
    if(isStaticCaseGood()) {
        if (direction) {
            if (control[n].dRow < 2) control[n].dRow += 0.025;
            movePos[n].x += control[n].dRow;
        } else if (!direction) {
            if (control[n].dRow > -2) control[n].dRow -= 0.025;
            movePos[n].x += control[n].dRow;
        }
        if (100 > movePos[n].x) {
            direction = true;
            control[n].dRow += 0.025;
        } else if (300 < movePos[n].x) {
            direction = false;
            control[n].dRow -= 0.025;
        }
        moveTiles[n].setPosition(movePos[n].x, movePos[n].y);
    }
}

int MovingTiles::getTileRow(int n) const {
    return movePos[n].x;
}

void MovingTiles::move(int i, float n) {
    if(isStaticCaseGood()) {
        movePos[i].x = movePos[i].x;
        movePos[i].y = movePos[i].y - n;
        moveTiles[i].setPosition(movePos[i].x, movePos[i].y);
    }
}

bool MovingTiles::isOutside(int i, int height) const {
    return movePos[i].y > height;
}

void MovingTiles::relocate(int i, int border) {
    if(isStaticCaseGood()) {
        control[i].dRow = 0;
        movePos[i].x = 0;
        spawnPos[i].x = 0;
        movePos[i].y = -(rand() % border);
        movePos[i].x = spawnPos[i].x = rand() % 370;
        moveTiles[i].setPosition(movePos[i].x, movePos[i].y);
    }
}

int MovingTiles::getTilesCount() const {
    return movingTilesQ;
}

int MovingTiles::getTileCol(int n) const {
    return movePos[n].y;
}

void MovingTiles::grow() {
    if((scr.getScore()/10) > (scoreMovingLimit * scoreMovingCap) && movingTilesQ < maxMovingTiles) {
        movingTilesQ++;
        scoreMovingLimit++;
    }
}
