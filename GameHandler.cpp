#include "GameHandler.h"

State GameHandler::getGameState() {
    if(scor.getScore() == 0)
        return STARTED;
    else if(scor.getScore() > 0 && jumpy.getJumpCol() >= 540)
        return LOSS;
    else
        return RUNNING;
}

GameHandler::GameHandler(Jumper &j, Scores &s): jumpy(j), scor(s){

}
