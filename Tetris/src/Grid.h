#ifndef TETRIS_GRID_H
#define TETRIS_GRID_H

#include "vector"

class Grid {
public:
    std::vector<std::vector<int>> GridMatrix;

    Grid();

    void Draw();

    void CheckClearedRows();

    void Print();
private:
    void Init();
    void ClearRow(int row);
};

#endif //TETRIS_GRID_H
