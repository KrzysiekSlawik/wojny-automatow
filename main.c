#include "interpreter.h"
#include <stdlib.h>
#include <stdio.h>
#include "robot.h"
#include "map.h"
#include "commands.h"
#include <time.h>

int main()
{
	map *map = initMap(100, 100, 3, 200, 10);


	robot *list[1000];
	for(int i = 0; i<1000; i++)
	{
		list[i] = malloc(sizeof(robot));
	}
	list[0]->hp=2;
	list[0]->pos.x= 40;
	list[0]->pos.y= 25;
	map->whole[40][25]=0;
	list[0]->isAlive = true;
	list[0]->isRed = false;
	list[0]->isWar = false;
	list[0]->isSupp = false;
	list[0]->isBase = false;
	list[0]->stratId = 0;
	list[0]->integerAku = 5;
	list[0]->taskCountBis = 0;
	list[0]->taskCount = 0;
	list[0]->pathPos = 0;
	printf("\n h%ld h",sizeof(long int));
	printf("\n & %ld h",sizeof(&forwardPathC));

	script *test = makeScript("test");
	time_t tlf=time(NULL);
	while(list[0]->isAlive)
	{
		if(time(NULL)-tlf>0.1)
		{
			tlf=time(NULL);
			tickRobots(test, list, map);
			system("clear");
			for(int y = 0; y<100; y++)
			{
				for(int x = 0; x<100; x++)
				{
					if(map->whole[x][y]==-3 || map->whole[x][y]==-2)printf("# ");
					if(map->whole[x][y]>=0)printf("O ");
					if(map->whole[x][y]==-1)printf("  ");
				}
				putchar('\n');
			}
		}
	}

}
