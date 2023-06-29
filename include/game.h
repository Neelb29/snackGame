#ifndef GAME_H
#define GAME_H

#include "game_type.h"

void InitGame();

void GetBoundary(ScreenCoordinate_t* pObstacleCoord, int* pSize);

void GetSnake(ScreenCoordinate_t* pSnakeCoord, int* pSize);

void GetFruit(ScreenCoordinate_t* pFruitCoord);

void PlayGame();

#endif
