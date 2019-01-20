#include "interpreter.h"
#include <stdlib.h>
#include <stdio.h>
#include "robot.h"
#include "map.h"
#include "commands.h"
#include <time.h>

int main()
{
	map *curMap = initMap(100, 100, 3, 200, 10);


	robot *list[1000];
	for(int i = 0; i<1000; i++)
	{
		list[i] = malloc(sizeof(robot));
	}
	list[0]->hp=2;
	list[0]->pos.x= 40;
	list[0]->pos.y= 25;
	curMap->whole[40][25]=0;
	curMap->resources[0]=1000;
	list[0]->isAlive = true;
	list[0]->isRed = false;
	list[0]->isWar = false;
	list[0]->isSupp = false;
	list[0]->isBase = true;
	list[0]->stratId = 0;
	list[0]->integerAku = 5;
	list[0]->taskCountBis = 0;
	list[0]->taskCount = 0;
	list[0]->pathPos = 0;
	int scrCount[2]= {1, 0};
	script **test[2];
	test[0]=malloc(sizeof(script*));
	test[0][0] = makeScript("baseTest");
	addScriptToBook(test, "test", false, scrCount);
	time_t tlf=time(NULL);
	int i=0;
	while(i!=10)
	{
		if(time(NULL)-tlf>0.1)
		{
			i++;
			tlf=time(NULL);
			tickRobots(test, list, curMap);
			//system("clear");
			/*
			for(int y = 0; y<100; y++)
			{
				for(int x = 0; x<100; x++)
				{
					if(curMap->whole[x][y]>=0)printf("O ");
					if(curMap->whole[x][y]==-3 || map->whole[x][y]==-2)printf("# ");
					if(curMap->whole[x][y]==-1)printf("  ");
				}
				putchar('\n');
			}*/
		}
	}
	freeMap(curMap);
	freeBook(test, scrCount);
	for(int i = 0; i<1000; i++)
	{
		free(list[i]);
	}
}
