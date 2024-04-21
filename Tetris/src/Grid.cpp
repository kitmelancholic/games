#include "Grid.h"
#include "raylib.h"
#include "iostream"

#include "GameConsts.h"

Grid::Grid(Vector2 GridSize, Vector2 GridOffset) {
    gridSize = GridSize;
    gridOffset = GridOffset;
    GridMatrix.resize(gridSize.y, std::vector<int>(gridSize.x, 0));
    Clear();
}

void Grid::Clear() {
    for (int row = 0; row < gridSize.y; row++) {
        for (int column = 0; column < gridSize.x; column++) {
            GridMatrix[row][column] = 0;
        }
    }
}

void Grid::Draw() {
    for (int row = 0; row < gridSize.y; row++) {
        for (int column = 0; column < gridSize.x; column++) {
            Vector2 position = {gridOffset.x + column * kGridBoxSize.x + column * kGridBoxOffset.x,
                                gridOffset.y + row * kGridBoxSize.y + row * kGridBoxOffset.y};
            DrawRectangleV(position, kGridBoxSize, kColors[GridMatrix[row][column]]);
        }
    }
}

void Grid::Print() {
    for (int row = 0; row < gridSize.y; row++) {
        for (int column = 0; column < gridSize.x; column++) {
            std::cout << GridMatrix[row][column] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Grid::CheckClearedRows(int& score) {
    for (int row = 0; row < gridSize.y; row++) {
        bool flag = false;
        for (int column = 0; column < gridSize.x; column++) {
            if (GridMatrix[row][column] == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            ClearRow(row);
            score++;
        }
    }
}

void Grid::ClearRow(int clearrow) {

    for (int row = clearrow; row > 0; row--) {
        for (int column = 0; column < gridSize.x; column++) {
            if (row == 0) {
                std::cout << "passed" << std::endl;
                GridMatrix[row][column] = 0;
            } else {
                GridMatrix[row][column] = GridMatrix[row - 1][column];
            }
        }
    }
}
