#include <stdio.h>
#include "game_type.h"
#include "game.h"
#include <windows.h>

static char screenElements[MAX_ROW*MAX_COLUMN];

void PrepareDisplay()
{
	int index = 0;
	ScreenCoordinate_t pFruitCoord;
	for(index = 0; index < MAX_ROW*MAX_COLUMN; index++)
	{
		screenElements[index] = ' ';
	}
	
	//Get the coordinates of boundary.
	ScreenCoordinate_t boundaryCoord[40];
	int sizeBoundary = 0;
	GetBoundary(boundaryCoord, &sizeBoundary);

	//Update boundary coordinates to screen
	int boundaryIndex = 0;
	for(boundaryIndex = 0; boundaryIndex < sizeBoundary; boundaryIndex++)
	{
		//Converting 2d coords to 1d
		int coord1D = (boundaryCoord[boundaryIndex].y * MAX_COLUMN) + boundaryCoord[boundaryIndex].x;
		
		//Updating at 1d corrd on screen
		if((coord1D >= 0) && (coord1D < MAX_ROW*MAX_COLUMN))
		{
			screenElements[coord1D] = '*';	
		}
		else
		{
			printf("Invalid conversion!\n");
		}
		
	}
	
	
	//Updating snake
	ScreenCoordinate_t snakeCoord[MAX_ROW*MAX_COLUMN];
	int sizeSnake = 0;
	GetSnake(snakeCoord, &sizeSnake);
	
	
	int snakeIndex=0;
	for(snakeIndex=0; snakeIndex< sizeSnake; snakeIndex++)
	{
		//Converting 2d coords to 1d
		int scoord1D = (snakeCoord[snakeIndex].y * MAX_COLUMN) + snakeCoord[snakeIndex].x;
		screenElements[scoord1D] = '#';		
		
	}
	
	
	//Displaying Fruit

	GetFruit( &pFruitCoord);
	
	{	
		//*pFruitCoord = fruitCoords;
		
		int fcoord1D = (pFruitCoord.y * MAX_COLUMN) + pFruitCoord.x;
		screenElements[fcoord1D] = '$';
	}

			printf("\n%d",sizeSnake);
			
}

void DisplayOnConsole()
{
	//Clearing sceen
	system("@cls||clear");
	
	//Updating display elements
	PrepareDisplay();
	
	//Displaying on console
	int index = 0;
	for(index = 0; index < MAX_ROW*MAX_COLUMN; index++)
	{
		printf("%c", screenElements[index]);
		if((index%MAX_COLUMN) == (MAX_COLUMN-1))
		{
			printf("\n");
		}
	}
	
}
