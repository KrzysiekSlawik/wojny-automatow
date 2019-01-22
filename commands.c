#include "commands.h"
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
bool actionLength(robot *bot, int length)
{
	if(bot->taskCountBis>=length-1)
	{
		bot->taskCountBis = 0;
		return true;
	}
	else
	{
		bot->taskCountBis++;
		return false;
	}
}
bool visionUpdate(robot *bot, map *map)
{
	for(int x = 0; x<11; x++)
	{
		for(int y = 0; y<11; y++)
		{
			if(bot->pos.x-5+x>=0 && bot->pos.x-5+x<map->sizeX && bot->pos.y-5+y>=0 && bot->pos.y-5+y<map->sizeY)
			{
				map->vision[bot->isRed][bot->pos.x-5+x][bot->pos.y-5+y] = true;
			}
		}
	}
	return true;
}
bool loadIC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(variable.isValue)
	{
		bot->integerAku = variable.vid;
	}
	else
	{
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return false;
		}
		bot->integerAku = bot->integerMem[variable.vid];
	}
	return true;
}
bool saveIC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(variable.vid < 0 || variable.vid >= ROBOTMEM)
	{
		bot->isAlive = false;
		return false;
	}
	bot->integerMem[variable.vid] = bot->integerAku;
	return true;
}
bool loadXC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.vid == 5)return true;
	if(!actionLength(bot, 1))return false;
	if(variable.isValue)
	{
		bot->coordAku.x = variable.vid;
	}
	else
	{
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return false;
		}
		bot->coordAku.x = bot->integerMem[variable.vid];
	}
	return true;
}
bool loadYC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(variable.isValue)
	{
		bot->coordAku.y = variable.vid;
	}
	else
	{
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return false;
		}
		bot->coordAku.y = bot->integerMem[variable.vid];
	}
	return true;
}
bool loadCC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(variable.vid < 0 || variable.vid >= ROBOTMEM)
	{
		bot->isAlive = false;
		return false;
	}
	bot->coordAku.x = bot->coordMem[variable.vid].x;
	bot->coordAku.y = bot->coordMem[variable.vid].y;
	return true;
}
bool saveCC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(variable.vid < 0 || variable.vid >= ROBOTMEM)
	{
		bot->isAlive = false;
		return false;
	}
	bot->coordMem[variable.vid].x = bot->coordAku.x;
	bot->coordMem[variable.vid].y = bot->coordAku.y;
	return true;
}
bool addC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(variable.isValue)
	{
		bot->integerAku += variable.vid;
	}
	else
	{
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return false;
		}
		bot->integerAku += bot->integerMem[variable.vid];
	}
	return true;
}
bool subC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(variable.isValue)
	{
		bot->integerAku -= variable.vid;
	}
	else
	{
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return false;
		}
		bot->integerAku -= bot->integerMem[variable.vid];
	}
	return true;
}
bool addXC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(variable.isValue)
	{
		bot->coordAku.x += variable.vid;
	}
	else
	{
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return false;
		}
		bot->coordAku.x += bot->integerMem[variable.vid];
	}
	return true;
}
bool subXC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(variable.isValue)
	{
		bot->coordAku.x -= variable.vid;
	}
	else
	{
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return false;
		}
		bot->coordAku.x -= bot->integerMem[variable.vid];
	}
	return true;
}
bool addYC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(variable.isValue)
	{
		bot->coordAku.y += variable.vid;
	}
	else
	{
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return false;
		}
		bot->coordAku.y += bot->integerMem[variable.vid];
	}
	return true;
}
bool subYC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(variable.isValue)
	{
		bot->coordAku.y -= variable.vid;
	}
	else
	{
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return false;
		}
		bot->coordAku.y -= bot->integerMem[variable.vid];
	}
	return true;
}
bool greaterC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
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
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return false;
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
	return true;
}
bool equalC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
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
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return false;
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
	return true;
}
bool jumpC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(bot->integerAku == 0)return true;
	if(variable.isValue)
	{
		bot->taskCount = variable.vid-1;
	}
	else
	{
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return false;
		}
		bot->taskCount = bot->integerMem[variable.vid]-1;
	}
	return true;
}
bool moveC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(bot->isBase)
	{
		bot->isAlive = false;
		return false;
	}
	int directionValue, xVec=0, yVec=0;
	if(variable.isValue)directionValue = variable.vid;
	else
	{
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return false;
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
	if(newPos.x < 0 || newPos.x >= map->sizeX)
	{
		bot->isAlive = false;
		return false;
	}
	if(newPos.y < 0 || newPos.y >= map->sizeY)
	{
		bot->isAlive = false;
		return false;
	}
	if(map->whole[newPos.x][newPos.y]==-1)
	{
		map->whole[newPos.x][newPos.y] = map->whole[bot->pos.x][bot->pos.y];
		map->whole[bot->pos.x][bot->pos.y] = -1;
		bot -> pos = newPos;
	}
	visionUpdate(bot, map);
	return true;
}
bool attackC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(!bot->isBase && !bot->isSupp && !bot->isWar)
	{
		bot->isWar = true;
	}
	int id;
	if(!bot->isWar)
	{
		bot->isAlive = false;
		return false;
	}
	if(bot->coordAku.x < 0 || bot->coordAku.x >= map->sizeX)
	{
		bot->isAlive = false;
		return false;
	}
	if(bot->coordAku.y < 0 || bot->coordAku.y >= map->sizeY)
	{
		bot->isAlive = false;
		return false;
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
	return true;
}
bool gatherC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(!bot->isBase && !bot->isSupp && !bot->isWar)
	{
		bot->isSupp = true;
	}
	if(!bot->isSupp)
	{
		bot->isAlive = false;
		return false;
	}
	if(bot->coordAku.x < 0 || bot->coordAku.x >= map->sizeX)
	{
		bot->isAlive = false;
		return false;
	}
	if(bot->coordAku.y < 0 || bot->coordAku.y >= map->sizeY)
	{
		bot->isAlive = false;
		return false;
	}
	int distance = sqrt(pow(bot->coordAku.x-bot->pos.x,2)+pow(bot->coordAku.y-bot->pos.y,2));
	if(distance>3)return false;
	if(map->whole[bot->coordAku.x][bot->coordAku.y]==-2)
	{
		map->whole[bot->coordAku.x][bot->coordAku.y]=rand()%2 - 2;
		map->resources[(int)bot->isRed]++;
	}
	return true;
}
bool produceC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(!bot->isBase)
	{
		bot->isAlive = false;
		return false;
	}
	if(map->resources[(int)bot->isRed]<10)return false;
	int idS;
	if(variable.isValue)
	{
		idS = variable.vid;
	}
	else
	{
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return false;
		}
		idS = bot->integerMem[variable.vid];
	}
	if(idS <= 0)
	{
		bot->isAlive = false;
		return false;
	}
	int idT;
	for(idT = 0; idT<1000; idT++)
	{
		if(!tab[idT]->isAlive)break;
	}
	if(map->whole[bot->pos.x-1][bot->pos.y+1])
	{
		tab[idT]->pos.x = bot->pos.x-1;
		tab[idT]->pos.y = bot->pos.y+1;
	}
	else if(map->whole[bot->pos.x][bot->pos.y+1])
	{
		tab[idT]->pos.x = bot->pos.x;
		tab[idT]->pos.y = bot->pos.y+1;
	}
	else if(map->whole[bot->pos.x+1][bot->pos.y+1])
	{
		tab[idT]->pos.x = bot->pos.x+1;
		tab[idT]->pos.y = bot->pos.y+1;
	}
	else if(map->whole[bot->pos.x+1][bot->pos.y])
	{
		tab[idT]->pos.x = bot->pos.x+1;
		tab[idT]->pos.y = bot->pos.y;
	}
	else if(map->whole[bot->pos.x+1][bot->pos.y-1])
	{
		tab[idT]->pos.x = bot->pos.x+1;
		tab[idT]->pos.y = bot->pos.y-1;
	}
	else if(map->whole[bot->pos.x][bot->pos.y-1])
	{
		tab[idT]->pos.x = bot->pos.x;
		tab[idT]->pos.y = bot->pos.y-1;
	}
	else if(map->whole[bot->pos.x-1][bot->pos.y-1])
	{
		tab[idT]->pos.x = bot->pos.x-1;
		tab[idT]->pos.y = bot->pos.y-1;
	}
	else if(map->whole[bot->pos.x-1][bot->pos.y])
	{
		tab[idT]->pos.x = bot->pos.x-1;
		tab[idT]->pos.y = bot->pos.y;
	}
	else
	{
		return false;
	}
	tab[idT]->hp = 2;
	tab[idT]->isAlive = true;
	tab[idT]->isRed = bot->isRed;
	tab[idT]->stratId = idS;
	tab[idT]->isSupp = false;
	tab[idT]->isBase = false;
	tab[idT]->coordAku.x = 0;
	tab[idT]->coordAku.y = 0;
	tab[idT]->integerAku = 0;
	tab[idT]->pathLength = 0;
	tab[idT]->pathPos = 0;
	for(int i = 0; i < ROBOTMEM; i++)
	{
		tab[idT]->coordMem[i].x = 0;
		tab[idT]->coordMem[i].x = 0;
		tab[idT]->integerMem[i] = 0;
	}
	map->resources[(int)bot->isRed]-=10;
	map->whole[tab[idT]->pos.x][tab[idT]->pos.y] = idT;
	visionUpdate(bot, map);
	return true;
}
bool howManyUnitsC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	int toReturn = 0;
	if(!bot->isBase)
	{
		bot->isAlive = false;
		return false;
	}
	for(int i=0; i<1000; i++)
	{
		if(bot->isRed == tab[i]->isRed)
		{
			if(tab[i]->stratId==bot->integerAku)
			{
				toReturn++;
			}
		}
	}
	bot->integerAku = toReturn;
	return true;
}
bool distanceC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	int distance = sqrt(pow(bot->coordAku.x-bot->pos.x,2)+pow(bot->coordAku.y-bot->pos.y,2));
	bot->integerAku = distance;
	return true;
}
bool whatIsC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(bot->coordAku.x < 0 || bot->coordAku.x >= map->sizeX)
	{
		bot->isAlive = false;
		return false;
	}
	if(bot->coordAku.y < 0 || bot->coordAku.y >= map->sizeY)
	{
		bot->isAlive = false;
		return false;
	}
	int ID = map->whole[bot->coordAku.x][bot->coordAku.y];
	if(ID>=0)
	{
		if(bot->isRed == tab[ID]->isRed)
		{
			bot->integerAku = ID;
			return true;
		}
		else
		{
			bot->integerAku = -4;
			return true;
		}
	}
	else bot->integerAku = ID;
	return true;
}
bool tellC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	int toIntegerAku;
	if(variable.isValue)
	{
		toIntegerAku = variable.vid;
	}
	else
	{
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return false;
		}
		toIntegerAku = bot->integerMem[variable.vid];
	}
	if(bot->integerAku < 0 || bot->integerAku >= 1000)
	{
		bot->isAlive = false;
		return false;
	}
	tab[bot->integerAku]->coordAku = bot->coordAku;
	tab[bot->integerAku]->integerAku = toIntegerAku;
	return true;
}
bool nearestEnemyC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	for(int i = 1; i+bot->pos.x < map->sizeX || bot->pos.x - i >= 0 || i+bot->pos.y < map->sizeY || bot->pos.y - i >= 0; i++)
	{
		if(bot->pos.y+i<map->sizeY)
		{
			for(int j = 0; j < 1+2*i; j++)
			{
				if(bot->pos.x - i + j >= 0 && bot->pos.x - i + j < map->sizeX)
				{
					if(map->vision[(int)bot->isRed][bot->pos.x - i + j][bot->pos.y + i])
					{
						if(map->whole[bot->pos.x - i + j][bot->pos.y + i]>=0)
						{
							if(tab[map->whole[bot->pos.x - i + j][bot->pos.y + i]]->isRed != bot->isRed)
							{
								bot->coordAku.x = bot->pos.x - i + j;
								bot->coordAku.y = bot->pos.y + i;
								return true;
							}
						}
					}
				}
			}
		}
		if(bot->pos.x+i < map->sizeX)
		{
			for(int j = 1; j < 1+2*i; j++)
			{
				if(bot->pos.y + i - j >= 0 && bot->pos.y + i - j < map->sizeY)
				{
					if(map->vision[(int)bot->isRed][bot->pos.x + i][bot->pos.y + i - j])
					{
						if(map->whole[bot->pos.x + i][bot->pos.y + i - j]>=0)
						{
							if(tab[map->whole[bot->pos.x + i][bot->pos.y + i - j]]->isRed != bot->isRed)
							{
								bot->coordAku.x = bot->pos.x + i;
								bot->coordAku.y = bot->pos.y + i - j;
								return true;
							}
						}
					}
				}
			}
		}
		if(bot->pos.y-i >= 0)
		{
			for(int j = 0; j < 1+2*i; j++)
			{
				if(bot->pos.x + i - j >= 0 && bot->pos.x + i - j < map->sizeX)
				{
					if(map->vision[(int)bot->isRed][bot->pos.x + i - j][bot->pos.y - i])
					{
						if(map->whole[bot->pos.x + i - j][bot->pos.y - i]>=0)
						{
							if(tab[map->whole[bot->pos.x + i - j][bot->pos.y - i]]->isRed != bot->isRed)
							{
								bot->coordAku.x = bot->pos.x + i - j;
								bot->coordAku.y = bot->pos.y - i;
								return true;
							}
						}
					}
				}
			}
		}
		if(bot->pos.x-i >= 0)
		{
			for(int j = 1; j < 1+2*i; j++)
			{
				if(bot->pos.y - i + j >= 0 && bot->pos.y - i + j < map->sizeY)
				{
					if(map->vision[(int)bot->isRed][bot->pos.x - i][bot->pos.y - i + j])
					{
						if(map->whole[bot->pos.x - i][bot->pos.y - i + j]>=0)
						{
							if(tab[map->whole[bot->pos.x - i][bot->pos.y - i + j]]->isRed != bot->isRed)
							{
								bot->coordAku.x = bot->pos.x - i;
								bot->coordAku.y = bot->pos.y - i + j;
								return true;
							}
						}
					}
				}
			}
		}
	}
	return true;
}
bool nearestFriendC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	for(int i = 1; i+bot->pos.x < map->sizeX || bot->pos.x - i >= 0 || i+bot->pos.y < map->sizeY || bot->pos.y - i >= 0; i++)
	{
		if(bot->pos.y+i<map->sizeY)
		{
			for(int j = 0; j < 1+2*i; j++)
			{
				if(bot->pos.x - i + j >= 0 && bot->pos.x - i + j < map->sizeX)
				{
					if(map->vision[(int)bot->isRed][bot->pos.x - i + j][bot->pos.y + i])
					{
						if(map->whole[bot->pos.x - i + j][bot->pos.y + i]>=0)
						{
							if(tab[map->whole[bot->pos.x - i + j][bot->pos.y + i]]->isRed == bot->isRed)
							{
								bot->coordAku.x = bot->pos.x - i + j;
								bot->coordAku.y = bot->pos.y + i;
								return true;
							}
						}
					}
				}
			}
		}
		if(bot->pos.x+i < map->sizeX)
		{
			for(int j = 1; j < 1+2*i; j++)
			{
				if(bot->pos.y + i - j >= 0 && bot->pos.y + i - j < map->sizeY)
				{
					if(map->vision[(int)bot->isRed][bot->pos.x + i][bot->pos.y + i - j])
					{
						if(map->whole[bot->pos.x + i][bot->pos.y + i - j]>=0)
						{
							if(tab[map->whole[bot->pos.x + i][bot->pos.y + i - j]]->isRed == bot->isRed)
							{
								bot->coordAku.x = bot->pos.x + i;
								bot->coordAku.y = bot->pos.y + i - j;
								return true;
							}
						}
					}
				}
			}
		}
		if(bot->pos.y-i >= 0)
		{
			for(int j = 0; j < 1+2*i; j++)
			{
				if(bot->pos.x + i - j >= 0 && bot->pos.x + i - j < map->sizeX)
				{
					if(map->vision[(int)bot->isRed][bot->pos.x + i - j][bot->pos.y - i])
					{
						if(map->whole[bot->pos.x + i - j][bot->pos.y - i]>=0)
						{
							if(tab[map->whole[bot->pos.x + i - j][bot->pos.y - i]]->isRed == bot->isRed)
							{
								bot->coordAku.x = bot->pos.x + i - j;
								bot->coordAku.y = bot->pos.y - i;
								return true;
							}
						}
					}
				}
			}
		}
		if(bot->pos.x-i >= 0)
		{
			for(int j = 1; j < 1+2*i; j++)
			{
				if(bot->pos.y - i + j >= 0 && bot->pos.y - i + j < map->sizeY)
				{
					if(map->vision[(int)bot->isRed][bot->pos.x - i][bot->pos.y - i + j])
					{
						if(map->whole[bot->pos.x - i][bot->pos.y - i + j]>=0)
						{
							if(tab[map->whole[bot->pos.x - i][bot->pos.y - i + j]]->isRed == bot->isRed)
							{
								bot->coordAku.x = bot->pos.x - i;
								bot->coordAku.y = bot->pos.y - i + j;
								return true;
							}
						}
					}
				}
			}
		}
	}
	return true;
}
bool nearestResourceC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	for(int i = 1; i+bot->pos.x < map->sizeX || bot->pos.x - i >= 0 || i+bot->pos.y < map->sizeY || bot->pos.y - i >= 0; i++)
	{
		if(bot->pos.y+i<map->sizeY)
		{
			for(int j = 0; j < 1+2*i; j++)
			{
				if(bot->pos.x - i + j >= 0 && bot->pos.x - i + j < map->sizeX)
				{
					if(map->vision[(int)bot->isRed][bot->pos.x - i + j][bot->pos.y + i])
					{
						if(map->whole[bot->pos.x - i + j][bot->pos.y + i]==-2)
						{
							bot->coordAku.x = bot->pos.x - i + j;
							bot->coordAku.y = bot->pos.y + i;
							return true;
						}
					}
				}
			}
		}
		if(bot->pos.x+i < map->sizeX)
		{
			for(int j = 1; j < 1+2*i; j++)
			{
				if(bot->pos.y + i - j >= 0 && bot->pos.y + i - j < map->sizeY)
				{
					if(map->vision[(int)bot->isRed][bot->pos.x + i][bot->pos.y + i - j])
					{
						if(map->whole[bot->pos.x + i][bot->pos.y + i - j]==-2)
						{
							bot->coordAku.x = bot->pos.x + i;
							bot->coordAku.y = bot->pos.y + i - j;
							return true;
						}
					}
				}
			}
		}
		if(bot->pos.y-i >= 0)
		{
			for(int j = 0; j < 1+2*i; j++)
			{
				if(bot->pos.x + i - j >= 0 && bot->pos.x + i - j < map->sizeX)
				{
					if(map->vision[(int)bot->isRed][bot->pos.x + i - j][bot->pos.y - i])
					{
						if(map->whole[bot->pos.x + i - j][bot->pos.y - i]==-2)
						{
							bot->coordAku.x = bot->pos.x + i - j;
							bot->coordAku.y = bot->pos.y - i;
							return true;
						}
					}
				}
			}
		}
		if(bot->pos.x-i >= 0)
		{
			for(int j = 1; j < 1+2*i; j++)
			{
				if(bot->pos.y - i + j >= 0 && bot->pos.y - i + j < map->sizeY)
				{
					if(map->vision[(int)bot->isRed][bot->pos.x - i][bot->pos.y - i + j])
					{
						if(map->whole[bot->pos.x - i][bot->pos.y - i + j]==-2)
						{
							bot->coordAku.x = bot->pos.x - i;
							bot->coordAku.y = bot->pos.y - i + j;
							return true;
						}
					}
				}
			}
		}
	}
	return true;
}
bool nearestShadowC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	for(int i = 1; i+bot->pos.x < map->sizeX || bot->pos.x - i >= 0 || i+bot->pos.y < map->sizeY || bot->pos.y - i >= 0; i++)
	{
		if(bot->pos.y+i<map->sizeY)
		{
			for(int j = 0; j < 1+2*i; j++)
			{
				if(bot->pos.x - i + j >= 0 && bot->pos.x - i + j < map->sizeX)
				{
					if(!map->vision[(int)bot->isRed][bot->pos.x - i + j][bot->pos.y + i])
					{
						bot->coordAku.x = bot->pos.x - i + j;
						bot->coordAku.y = bot->pos.y + i;
						return true;
					}
				}
			}
		}
		if(bot->pos.x+i < map->sizeX)
		{
			for(int j = 1; j < 1+2*i; j++)
			{
				if(bot->pos.y + i - j >= 0 && bot->pos.y + i - j < map->sizeY)
				{
					if(!map->vision[(int)bot->isRed][bot->pos.x + i][bot->pos.y + i - j])
					{
						bot->coordAku.x = bot->pos.x + i;
						bot->coordAku.y = bot->pos.y + i - j;
						return true;
					}
				}
			}
		}
		if(bot->pos.y-i >= 0)
		{
			for(int j = 0; j < 1+2*i; j++)
			{
				if(bot->pos.x + i - j >= 0 && bot->pos.x + i - j < map->sizeX)
				{
					if(!map->vision[(int)bot->isRed][bot->pos.x + i - j][bot->pos.y - i])
					{
						bot->coordAku.x = bot->pos.x + i - j;
						bot->coordAku.y = bot->pos.y - i;
						return true;
					}
				}
			}
		}
		if(bot->pos.x-i >= 0)
		{
			for(int j = 1; j < 1+2*i; j++)
			{
				if(bot->pos.y - i + j >= 0 && bot->pos.y - i + j < map->sizeY)
				{
					if(!map->vision[(int)bot->isRed][bot->pos.x - i][bot->pos.y - i + j])
					{
						bot->coordAku.x = bot->pos.x - i;
						bot->coordAku.y = bot->pos.y - i + j;
						return true;
					}
				}
			}
		}
	}
	return true;
}
bool myBaseC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	for(int i = 0; i < 1000; i++)
	{
		if(tab[i]->isRed == bot->isRed)
		{
			if(tab[i]->isBase)
			{
				bot->coordAku.x = tab[i]->pos.x;
				bot->coordAku.y = tab[i]->pos.y;
				return true;
			}
		}
	}
	return true;
}
bool yellC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	for(int i = 0; i < 1000; i++)
	{
		if(tab[i]->isRed == bot->isRed)
		{
			tab[i]->coordAku.x = bot->coordAku.x;
			tab[i]->coordAku.y = bot->coordAku.y;
			tab[i]->integerAku = bot->integerAku;
		}
	}
	return true;
}
bool findPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(bot->path!=NULL)free(bot->path);
	bot->path = NULL;
	if(bot->coordAku.x < 0 || bot->coordAku.x >= map->sizeX)
	{
		bot->isAlive = false;
		return false;
	}
	if(bot->coordAku.y < 0 || bot->coordAku.y >= map->sizeY)
	{
		bot->isAlive = false;
		return false;
	}
	if(map->vision[(int)bot->isRed][bot->coordAku.x][bot->coordAku.y] && map->whole[bot->coordAku.x][bot->coordAku.y]!= -1)
	{
		int range = 0;
		while(range <= 5)
		{
			range++;
			if(bot->coordAku.x+range<map->sizeX)
			{
				if(map->vision[(int)bot->isRed][bot->coordAku.x+range][bot->coordAku.y] && map->whole[bot->coordAku.x+range][bot->coordAku.y]== -1)
				{
					bot->coordAku.x += range;
					break;
				}
			}
			if(bot->coordAku.x-range>=0)
			{
				if(map->vision[(int)bot->isRed][bot->coordAku.x-range][bot->coordAku.y] && map->whole[bot->coordAku.x-range][bot->coordAku.y]== -1)
				{
					bot->coordAku.x -= range;
					break;
				}
			}
			if(bot->coordAku.y+range<map->sizeY)
			{
				if(map->vision[(int)bot->isRed][bot->coordAku.x][bot->coordAku.y+range] && map->whole[bot->coordAku.x][bot->coordAku.y+range]== -1)
				{
					bot->coordAku.y += range;
					break;
				}
			}
			if(bot->coordAku.y-range>=0)
			{
				if(map->vision[(int)bot->isRed][bot->coordAku.x][bot->coordAku.y-range] && map->whole[bot->coordAku.x][bot->coordAku.y-range]== -1)
				{
					bot->coordAku.y -= range;
					break;
				}
			}
		}
	}
	int **mapCpy = calloc(map->sizeX, sizeof(int*));
	for(int x = 0; x < map->sizeX; x++)
	{
		mapCpy[x] = calloc(map->sizeY, sizeof(int));
	}
	for(int x = 0; x < map->sizeX; x++)
	{
		for(int y = 0; y < map->sizeY; y++)
		{
			mapCpy[x][y] = -1;
			if(map->vision[bot->isRed][x][y])
			{
				if(map->whole[x][y] != -1)
				{
					mapCpy[x][y] = -3;
				}
			}
		}
	}

	int step = 0;
	mapCpy[bot->pos.x][bot->pos.y] = 0;
	bool changed = true;
	while(mapCpy[bot->coordAku.x][bot->coordAku.y]==-1 && changed)
	{
		changed = false;
		for(int x = 0; x < map->sizeX; x++)
		{
			for(int y = 0; y < map->sizeY; y++)
			{
				if(mapCpy[x][y] == step)
				{
					if(x-1>=0 && y+1<map->sizeY)
					{
						if(mapCpy[x-1][y+1]==-1)
						{
							mapCpy[x-1][y+1] = step+1;
							changed = true;
						}
					}
					if(y+1<map->sizeY)
					{
						if(mapCpy[x][y+1]==-1)
						{
							mapCpy[x][y+1] = step+1;
							changed = true;
						}
					}
					if(x+1<map->sizeX && y+1<map->sizeY)
					{
						if(mapCpy[x+1][y+1]==-1)
						{
							mapCpy[x+1][y+1] = step+1;
							changed = true;
						}
					}
					if(x+1<map->sizeX)
					{
						if(mapCpy[x+1][y]==-1)
						{
							mapCpy[x+1][y] = step+1;
							changed = true;
						}
					}
					if(x+1<map->sizeX && y-1>=0)
					{
						{
							if(mapCpy[x+1][y-1]==-1)
							mapCpy[x+1][y-1] = step+1;
							changed = true;
						}
					}
					if(y-1>=0)
					{
						if(mapCpy[x][y-1]==-1)
						{
							mapCpy[x][y-1] = step+1;
							changed = true;
						}
					}
					if(x-1>=0 && y-1>=0)
					{
						if(mapCpy[x-1][y-1]==-1)
						{
							mapCpy[x-1][y-1] = step+1;
							changed = true;
						}
					}
					if(x-1>=0)
					{
						if(mapCpy[x-1][y]==-1)
						{
							mapCpy[x-1][y] = step+1;
							changed = true;
						}
					}
				}
			}
		}
		step++;
	}
	if(mapCpy[bot->coordAku.x][bot->coordAku.y]==-1)
	{
		bot->integerAku = 0;
		return true;
	}
	bot->pathLength = mapCpy[bot->coordAku.x][bot->coordAku.y]+1;
	if(bot->pathLength <= 0)
	{
		for(int x = 0; x < map->sizeX; x++)
		{
			free(mapCpy[x]);
		}
		free(mapCpy);
		return false;
	}
	point *path = calloc(bot->pathLength, sizeof(point));
	path[bot->pathLength-1].x = bot->coordAku.x;
	path[bot->pathLength-1].y = bot->coordAku.y;
	for(int i = bot->pathLength -1; i>0; i--)
	{
		if(path[i].x-1>=0 && path[i].y+1<map->sizeY)
		{
			if(mapCpy[path[i].x-1][path[i].y+1]==i-1)
			{
				path[i-1].x = path[i].x-1;
				path[i-1].y = path[i].y+1;
				continue;
			}
		}
		if(path[i].y+1<map->sizeY)
		{
			if(mapCpy[path[i].x][path[i].y+1]==i-1)
			{
				path[i-1].x = path[i].x;
				path[i-1].y = path[i].y+1;
				continue;
			}
		}
		if(path[i].x+1<map->sizeX && path[i].y+1<map->sizeY)
		{
			if(mapCpy[path[i].x+1][path[i].y+1]==i-1)
			{
				path[i-1].x = path[i].x+1;
				path[i-1].y = path[i].y+1;
				continue;
			}
		}
		if(path[i].x+1<map->sizeX)
		{
			if(mapCpy[path[i].x+1][path[i].y]==i-1)
			{
				path[i-1].x = path[i].x+1;
				path[i-1].y = path[i].y;
				continue;
			}
		}
		if(path[i].x+1<map->sizeX && path[i].y-1>=0)
		{
			if(mapCpy[path[i].x+1][path[i].y-1]==i-1)
			{
				path[i-1].x = path[i].x+1;
				path[i-1].y = path[i].y-1;
				continue;
			}
		}
		if(path[i].y-1>=0)
		{
			if(mapCpy[path[i].x][path[i].y-1]==i-1)
			{
				path[i-1].x = path[i].x;
				path[i-1].y = path[i].y-1;
				continue;
			}
		}
		if(path[i].x-1>=0 && path[i].y-1>=0)
		{
			if(mapCpy[path[i].x-1][path[i].y-1]==i-1)
			{
				path[i-1].x = path[i].x-1;
				path[i-1].y = path[i].y-1;
				continue;
			}
		}
		if(path[i].x-1>=0)
		{
			if(mapCpy[path[i].x-1][path[i].y]==i-1)
			{
				path[i-1].x = path[i].x-1;
				path[i-1].y = path[i].y;
				continue;
			}
		}
	}
	bot->pathPos = 0;
	for(int x = 0; x < map->sizeX; x++)
	{
		free(mapCpy[x]);
	}
	free(mapCpy);
	bot->path = path;
	return true;
}
bool forwardPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(bot->isBase)
	{
		bot->isAlive = false;
		return false;
	}
	int id;
	if(bot->pathPos < bot->pathLength - 1)
	{
		if(map->whole[bot->path[bot->pathPos+1].x][bot->path[bot->pathPos+1].y]!=-1)return true;
		id = map->whole[bot->pos.x][bot->pos.y];
		map->whole[bot->pos.x][bot->pos.y] = -1;
		bot->pathPos++;
		bot->pos.x = bot->path[bot->pathPos].x;
		bot->pos.y = bot->path[bot->pathPos].y;
		map->whole[bot->pos.x][bot->pos.y] = id;
	}
	visionUpdate(bot, map);
	return true;
}
bool backwardPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(bot->isBase)
	{
		bot->isAlive = false;
		return false;
	}
	int id;
	if(bot->pathPos > 0)
	{
		if(map->whole[bot->path[bot->pathPos-1].x][bot->path[bot->pathPos-1].y]!=-1)return true;
		id = map->whole[bot->pos.x][bot->pos.y];
		map->whole[bot->pos.x][bot->pos.y] = -1;
		bot->pathPos--;
		bot->pos.x = bot->path[bot->pathPos].x;
		bot->pos.y = bot->path[bot->pathPos].y;
		map->whole[bot->pos.x][bot->pos.y] = id;
	}
	visionUpdate(bot, map);
	return true;
}
bool lengthPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	bot->integerAku = bot->pathLength - bot->pathPos - 1;
	return true;
}
bool unobstructedPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	for(int i = bot->pathPos; i < bot->pathLength; i++)
	{
		if(map->vision[bot->isRed][bot->path[i].x][bot->path[i].y])
		{
			if(map->whole[bot->path[i].x][bot->path[i].y]!=-1)
			{
				bot->integerAku = 0;
				return true;
			}
		}
	}
	bot->integerAku = 1;
	return true;
}
bool produceWithPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(!actionLength(bot, 1))return false;
	if(!bot->isBase)
	{
		bot->isAlive = false;
		return false;
	}
	int idT;
	for(idT = 0; idT<1000; idT++)
	{
		if(!tab[idT]->isAlive)break;
	}
	produceC(bot, variable, map, tab);
	findPathC(tab[idT], variable, map, tab);
	return true;
}
