#include "Grid.h"
#include "raylib.h"
#include "iostream"

#include "GameConsts.h"

Grid::Grid() {
    GridMatrice.resize(kGridSize.y, std::vector<int>(kGridSize.x, 0));
    Init();
}

void Grid::Init() {
    for (int row = 0; row < kGridSize.y; row++) {
        for (int column = 0; column < kGridSize.x; column++) {
            GridMatrice[row][column] = 0;
        }
    }
}

void Grid::Draw() {
    for (int row = 0; row < kGridSize.y; row++) {
        for (int column = 0; column < kGridSize.x; column++) {
            Vector2 position = {kGridOffset.x + column * kGridBoxSize.x + column * kGridBoxOffset.x,
                                kGridOffset.y + row * kGridBoxSize.y + row * kGridBoxOffset.y};
            DrawRectangleV(position, kGridBoxSize, kColors[GridMatrice[row][column]]);
        }
    }
}

void Grid::Print() {
    for (int row = 0; row < kGridSize.y; row++) {
        for (int column = 0; column < kGridSize.x; column++) {
            std::cout << GridMatrice[row][column] << " ";
        }
        std::cout << std::endl;
    } std::cout << std::endl;
}