#include "Grid.h"
#include "raylib.h"
#include "iostream"

#include "GameConsts.h"

Grid::Grid() {
    GridMatrix.resize(kGridSize.y, std::vector<int>(kGridSize.x, 0));
    Init();
}

void Grid::Init() {
    for (int row = 0; row < kGridSize.y; row++) {
        for (int column = 0; column < kGridSize.x; column++) {
            GridMatrix[row][column] = 0;
        }
    }
}

void Grid::Draw() {
    for (int row = 0; row < kGridSize.y; row++) {
        for (int column = 0; column < kGridSize.x; column++) {
            Vector2 position = {kGridOffset.x + column * kGridBoxSize.x + column * kGridBoxOffset.x,
                                kGridOffset.y + row * kGridBoxSize.y + row * kGridBoxOffset.y};
            DrawRectangleV(position, kGridBoxSize, kColors[GridMatrix[row][column]]);
        }
    }
}

void Grid::Print() {
    for (int row = 0; row < kGridSize.y; row++) {
        for (int column = 0; column < kGridSize.x; column++) {
            std::cout << GridMatrix[row][column] << " ";
        }
        std::cout << std::endl;
    } std::cout << std::endl;
}