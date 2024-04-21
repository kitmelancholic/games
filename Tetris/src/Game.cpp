#include "Game.h"
#include "raylib.h"
#include "GameConsts.h"

Game::Game() {
    Score = 0;
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
    DrawText("INCOMING:", kFirstTextBoxOffset.x, kFirstTextBoxOffset.y, 10, GRAY);
    DrawText(TextFormat("LINES:      %04i", Score), kSecondTextBoxOffset.x, kSecondTextBoxOffset.y, 10, GRAY);
    NextGrid.Draw();
    GameGrid.Draw();
    EndDrawing();
}

void Game::Restart() {
    GameGrid.Clear();
    Score = 0;
}