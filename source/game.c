#include <stdio.h>

#include "game_type.h"
#include "display.h"
#include <windows.h>
#include "input.h"
#include <unistd.h>

static ScreenCoordinate_t obstacleCoords[(MAX_ROW*4)-4] = {{0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7}, {0,8}, {0,9}, 
													   		  {1,9}, {2,9}, {3,9}, {4,9}, {5,9}, {6,9}, {7,9}, {8,9}, {9,9}, 
															  {9,8}, {9,7}, {9,6}, {9,5}, {9,4}, {9,3}, {9,2}, {9,1}, {9,0},
															  {8,0}, {7,0}, {6,0}, {5,0}, {4,0}, {3,0}, {2,0}, {1,0}
														  };

static ScreenCoordinate_t fruitCoords = {5,4};

static Snake_t snake = {2, DIR_RIGHT, {{2,2}, {3,2}}};

static GenerateFruit( ){
	
	
	fruitCoords.x = (rand()% 8)+1;
		
	fruitCoords.y = (rand()% 8)+1;
};



static void UpdateSnake();

static void EatFruit();
static void checkTermination();
void InitGame()
{
	//Initialize boundary.
	int index = 0;
	for(index = 0; index < (MAX_ROW*4-4); index++)
	{
		printf("coord: (%d,%d)\n", obstacleCoords[index].x, obstacleCoords[index].y);	
	}
	
	DisplayOnConsole();
	  
}
#if 1
void GetSnake(ScreenCoordinate_t* pSnakeCoord, int* pSize)
{
	*pSize = (snake.length);
	int snakeIndex=0;
	for(snakeIndex=0; snakeIndex< snake.length; snakeIndex++)
	{
		pSnakeCoord[snakeIndex] = snake.coord[snakeIndex];
	}
}
#endif



void GetBoundary(ScreenCoordinate_t* pObstacleCoord, int* pSize)
{
	*pSize = (MAX_ROW*4)-4;
	
	int index = 0;
	for(index = 0; index < (MAX_ROW*4-4); index++)
	{
		pObstacleCoord[index] = obstacleCoords[index];
	}
	
}

void GetFruit(ScreenCoordinate_t* pFruitCoord)
{	
		*pFruitCoord = fruitCoords;
}





void PlayGame()
{
	
	while(1)
	{
		//Read keyboard input
		ReadKeyboardInput();
		Direction_t keyPressDir = GetDirection();
		snake.direction = keyPressDir;
		
		//Update sanke
		UpdateSnake();
		
		
		//Eat fruit
		EatFruit();
		
		//Chcek Termination of Snake
		checkTermination();
			
		//Display
		DisplayOnConsole();
		
		//Wait for next frame to update
		usleep(500000);
	}
	
}




static void UpdateSnake()
{
	//Shift left (update tail)
	int pos =  0;
	for(pos = 1; pos < snake.length; pos++){
		snake.coord[pos-1] = snake.coord[pos];
	}
	
	//Update right (update head) based on direction
	switch(snake.direction)
	{
		case DIR_LEFT:  
		{
			--snake.coord[snake.length-1].x; 
			break;
		}
		
		case DIR_RIGHT:  
		{
			++snake.coord[snake.length-1].x; 
			break;
		}
		
		case DIR_UP:  
		{
			--snake.coord[snake.length-1].y; 
			break;
		}
		
		case DIR_DOWN:  
		{
			++snake.coord[snake.length-1].y; 
			break;
		}
		
		default: break;
	}
	
}

static void checkTermination(){
		if(snake.coord[snake.length-1].x == 0 || 
		snake.coord[snake.length-1].x == MAX_COLUMN-1 || 
		snake.coord[snake.length-1].y == 0 || 
		snake.coord[snake.length-1].y == MAX_ROW -1 ){
			printf("Score = %d",snake.length*10);
			printf("\nGame Over\n");
			exit (EXIT_FAILURE);
		}
}
static void EatFruit()
{

	if(snake.coord[snake.length-1].x == fruitCoords.x &&
		 snake.coord[snake.length-1].y == fruitCoords.y)
	{
		
		// Update new lenght increased by 1
		++snake.length;

		int pos =  0;
		for(pos = 1; pos < snake.length; pos++){
			snake.coord[pos-1] = snake.coord[pos];
		}

		snake.coord[snake.length-1].x = fruitCoords.x;
		snake.coord[snake.length-1].y = fruitCoords.y;
	
		//Generate Next Fruit 
		GenerateFruit();

	}
	 
}

