#ifndef TETRIS_GAMECONSTS_H
#define TETRIS_GAMECONSTS_H

#include "raylib.h"

const Vector2 kWindowSize = {490, 650};
const Vector2 kGridOffset = {15, 15};
const Vector2 kGridSize = {10, 20};
const Vector2 kGridBoxSize = {30, 30};
const Vector2 kGridBoxOffset = {1, 1};
const Vector2 kFirstTextBoxOffset = {350, 15};
const Vector2 kSecondTextBoxOffset = {350, 175};
const Vector2 kNextGridSize = {4, 4};
const Vector2 kNextGridOffset = {350, 30};
const Color kColors[7] = {LIGHTGRAY, LIME, MAROON, ORANGE, GOLD, VIOLET, DARKBLUE};
const int kBlockMaxRotateState[7] = {4, 4, 4, 1, 4, 4, 4};

#endif //TETRIS_GAMECONSTS_H