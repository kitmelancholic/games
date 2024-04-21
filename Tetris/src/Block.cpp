#include "Block.h"
#include "raylib.h"
#include "GameConsts.h"
#include "Grid.h"


Block::Block(Vector2 position, int type) : kBlockType(type) {
    BlockPosition = position;
    RotateState = 0;
    isStopped = false;
    Init();
}

bool Block::InitIsAvailable(Grid &grid) {
    return (IsValidMove(Vector2{0, 0}, grid));
}

void Block::UpdateMoveDown(Grid &grid) {
    if (IsValidMove(Vector2{0, 1}, grid)) {
        BlockPosition.y += 1;
    } else {
        Stop();
    }
}

void Block::UpdateMoveHoriz(Grid &grid, int horizonX) {
    if (IsValidMove(Vector2{(float) horizonX, 0}, grid)) {
        BlockPosition.x += horizonX;
    }
}

void Block::UpdateRotate(Grid &grid) {
    int nextRotateState = (RotateState == kBlockMaxRotateState[kBlockType] - 1) ? 0 : RotateState + 1;
    if (IsValidRotate(nextRotateState, grid)) {
        RotateState = nextRotateState;
    }
}

void Block::DrawOnGrid(Grid &grid) {
    for (Vector2 box: BlockList[RotateState]) {
        grid.GridMatrix[box.y + BlockPosition.y][box.x + BlockPosition.x] = kBlockType + 1;
    }
}

void Block::EraseFromGrid(Grid &grid) {
    for (Vector2 box: BlockList[RotateState]) {
        grid.GridMatrix[box.y + BlockPosition.y][box.x + BlockPosition.x] = 0;
    }
}

bool Block::IsValidMove(Vector2 moveDir, Grid &grid) {
    for (Vector2 box: BlockList[RotateState]) {
        Vector2 newPos = {box.x + BlockPosition.x + moveDir.x, box.y + BlockPosition.y + moveDir.y};
        if (newPos.x < 0 || newPos.y < 0 || newPos.y >= grid.gridSize.y || newPos.x >= grid.gridSize.x ||
            grid.GridMatrix[newPos.y][newPos.x] != 0) {
            return false;
        }
    }
    return true;
}

bool Block::IsValidRotate(int nextRotateState, Grid &grid) {
    for (Vector2 box: BlockList[nextRotateState]) {
        Vector2 newPos = {box.x + BlockPosition.x, box.y + BlockPosition.y};
        if (newPos.x < 0 || newPos.y < 0 || newPos.y >= grid.gridSize.y || newPos.x >= grid.gridSize.x ||
            grid.GridMatrix[newPos.y][newPos.x] != 0) {
            return false;
        }
    }
    return true;
}

void Block::Stop() {
    isStopped = true;
}

bool Block::IsStopped() {
    return isStopped;
}

void Block::Init() {
    switch (kBlockType) {
        case 0: { // L
            BlockList = {
                    {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
                    {{0, 1}, {1, 1}, {2, 1}, {2, 2}},
                    {{1, 0}, {1, 1}, {1, 2}, {2, 0}},
                    {{0, 0}, {0, 1}, {1, 1}, {2, 1}}
            };
            break;
        }
        case 1: { // J
            BlockList = {
                    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
                    {{0, 1}, {0, 2}, {1, 1}, {2, 1}},
                    {{1, 0}, {1, 1}, {1, 2}, {2, 2}},
                    {{0, 1}, {1, 1}, {2, 0}, {2, 1}}
            };
            break;
        }
        case 2: { // I
            BlockList = {
                    {{1, 0}, {1, 1}, {1, 2}, {1, 3}},
                    {{0, 2}, {1, 2}, {2, 2}, {3, 2}},
                    {{2, 0}, {2, 1}, {2, 2}, {2, 3}},
                    {{0, 1}, {1, 1}, {2, 1}, {3, 1}}
            };
            break;
        }
        case 3: { // O
            BlockList = {
                    {{0, 0}, {0, 1}, {1, 0}, {1, 1}}
            };
            break;
        }
        case 4: { // S
            BlockList = {
                    {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
                    {{0, 1}, {1, 1}, {1, 2}, {2, 2}},
                    {{1, 1}, {1, 2}, {2, 0}, {2, 1}},
                    {{0, 0}, {1, 0}, {1, 1}, {2, 1}}
            };
            break;
        }
        case 5: { // T
            BlockList = {
                    {{0, 1}, {1, 0}, {1, 1}, {1, 2}},
                    {{0, 1}, {1, 1}, {1, 2}, {2, 1}},
                    {{1, 0}, {1, 1}, {1, 2}, {2, 1}},
                    {{0, 1}, {1, 0}, {1, 1}, {2, 1}}
            };
            break;
        }
        case 6: { // Z
            BlockList = {
                    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
                    {{0, 2}, {1, 1}, {1, 2}, {2, 1}},
                    {{1, 0}, {1, 1}, {2, 1}, {2, 2}},
                    {{0, 1}, {1, 0}, {1, 1}, {2, 0}}
            };
            break;
        }
    }
}

