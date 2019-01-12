#include "commands.h"
#include <math.h>
#include <stdlib.h>
void loadIC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->integerAku = variable.vid;
	}
	else
	{
		if(variable.vid < 0 && variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return;
		}
		bot->integerAku = bot->integerMem[variable.vid];
	}
}
void saveIC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.vid < 0 && variable.vid >= ROBOTMEM)
	{
		bot->isAlive = false;
		return;
	}
	bot->integerMem[variable.vid] = bot->integerAku;
}
void loadXC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->coordAku.x = variable.vid;
	}
	else
	{
		if(variable.vid < 0 && variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return;
		}
		bot->coordAku.x = bot->integerMem[variable.vid];
	}
}
void loadYC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->coordAku.y = variable.vid;
	}
	else
	{
		if(variable.vid < 0 && variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return;
		}
		bot->coordAku.y = bot->integerMem[variable.vid];
	}
}
void loadCC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.vid < 0 && variable.vid >= ROBOTMEM)
	{
		bot->isAlive = false;
		return;
	}
	bot->coordAku.x = bot->coordMem[variable.vid].x;
	bot->coordAku.y = bot->coordMem[variable.vid].y;
}
void saveCC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.vid < 0 && variable.vid >= ROBOTMEM)
	{
		bot->isAlive = false;
		return;
	}
	bot->coordMem[variable.vid].x = bot->coordAku.x;
	bot->coordMem[variable.vid].y = bot->coordAku.y;
}
void addC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->integerAku += variable.vid;
	}
	else
	{
		if(variable.vid < 0 && variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return;
		}
		bot->integerAku += bot->integerMem[variable.vid];
	}
}
void subC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->integerAku -= variable.vid;
	}
	else
	{
		if(variable.vid < 0 && variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return;
		}
		bot->integerAku -= bot->integerMem[variable.vid];
	}
}
void addXC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->coordAku.x += variable.vid;
	}
	else
	{
		if(variable.vid < 0 && variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return;
		}
		bot->coordAku.x += bot->integerMem[variable.vid];
	}
}
void subXC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->coordAku.x -= variable.vid;
	}
	else
	{
		if(variable.vid < 0 && variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return;
		}
		bot->coordAku.x -= bot->integerMem[variable.vid];
	}
}
void addYC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->coordAku.y += variable.vid;
	}
	else
	{
		if(variable.vid < 0 && variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return;
		}
		bot->coordAku.y += bot->integerMem[variable.vid];
	}
}
void subYC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->coordAku.y -= variable.vid;
	}
	else
	{
		if(variable.vid < 0 && variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return;
		}
		bot->coordAku.y -= bot->integerMem[variable.vid];
	}
}
void greaterC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		if(bot->integerAku > variable.vid)
		{
			bot->integerAku = 1;
		}
		else
		{
			bot->integerAku = 0;
		}
	}
	else
	{
		if(variable.vid < 0 && variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return;
		}
		if(bot->integerAku > bot->integerMem[variable.vid])
		{
			bot->integerAku = 1;
		}
		else
		{
			bot->integerAku = 0;
		}
	}
}
void equalC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		if(bot->integerAku == variable.vid)
		{
			bot->integerAku = 1;
		}
		else
		{
			bot->integerAku = 0;
		}
	}
	else
	{
		if(variable.vid < 0 && variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return;
		}
		if(bot->integerAku == bot->integerMem[variable.vid])
		{
			bot->integerAku = 1;
		}
		else
		{
			bot->integerAku = 0;
		}
	}
}
void jumpC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(bot->integerAku != 0)
	{
		if(variable.isValue)
		{
			bot->taskCount = variable.vid;
		}
		else
		{
			if(variable.vid < 0 && variable.vid >= ROBOTMEM)
			{
				bot->isAlive = false;
				return;
			}
			bot->taskCount = bot->integerMem[variable.vid];
		}
	}
}
void moveC(robot *bot, var variable, map *map, robot *tab[1000])
{
	int directionValue, xVec=0, yVec=0;
	if(variable.isValue)directionValue = variable.vid;
	else
	{
		if(variable.vid < 0 && variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return;
		}
		directionValue = bot -> integerMem[variable.vid];
	}
	switch (directionValue)
	{
		case 0:
			xVec = -1;
			yVec = 1;
			break;
		case 1:
			xVec = 0;
			yVec = 1;
			break;
		case 2:
			xVec = 1;
			yVec = 1;
			break;
		case 3:
			xVec = 1;
			yVec = 0;
			break;
		case 4:
			xVec = 1;
			yVec = -1;
			break;
		case 5:
			xVec = 0;
			yVec = -1;
			break;
		case 6:
			xVec = -1;
			yVec = -1;
			break;
		case 7:
			xVec = -1;
			yVec = 0;
			break;
	}
	point newPos;
	newPos.x = bot -> pos.x + xVec;
	newPos.y = bot -> pos.y + yVec;
	if(newPos.x < 0 && newPos.x >= map->sizeX)
	{
		bot->isAlive = false;
		return;
	}
	if(newPos.y < 0 && newPos.y >= map->sizeY)
	{
		bot->isAlive = false;
		return;
	}
	if(map->whole[newPos.x][newPos.y]==-1)
	{
		bot -> pos = newPos;
	}
}
void attackC(robot *bot, var variable, map *map, robot *tab[1000])
{
	int id;
	if(bot->isBase || bot->isSupp)
	{
		bot->isAlive = false;
		return;
	}
	if(bot->coordAku.x < 0 && bot->coordAku.x >= map->sizeX)
	{
		bot->isAlive = false;
		return;
	}
	if(bot->coordAku.y < 0 && bot->coordAku.y >= map->sizeY)
	{
		bot->isAlive = false;
		return;
	}
	if((id=map->whole[bot->coordAku.x][bot->coordAku.y])>=0)
	{
		if((tab[id]->isRed)!=(bot->isRed))
		{
			int distance = sqrt(pow(bot->coordAku.x-bot->pos.x,2)+pow(bot->coordAku.y-bot->pos.y,2));
			if(distance<=3)
			{
				if(tab[id]->isAlive)
				{
					tab[id]->hp--;
					if(tab[id]->hp==0)
						tab[id]->isAlive = false;
				}
			}
		}
	}
}
void gatherC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!bot->isSupp)
	{
		bot->isAlive = false;
		return;
	}
	if(bot->coordAku.x < 0 && bot->coordAku.x >= map->sizeX)
	{
		bot->isAlive = false;
		return;
	}
	if(bot->coordAku.y < 0 && bot->coordAku.y >= map->sizeY)
	{
		bot->isAlive = false;
		return;
	}
	if(map->whole[bot->coordAku.x][bot->coordAku.y]==-2)
	{
		map->whole[bot->coordAku.x][bot->coordAku.y]=rand()%2 - 2;
		map->resources[(int)bot->isRed];
	}

}
void produceC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
void howManyUnitsC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
void distanceC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
void whatIsC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
void tellC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
void nearestEnemyC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
void nearestFriendC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
void nearestResourceC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
void nearestShadowC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
void myBaseC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
void yellC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
void findPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
void forwardPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
void backwardPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
void lengthPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
void unobstructedPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
void produceWithPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	//work in progress
}
