#include "GameController.h"
#include <iostream>

GameController::GameController(StaticView &v, Jumper &j, Tiles &t, MovingTiles &t1,
        Subtitles &s, Scores &sc, GameHandler &h, Manager &m, Items &i)
: view(v), jumpy(j), tile(t), movingTile(t1), sub(s), scor(sc), handy(h), mgr(m), item(i) {
    jump.loadFromFile("..\\sounds\\jump.ogg");
    loss.loadFromFile("..\\sounds\\loss.ogg");
    rocketjump.loadFromFile("..\\sounds\\rocketjump.ogg");
    springjump.loadFromFile("..\\sounds\\springjump.ogg");
    played = false;
    timer[0] = 0;
    timer[1] = 0;
}

void GameController::play() {
    constexpr int scr_height = 540;
    constexpr int scr_width = 400;
    sound.setBuffer(jump);
    std::string title = "Play MyDoodle!";
    sf::Clock clock;
    sf::RenderWindow GameWindow(sf::VideoMode(scr_width, scr_height), title);
    GameWindow.setFramerateLimit(100);
    while (GameWindow.isOpen()) {
        sf::Event e{};
        while (GameWindow.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                exit(0);
            if (handy.getGameState() == LOSS) {
                if (e.type == sf::Event::KeyPressed && (e.key.code == sf::Keyboard::Space)) {
                    mgr.setGame(PLAY);
                    GameWindow.close();
                } else if (e.type == sf::Event::KeyPressed && (e.key.code == sf::Keyboard::Escape)) {
                    mgr.setGame(MENU);
                    GameWindow.close();
                }
            }
        }
        GameWindow.clear();
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer[0] += time;
        timer[1] += time;
        stateCtrl();
        view.drawTheme(GameWindow);
        jumpy.drawMe(GameWindow);
        for (int i = 0; i < tile.getTilesCount(); ++i) {
            tile.drawMe(i, GameWindow);
        }
        itemsCtrl(GameWindow);
        for (int i = 0; i < movingTile.getTilesCount(); ++i) {
            movingTile.drawMe(i, GameWindow);
        }
        sub.drawScore(GameWindow);
        if (handy.getGameState() == LOSS) {
            sub.drawResults(GameWindow);
        }
        GameWindow.display();
    }
}



void GameController::jumpyCtrl() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) jumpy.move(3);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) jumpy.move(-3);
    jumpy.jump();
}

void GameController::collisionCtrl() {
    for(int i=0;i<tile.getTilesCount();++i) {
        if ((jumpy.getJumpRow() + jumpy.getJumperPos().width - 20 > tile.getTileRow(i)) &&
            (jumpy.getJumpRow() + 20 < tile.getTileRow(i) + tile.getTileSize(i).width) &&
            (jumpy.getJumpCol() + jumpy.getJumperPos().height + 10 > tile.getTileCol(i)) &&
            (jumpy.getJumpCol() + jumpy.getJumperPos().height + 20 < tile.getTileCol(i) + 40 &&
             (jumpy.getJumpHeight() > 0))) {
            jumpy.setJumpHeight(-9);
            sound.setBuffer(jump);
            sound.play();
        }
    }
    for(int i=0;i<movingTile.getTilesCount();++i){
        if((jumpy.getJumpRow() + jumpy.getJumperPos().width - 20 > movingTile.getTileRow(i)) &&
           (jumpy.getJumpRow()+20<movingTile.getTileRow(i)+movingTile.getTileSize(i).width) &&
           (jumpy.getJumpCol() + jumpy.getJumperPos().height + 10 > movingTile.getTileCol(i)) &&
           (jumpy.getJumpCol() + jumpy.getJumperPos().height + 20 < movingTile.getTileCol(i) + 40 &&
            (jumpy.getJumpHeight() > 0))) {
            jumpy.setJumpHeight(-9);
            sound.setBuffer(jump);
            sound.play();
        }
    }
}

void GameController::mapCtrl() {
    if(jumpy.getJumpCol() < border) {
        scor.makeScore(jumpy.getJumpHeight());
        jumpy.setJumpCol(border);
        for (int i = 0; i < tile.getTilesCount(); ++i) {
            tile.move(i,jumpy.getJumpHeight());
            if(tile.isOutside(i,540)){
                tile.relocate(i);
            }
        }
        jumpy.setJumpCol(border);
        item.move("rocket", jumpy.getJumpHeight());
        item.move("spring", jumpy.getJumpHeight());
        for(int i=0; i < movingTile.getTilesCount(); i++){
            movingTile.move(i, jumpy.getJumpHeight());
            if(movingTile.isOutside(i, 540)) {
                movingTile.relocate(i, border);
            }
        }
    }
    movingTile.grow();
    tile.reduce();
}

void GameController::stateCtrl() {
    if(handy.getGameState() != LOSS) {
        collisionCtrl();
        jumpyCtrl();
        mapCtrl();
        for(int i=0; i < movingTile.getTilesCount(); ++i) {
            movingTile.horizontalMove(i);
        }
    }
    if(handy.getGameState() == LOSS){
        if(!played){
            sound.setBuffer(loss);
            sound.play();
            played = true;
        }
    }
}

void GameController::itemsCtrl(sf::RenderWindow &w1) {
    if(handy.getGameState() != LOSS) {
        if (rocket_time < timer[0]) {
            show_rocket = true;
            item.spawn("rocket");
            timer[0] = 0;
        } else if (spring_time < timer[1]) {
            show_spring = true;
            item.spawn("spring");
            timer[1] = 0;
        }
        if (show_rocket && timer[0] < time_present) {
            item.drawMe("rocket", w1);
        } else if (show_spring && timer[1] < time_present) {
            item.drawMe("spring", w1);
        }
        if (show_rocket && timer[0] > time_present) {
            item.despawn("rocket");
        } else if (show_spring && timer[1] > time_present) {
            item.despawn("spring");
        }
        if (jumpy.getJumperPos().intersects(item.getItemPos("rocket"))) {
            sound.setBuffer(rocketjump);
            sound.play();
            jumpy.setJumpHeight(-32);
        }
        if (jumpy.getJumperPos().intersects(item.getItemPos("spring"))) {
            sound.setBuffer(springjump);
            sound.play();
            jumpy.setJumpHeight(-15);
        }
    }
}

