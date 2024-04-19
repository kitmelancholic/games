#include "raylib.h"
#include "Grid.h"
#include "GameConsts.h"

Grid GameGrid;

void Init() {
    InitWindow(kWindowSize.x, kWindowSize.y, "Tetris");
    SetTargetFPS(60);
}

void GameCycle() {
    while (!WindowShouldClose()) {
        // Update

        //GameGrid.Print();

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            GameGrid.Draw();
        EndDrawing();
    }
}

void Close() {
    CloseWindow();
}

int main() {
    Init();
    GameCycle();
    Close();
    return 0;
}
