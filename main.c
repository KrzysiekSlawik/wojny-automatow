#include "interpreter.h"
#include <stdlib.h>
#include <stdio.h>
#include "robot.h"
#include "map.h"

int main()
{
	map *map = initMap(200, 100, 3, 800, 20);
	robot bot;
	robot **list;
	//script *test = makeScript("test");
	//test->funcPtr[0](&bot, test->variable[0], map, list);
	//printf("%d", bot.integerAku);
	for(int y = 0; y<100; y++)
	{
		for(int x = 0; x<200; x++)
		{
			if(map->whole[x][y]==-3 || map->whole[x][y]==-2)printf("# ");
			else printf("  ");
		}
		putchar('\n');
	}
}
