#include "Game.h"
#include "raylib.h"

Game::Game() {
}

void Game::HandleInput(int &hv, bool &up, bool &down) {
    if (IsKeyDown(KEY_LEFT)) {
        hv = -1;
    } else if (IsKeyDown(KEY_RIGHT)) {
        hv = 1;
    } else {
        hv = 0;
    }

    down = IsKeyDown(KEY_DOWN);
    up = IsKeyPressed(KEY_UP);
}


void Game::CleanInput(int &hv, bool &up, bool &down) {
    hv = 0;
    up = false;
    down = false;
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    GameGrid.Draw();
    EndDrawing();
}

Game::~Game() {
    //delete block;
}


