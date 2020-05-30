#ifndef MYDOODLE_SCORES_H
#define MYDOODLE_SCORES_H

// SCORES ARE COUNT IN THIS WAY:
// for each jump above the set limit(border)
// add numerical jump value over the border
// if the value is greater than |1|
// then divide it by 10

class Scores {
    int score;
public:
    Scores();
    int getScore();
    void makeScore(int sc);
};


#endif //MYDOODLE_SCORES_H
