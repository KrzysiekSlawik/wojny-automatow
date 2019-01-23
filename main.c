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
	map *curMap = initMap(100, 100, 3, 200, 10);


	robot *list[1000];
	for(int i = 0; i<1000; i++)
	{
		list[i] = calloc(1, sizeof(robot));
	}
	initBases(curMap, list);
	int scrCount[2]= {1, 0};
	script **test[2];
	test[0]=calloc(1, sizeof(script*));
	test[1]=calloc(1, sizeof(script*));
	test[0][0] = makeScript("baseTest");
	test[1][0] = makeScript("baseTest");

	addScriptToBook(test, "test", false, scrCount);
	time_t tlf=time(NULL);
	int i=0;
	while(i<100)
	{
		if(time(NULL)-tlf>0.1)
		{
			i++;
			tlf=time(NULL);
			tickRobots(test, list, curMap);
			system("clear");
			printMap(curMap, list);
		}
	}
	freeMap(curMap);
	freeBook(test, scrCount);
	for(int i = 0; i<1000; i++)
	{
		free(list[i]->path);
		free(list[i]);
	}
}
