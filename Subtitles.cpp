#include "Subtitles.h"

Subtitles::Subtitles(Scores &s) : scor(s) {
    myFont.loadFromFile("..\\font\\COMIC.TTF");
    score.setString(" ");
    format();
}

void Subtitles::drawScore(sf::RenderWindow &w1) {
    sub_score.setString(std::to_string(scor.getScore()/10));
    w1.draw(sub_score);
}

void Subtitles::format() {
    sub_score.setFont(myFont);
    sub_score.setFillColor(sf::Color::Black);
    sub_score.setCharacterSize(15);

    yourScore.setString("Your score:");
    pressEsc.setString("Go to MENU - press ESC");
    pressSpace.setString("Play Again - press SPACE");
    yourScore.setFillColor(sf::Color::Black);
    pressEsc.setFillColor(sf::Color::Black);
    pressSpace.setFillColor(sf::Color::Black);
    yourScore.setCharacterSize(25);
    pressSpace.setCharacterSize(20);
    pressEsc.setCharacterSize(20);
    yourScore.setFont(myFont);
    pressEsc.setFont(myFont);
    pressSpace.setFont(myFont);
    yourScore.setPosition(95,210);
    pressSpace.setPosition(80,270);
    pressEsc.setPosition(80,310);
    score.setFont(myFont);
    score.setFillColor(sf::Color::Black);
    score.setCharacterSize(25);
    score.setPosition(250,210);
}

void Subtitles::drawResults(sf::RenderWindow &w1) {
    score.setString(std::to_string(scor.getScore()/10));
    w1.draw(yourScore);
    w1.draw(pressSpace);
    w1.draw(pressEsc);
    w1.draw(score);
}

