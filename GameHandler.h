#ifndef MYDOODLE_GAMEHANDLER_H
#define MYDOODLE_GAMEHANDLER_H
#include "Jumper.h"
#include "Scores.h"

// controls state of game -

enum State {STARTED,RUNNING,LOSS};

class GameHandler {
    Jumper &jumpy;
    Scores &scor;
public:
    explicit GameHandler(Jumper &j, Scores &s);
    State getGameState();
};


#endif //MYDOODLE_GAMEHANDLER_H
