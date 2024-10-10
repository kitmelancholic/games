#include "raylib.h"
#include "Grid.h"
#include "Block.h"
#include "GameConsts.h"
#include "Game.h"

#include <random>
#include <ctime>

double lastUpdateTime = 0;

std::mt19937 rng(static_cast<long unsigned int>(time(0)));
std::uniform_int_distribution<int> uni(0, 6);

auto *block = new Block(Vector2{0, 0}, uni(rng));
auto *nextBlock = new Block(Vector2{0, 0}, uni(rng));

int HorizontalVector = 0;
bool isRotatePressed = false;
bool isDownPressed = false;
double lastHorizontalMoveTime = 0;
double lastDownMoveTime = 0;

bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() {
    bool stoppedLastBlock = false;
    InitWindow(kWindowSize.x, kWindowSize.y, "Tetris");
    SetTargetFPS(60);

    Game game;
    nextBlock->DrawOnGrid(game.NextGrid);

    while (!WindowShouldClose()) {
        game.HandleInput(HorizontalVector, isRotatePressed, isDownPressed);
        double currentTime = GetTime();

        if (!block->IsStopped()) {
            if (isDownPressed && currentTime - lastDownMoveTime > 0.1) {
                block->UpdateMoveDown(game.GameGrid);
                lastDownMoveTime = currentTime;
            } else if (EventTriggered(0.5)) {
                block->UpdateMoveDown(game.GameGrid);
            }

            if (HorizontalVector != 0 && currentTime - lastHorizontalMoveTime > 0.1) {
                block->UpdateMoveHoriz(game.GameGrid, HorizontalVector);
                lastHorizontalMoveTime = currentTime;
            }

            if (isRotatePressed) {
                block->UpdateRotate(game.GameGrid);
            }
            block->DrawOnGrid(game.GameGrid);
        } else {
            block->DrawOnGrid(game.GameGrid);
            delete block;

            block = nextBlock;
            game.NextGrid.Clear();
            nextBlock = new Block(Vector2{0, 0}, uni(rng));
            nextBlock->DrawOnGrid(game.NextGrid);
            if (!block->InitIsAvailable(game.GameGrid)) {
                game.Restart();
            }
            stoppedLastBlock = true;
        }

        //GameGrid.Print();

        // Draw
        game.Draw();

        if (!stoppedLastBlock) {
            block->EraseFromGrid(game.GameGrid);
        } else {
            stoppedLastBlock = false;
        }
        // clean input
        game.GameGrid.CheckClearedRows(game.Score);
        game.CleanInput(HorizontalVector, isRotatePressed, isDownPressed);
    }

    delete block;
    CloseWindow();
    return 0;
}