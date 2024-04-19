#include "raylib.h"

int kScreenWidth = 720;
int kScreenHeight = 1280;

int main() {

    InitWindow(kScreenWidth, kScreenHeight, "Tetris");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Update

        // Draw
        BeginDrawing();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
