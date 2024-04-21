#ifndef TETRIS_BLOCK_H
#define TETRIS_BLOCK_H

#include "raylib.h"
#include "Grid.h"
#include "vector"

class Block {
public:
    Block(Vector2 position, int type);

    bool InitIsAvailable(Grid &grid);

    void UpdateMoveDown(Grid &grid);

    void UpdateMoveHoriz(Grid &grid, int horizonX);

    void UpdateRotate(Grid &grid);

    void DrawOnGrid(Grid &grid);

    void EraseFromGrid(Grid &grid);

    void Stop();

    bool IsStopped();

protected:
    std::vector<std::vector<Vector2>> BlockList;
    const int kBlockType;
    Vector2 BlockPosition;
    int RotateState;
    bool isStopped;

    void Init();

    bool IsValidMove(Vector2 moveDir, Grid &grid);

    bool IsValidRotate(int nextRotateState, Grid &grid);
};

#endif //TETRIS_BLOCK_H