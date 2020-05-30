#include "Scores.h"
#include <SFML/Graphics.hpp>

int Scores::getScore() {
    return score;
}

void Scores::makeScore(int sc) {
    if(sc < -1)
        score += abs(sc);
}

Scores::Scores() {
    score=0;
}
