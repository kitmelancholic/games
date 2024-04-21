#ifndef TETRIS_GRID_H
#define TETRIS_GRID_H

#include "vector"
#include "raylib.h"

class Grid {
public:
    std::vector<std::vector<int>> GridMatrix;
    Vector2 gridSize;
    Vector2 gridOffset;

    Grid(Vector2 GridSize, Vector2 GridOffset);

    void Clear();

    void Draw();

    void CheckClearedRows(int& score);

    void Print();

private:

    void ClearRow(int row);
};

#endif //TETRIS_GRID_H
