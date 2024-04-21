#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "raylib.h"
#include "Grid.h"

class Game {
public:
    Grid GameGrid;

    Game();

    void HandleInput(int &hv, bool &up, bool &down);

    void CleanInput(int &hv, bool &up, bool &down);

    void Draw();

    ~Game();

private:
};

#endif //TETRIS_GAME_H
