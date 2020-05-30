#include "Tiles.h"
#include <iostream>
#include <ctime>

void set_time() {
    srand(time(NULL));
}

Tiles::Tiles(Scores &s) : scr(s){
    set_time();
    tile.loadFromFile("..\\icons\\tile.png");
    format();
}

void Tiles::drawMe(int n, sf::RenderWindow &w1) {
    w1.draw(tiles[n]);
}

void Tiles::format(){
    for(int i=0;i<tilesQ;i++) {
        tiles[i].setScale(0.4, 0.2);
        tiles[i].setTexture(tile);
        plats[i].x = position[i].x = rand()%370;
        int placeholder = (540/(tilesQ-2))*i;
        plats[i].y = position[i].y = rand()%1+placeholder;
        tiles[i].setPosition(plats[i].x, plats[i].y);
    }
}

int Tiles::getTilesCount() const {
    return tilesQ;
}

int Tiles::getTileRow(int n) const {
    return position[n].x;
}

int Tiles::getTileCol(int n) const {
    return position[n].y;
}

sf::Rect<float> Tiles::getTileSize(int n) const {
    return tiles[n].getGlobalBounds();
}

void Tiles::move(int i, float n) {
    position[i].x = plats[i].x;
    position[i].y = plats[i].y = plats[i].y-n;
    tiles[i].setPosition(plats[i].x,plats[i].y);
}

bool Tiles::isOutside(int i, int height) const{
    return plats[i].y > height;
}

void Tiles::relocate(int i) {
    position[i].y = plats[i].y = -(rand()%20);
    position[i].x = plats[i].x = rand()%370;
    tiles[i].setPosition(plats[i].x,plats[i].y);
}

void Tiles::reduce() {
    if((scr.getScore()/10) > (scoreStaticLimit * scoreStaticCap) && tilesQ > 2) {
        tilesQ--;
        scoreStaticLimit++;
    }
}

bool Tiles::isStaticCaseGood() const {
    return (scr.getScore() / 10) > (scoreStaticLimit * scoreStaticCap);
}




