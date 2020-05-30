#ifndef MYDOODLE_MANAGER_H
#define MYDOODLE_MANAGER_H

//gameplay control

enum gameState{MENU,PLAY};

class Manager {
    gameState state;
public:
    Manager();

    // MENU - ESC pressed
    // PLAY - SPACE pressed
    void setGame(gameState g);

    // return game state
    gameState getGame() const;
};


#endif //MYDOODLE_MANAGER_H
