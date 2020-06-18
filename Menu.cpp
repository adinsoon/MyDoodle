#include "Menu.h"

Menu::Menu() {
    theme.loadFromFile("..\\icons\\theme.png");
    title.loadFromFile("..\\icons\\title.png");
    playButtonOFF.loadFromFile("..\\icons\\playBUTTON.png");
    playButtonON.loadFromFile("..\\icons\\playBUTTONon.png");
    infoButtonOFF.loadFromFile("..\\icons\\infoBUTTON.png");
    infoButtonON.loadFromFile("..\\icons\\infoBUTTONon.png");
    backButtonON.loadFromFile("..\\icons\\returnON.png");
    backButtonOFF.loadFromFile("..\\icons\\returnOFF.png");
    click.loadFromFile("..\\sounds\\click.ogg");
    control.loadFromFile("..\\icons\\wsad.png");
    font.loadFromFile("..\\font\\COMIC.TTF");
    spring.loadFromFile("..\\icons\\spring.png");
    rocket.loadFromFile("..\\icons\\rocket.png");
    initialFormat();

}

void Menu::showMenu() {
    constexpr int scr_height = 400;
    constexpr int scr_width = 400;
    std::string textTitle = "Play MyDoodle!";
    sf::RenderWindow MenuWindow(sf::VideoMode(scr_width, scr_height), textTitle);
    while(MenuWindow.isOpen()){
        sf::Event e{};
        while (MenuWindow.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                exit(0);
            else if(scene == MAIN){
                if(e.type == sf::Event::MouseButtonPressed){
                    if(e.mouseButton.button == sf::Mouse::Left){
                        sf::Vector2i mouse_pos = sf::Mouse::getPosition(MenuWindow);
                        if(buttons[0].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_pos))) {
                            clickSound.play();
                            MenuWindow.close();
                        }
                        if(buttons[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_pos))) {
                            clickSound.play();
                            scene = HOWTO;
                        }
                    }
                }
            }
            else if(scene == HOWTO){
                if(e.type == sf::Event::MouseButtonPressed) {
                    if (e.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_pos = sf::Mouse::getPosition(MenuWindow);
                        if (buttons[2].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_pos))) {
                            clickSound.play();
                            scene = MAIN;
                        }
                    }
                }
            }
        }
        drawMAIN(MenuWindow);
        drawHOWTO(MenuWindow);
    }
}

void Menu::initialFormat() {
    clickSound.setBuffer(click);
    titleS.setTexture(title);
    buttons[0].setPosition(160,170);
    buttons[1].setPosition(115,270);
    buttons[2].setPosition(355,10);
    buttons[2].setScale(0.4,0.4);
    titleS.setPosition(100,50);
    controllers.setTexture(control);
    controllers.setScale(0.8,0.8);
    controllers.setPosition(70,50);
    pressKeys = "Use WSAD or ARROWS to move";
    controlTxt.setString(pressKeys);
    controlTxt.setFillColor(sf::Color::Black);
    controlTxt.setCharacterSize(17);
    controlTxt.setFont(font);
    controlTxt.setPosition(70,170);
    boosters = "Gain a small boost by jumping on";
    boostersTxt.setString(boosters);
    boostersTxt.setFillColor(sf::Color::Black);
    boostersTxt.setCharacterSize(17);
    boostersTxt.setFont(font);
    boostersTxt.setPosition(70,350);
    booster[0].setTexture(spring);
    booster[0].setScale(0.4,0.4);
    booster[0].setPosition(70,240);
    booster[1].setTexture(rocket);
    booster[1].setScale(0.2,0.2);
    booster[1].setPosition(200,240);
}

void Menu::format() {
    buttons[0].setTexture(playButtonOFF);
    buttons[1].setTexture(infoButtonOFF);
    buttons[2].setTexture(backButtonOFF);
}

void Menu::drawMAIN(sf::RenderWindow &w1) {
    if(scene == MAIN) {
        background.setTexture(theme);
        format();
        w1.clear(sf::Color::Black);
        w1.draw(background);
        w1.draw(titleS);
        for (int i = 0; i < 2; i++) {
            w1.draw(buttons[i]);
        }
        sf::Vector2i mouse_poss = sf::Mouse::getPosition(w1);
        if (buttons[0].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_poss))) {
            buttons[0].setTexture(playButtonON);
            w1.draw(buttons[0]);
        }
        if (buttons[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_poss))) {
            buttons[1].setTexture(infoButtonON);
            w1.draw(buttons[1]);
        }
        w1.display();
    }
}

void Menu::drawHOWTO(sf::RenderWindow &w1) {
    if(scene == HOWTO) {
        background.setTexture(theme);
        format();
        w1.clear(sf::Color::Black);
        w1.draw(background);
        w1.draw(buttons[2]);
        sf::Vector2i mouse_poss = sf::Mouse::getPosition(w1);
        if (buttons[2].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_poss))) {
            buttons[2].setTexture(backButtonON);
            w1.draw(buttons[2]);
        }
        w1.draw(controllers);
        w1.draw(controlTxt);
        w1.draw(boostersTxt);
        w1.draw(booster[0]);
        w1.draw(booster[1]);
        w1.display();
    }
}
