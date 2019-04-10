#include "interpreter.h"
#include <stdlib.h>
#include <stdio.h>
#include "robot.h"
#include "map.h"
#include "commands.h"
#include <time.h>
#include "display.h"
#include <ncurses.h>

#define TIMEOUT 100
int main()
{
	initDisplay();
	int delay = 5;
	setDelay(delay);
	WINDOW *mainWin;
	WINDOW *statsWin;
	int winSizeX;
	int winSizeY;


	getmaxyx(stdscr, winSizeY, winSizeX);
	map *curMap = initMapfromCF("map.cfg");
	if(curMap->sizeY<winSizeY)
	{
		winSizeY = curMap->sizeY;
	}
	if(curMap->sizeX<winSizeX - 15)
	{
		winSizeX = curMap->sizeX - 15;
	}
	else
	{
		winSizeX -= 15;
	}
	mainWin = initWindow(winSizeY, winSizeX, 0, 0);
	statsWin = initWindow(winSizeY, 15, 0, winSizeX + 1);
	robot *list[ROBOTSLIMIT];
	for(int i = 0; i<ROBOTSLIMIT; i++)
	{
		list[i] = calloc(1, sizeof(robot));
	}
	initBases(curMap, list);
	int scrCount[2]= {0, 0};
	script **test[2];

	makeTeamScripts("scrRed", true, test, scrCount);
	makeTeamScripts("scrGreen", false, test, scrCount);
	int input=0;
	int px=0, py=0;
	int state = 0;
	int i=0;
	while(!state)
	{
		input = getch();
		switch(input)
		{
			case KEY_LEFT:
				if(px > 0)
				{
					px--;
				}
				break;
			case KEY_RIGHT:
				if(px+winSizeX<curMap->sizeX)
				{
					px++;
				}
				break;
			case KEY_UP:
				if(py > 0)
				{
					py--;
				}
				break;
			case KEY_DOWN:
				if(py+winSizeY<curMap->sizeY)
				{
					py++;
				}
				break;
			case 'k':
				if(delay > 1)
				{
					delay--;
					setDelay(delay);
				}
				break;
			case 'l':
				delay++;
				setDelay(delay);
				break;
			case 'q':
				state = 3;
				break;
			case 's':
				while((state = tickRobots(test, list, curMap))==0 && i!=TIMEOUT)
				{
					i++;
				}
				i = 0;
				break;
			default:
				state = tickRobots(test, list, curMap);
				break;
		}
		printMap(curMap, list, mainWin, px, py, winSizeX, winSizeY, statsWin);
	}
	freeMap(curMap);
	freeBook(test, scrCount);
	for(int i = 0; i<ROBOTSLIMIT; i++)
	{
		free(list[i]->path);
		free(list[i]);
	}
	delWindow(statsWin);
	delWindow(mainWin);
	endDisplay();
	if(state == 1)
	{
		printf("\ngreen won\n");
	}
	if(state == 2)
	{
		printf("\nred won\n");
	}
	if(state == 3)
	{
		printf("\nquited before end\n");
	}
}
