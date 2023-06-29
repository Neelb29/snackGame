#include"stdio.h"
#include<conio.h>
#include"stdlib.h"
#include"game_type.h"

static Direction_t keyPress = DIR_RIGHT;


void ReadKeyboardInput()
{

	if(kbhit())
	{
		char keyPressed = getch();
		switch(keyPressed)
		{
			case'a': keyPress = DIR_LEFT; break;
	
			case's': keyPress = DIR_DOWN; break;

			case'w': keyPress = DIR_UP; break;

			case'd': keyPress = DIR_RIGHT; break;

			case 27:
				exit (0);
			
			default: break;
		}	
	}
			
  } 


Direction_t GetDirection()
{
	return keyPress;	
}

