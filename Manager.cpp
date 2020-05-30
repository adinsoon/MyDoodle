#include "Manager.h"

gameState Manager::getGame() const {
    return state;
}

void Manager::setGame(gameState g) {
    state = g;
}

Manager::Manager() {
    state = PLAY;
}