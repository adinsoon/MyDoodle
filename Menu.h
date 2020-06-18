#ifndef MYDOODLE_MENU_H
#define MYDOODLE_MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

enum Scenes {MAIN,HOWTO};

class Menu {
    sf::Texture theme;
    sf::Sprite background;
    sf::Texture title;
    sf::Sprite titleS;
    sf::Texture playButtonOFF;
    sf::Texture playButtonON;
    sf::Texture infoButtonOFF;
    sf::Texture infoButtonON;
    sf::Texture backButtonON;
    sf::Texture backButtonOFF;
    sf::Sprite buttons[3];
    sf::SoundBuffer click;
    sf::Sound clickSound;
    sf::Texture control;
    sf::Sprite controllers;
    sf::Texture spring;
    sf::Texture rocket;
    sf::Sprite booster[2];
    void initialFormat();
    void format();
    void drawMAIN(sf::RenderWindow &w1);
    void drawHOWTO(sf::RenderWindow &w1);
    Scenes scene = MAIN;
    sf::Font font;
    sf::Text controlTxt;
    sf::Text boostersTxt;
    std::string pressKeys;
    std::string boosters;
public:
    Menu();
    void showMenu();
};


#endif //MYDOODLE_MENU_H
