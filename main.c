#include "interpreter.h"
#include <stdlib.h>
#include <stdio.h>
#include "robot.h"
#include "map.h"
#include "commands.h"
#include <time.h>
#include "display.h"

int main()
{
	map *curMap = initMapfromCF("map.cfg");
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

	time_t tlf=time(NULL);
	while(true)
	{
		if(time(NULL)-tlf>0.1)
		{
			tlf=time(NULL);
			tickRobots(test, list, curMap);
			system("clear");
			printMap(curMap, list);
		}
	}
	freeMap(curMap);
	freeBook(test, scrCount);
	for(int i = 0; i<ROBOTSLIMIT; i++)
	{
		free(list[i]->path);
		free(list[i]);
	}
}
