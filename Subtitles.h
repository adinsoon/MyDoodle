#ifndef MYDOODLE_SUBTITLES_H
#define MYDOODLE_SUBTITLES_H
#include <SFML/Graphics.hpp>
#include "Scores.h"

class Subtitles {
    // during game
    sf::Font myFont;
    sf::Text sub_score;
    Scores &scor;

    // final results
    sf::Text yourScore;
    sf::Text score;
    sf::Text pressSpace;
    sf::Text pressEsc;
public:
    explicit Subtitles(Scores &s);

    // prepare texts to be shown
    void format();

    void drawScore(sf::RenderWindow &w1);
    void drawResults(sf::RenderWindow &w1);

};


#endif //MYDOODLE_SUBTITLES_H
