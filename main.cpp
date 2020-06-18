#include <iostream>
#include <SFML/Graphics.hpp>
#include "StaticView.h"
#include "Jumper.h"
#include "Tiles.h"
#include "MovingTiles.h"
#include "Subtitles.h"
#include "Scores.h"
#include "GameController.h"
#include "GameHandler.h"
#include "Manager.h"
#include "Items.h"
#include "Menu.h"

int main() {
    Manager mgr;
    do {
        ///// MENU PART
        Menu menu;
        menu.showMenu();
        do {
            ///// GAME PART
            Scores scr; // controls score during game
            StaticView view;    // controls background theme
            Jumper jumpy;   // player
            Tiles tile(scr);    // static tiles
            MovingTiles movingTile(scr);    // moving from one side to other
            Subtitles sub(scr); // controls the display of score and results
            Items items;    // special bonuses during game
            GameHandler handler(jumpy, scr);    // controls if game is finished or running
            GameController ctrl(view, jumpy, tile, movingTile,
                            sub, scr, handler, mgr, items); // game controller
            ctrl.play();
        }while(mgr.getGame() == PLAY); // SPACE pressed
    }while(mgr.getGame() == MENU); // ESC pressed
}
