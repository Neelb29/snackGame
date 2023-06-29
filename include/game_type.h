
#ifndef GAME_TYPE_H
#define GAME_TYPE_H

#define MAX_ROW 	(10)
#define MAX_COLUMN	(10)

typedef enum
{
	GAMEELEMENTS_SNAKE,
	GAMEELEMENTS_OBSTACLE,
	GAMEELEMENTS_FRUIT,
	GAMEELEMENTS_NONE
}GameElements_t;

typedef enum
{
	DIR_LEFT,
	DIR_DOWN,
	DIR_UP,
	DIR_RIGHT
}Direction_t;

typedef struct
{
	int x;
	int y;
}ScreenCoordinate_t;



typedef struct
{
	int length;
	Direction_t direction;
	ScreenCoordinate_t coord[MAX_ROW*MAX_COLUMN];
}Snake_t;

#endif
