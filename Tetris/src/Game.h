#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "raylib.h"
#include "GameConsts.h"
#include "Grid.h"

class Game {
public:
    Grid GameGrid = {kGridSize, kGridOffset};
    Grid NextGrid = {kNextGridSize, kNextGridOffset};
    int Score;

    Game();

    void HandleInput(int &hv, bool &up, bool &down);

    void CleanInput(int &hv, bool &up, bool &down);

    void Draw();

    void Restart();

private:
};

#endif //TETRIS_GAME_H
