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
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return;
		}
		bot->integerAku = bot->integerMem[variable.vid];
	}
}
void saveIC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.vid < 0 || variable.vid >= ROBOTMEM)
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
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
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
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return;
		}
		bot->coordAku.y = bot->integerMem[variable.vid];
	}
}
void loadCC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.vid < 0 || variable.vid >= ROBOTMEM)
	{
		bot->isAlive = false;
		return;
	}
	bot->coordAku.x = bot->coordMem[variable.vid].x;
	bot->coordAku.y = bot->coordMem[variable.vid].y;
}
void saveCC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.vid < 0 || variable.vid >= ROBOTMEM)
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
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
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
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
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
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
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
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
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
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
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
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
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
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
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
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
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
	if(variable.isValue)
	{
		bot->taskCount = variable.vid;
	}
	else
	{
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
		{
			bot->isAlive = false;
			return;
		}
		bot->taskCount = bot->integerMem[variable.vid];
	}
}
void moveC(robot *bot, var variable, map *map, robot *tab[1000])
{
	int directionValue, xVec=0, yVec=0;
	if(variable.isValue)directionValue = variable.vid;
	else
	{
		if(variable.vid < 0 || variable.vid >= ROBOTMEM)
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
	if(bot->coordAku.x < 0 || bot->coordAku.x >= map->sizeX)
	{
		bot->isAlive = false;
		return;
	}
	if(bot->coordAku.y < 0 || bot->coordAku.y >= map->sizeY)
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
	if(bot->coordAku.x < 0 || bot->coordAku.x >= map->sizeX)
	{
		bot->isAlive = false;
		return;
	}
	if(bot->coordAku.y < 0 || bot->coordAku.y >= map->sizeY)
	{
		bot->isAlive = false;
		return;
	}
	int distance = sqrt(pow(bot->coordAku.x-bot->pos.x,2)+pow(bot->coordAku.y-bot->pos.y,2));
	if(distance>3)return;
	if(map->whole[bot->coordAku.x][bot->coordAku.y]==-2)
	{
		map->whole[bot->coordAku.x][bot->coordAku.y]=rand()%2 - 2;
		map->resources[(int)bot->isRed]++;
	}

}
void produceC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(map->resources[(int)bot->isRed]<10)return;
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
			return;
		}
		idS = bot->integerMem[variable.vid];
	}
	if(idS <= 0)
	{
		bot->isAlive = false;
		return;
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
		return;
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
	free(tab[idT]->path);
	tab[idT]->pathLength = 0;
	tab[idT]->pathPos = 0;
	for(int i = 0; i < ROBOTMEM; i++)
	{
		tab[idT]->coordMem[i].x = 0;
		tab[idT]->coordMem[i].x = 0;
		tab[idT]->integerMem[i] = 0;
	}
	map->resources[(int)bot->isRed]-=10;
}
void howManyUnitsC(robot *bot, var variable, map *map, robot *tab[1000])
{
	int toReturn = 0;
	if(!bot->isBase)
	{
		bot->isAlive = false;
		return;
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
}
void distanceC(robot *bot, var variable, map *map, robot *tab[1000])
{
	int distance = sqrt(pow(bot->coordAku.x-bot->pos.x,2)+pow(bot->coordAku.y-bot->pos.y,2));
	bot->integerAku = distance;
}
void whatIsC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(bot->coordAku.x < 0 || bot->coordAku.x >= map->sizeX)
	{
		bot->isAlive = false;
		return;
	}
	if(bot->coordAku.y < 0 || bot->coordAku.y >= map->sizeY)
	{
		bot->isAlive = false;
		return;
	}
	int ID = map->whole[bot->coordAku.x][bot->coordAku.y];
	if(ID>=0)
	{
		if(bot->isRed == tab[ID]->isRed)
		{
			bot->integerAku = ID;
			return;
		}
		else
		{
			bot->integerAku = -4;
			return;
		}
	}
	else bot->integerAku = ID;
}
void tellC(robot *bot, var variable, map *map, robot *tab[1000])
{
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
			return;
		}
		toIntegerAku = bot->integerMem[variable.vid];
	}
	if(bot->integerAku < 0 || bot->integerAku >= 1000)
	{
		bot->isAlive = false;
		return;
	}
	tab[bot->integerAku]->coordAku = bot->coordAku;
	tab[bot->integerAku]->integerAku = toIntegerAku;
}
void nearestEnemyC(robot *bot, var variable, map *map, robot *tab[1000])
{
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
								return;
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
								return;
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
								return;
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
								return;
							}
						}
					}
				}
			}
		}
	}
}
void nearestFriendC(robot *bot, var variable, map *map, robot *tab[1000])
{
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
								return;
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
								return;
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
								return;
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
								return;
							}
						}
					}
				}
			}
		}
	}
}
void nearestResourceC(robot *bot, var variable, map *map, robot *tab[1000])
{
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
							return;
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
							return;
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
							return;
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
							return;
						}
					}
				}
			}
		}
	}
}
void nearestShadowC(robot *bot, var variable, map *map, robot *tab[1000])
{
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
						return;
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
						return;
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
						return;
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
						return;
					}
				}
			}
		}
	}
}
void myBaseC(robot *bot, var variable, map *map, robot *tab[1000])
{
	for(int i = 0; i < 1000; i++)
	{
		if(tab[i]->isRed == bot->isRed)
		{
			if(tab[i]->isBase)
			{
				bot->coordAku.x = tab[i]->pos.x;
				bot->coordAku.y = tab[i]->pos.y;
				return;
			}
		}
	}
}
void yellC(robot *bot, var variable, map *map, robot *tab[1000])
{
	for(int i = 0; i < 1000; i++)
	{
		if(tab[i]->isRed == bot->isRed)
		{
			tab[i]->coordAku.x = bot->coordAku.x;
			tab[i]->coordAku.y = bot->coordAku.y;
			tab[i]->integerAku = bot->integerAku;
		}
	}
}
void findPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	free(bot->path);
	if(bot->coordAku.x < 0 || bot->coordAku.x >= map->sizeX)
	{
		bot->isAlive = false;
		return;
	}
	if(bot->coordAku.y < 0 || bot->coordAku.y >= map->sizeY)
	{
		bot->isAlive = false;
		return;
	}
	if(map->vision[(int)bot->isRed][bot->coordAku.x][bot->coordAku.y] && map->whole[bot->coordAku.x][bot->coordAku.y]!= -1)
	{
		bot->integerAku = 0;
		return;
	}
	int **mapCpy = malloc(sizeof(int*) * map->sizeX);
	for(int x = 0; x < map->sizeX; x++)
	{
		mapCpy[x] = malloc(sizeof(int) * map->sizeY);
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
	while(mapCpy[bot->coordAku.x][bot->coordAku.y]==-1)
	{
		for(int x = 0; x < map->sizeX; x++)
		{
			for(int y = 0; y < map->sizeY; y++)
			{
				if(mapCpy[x][y] == step)
				{
					if(mapCpy[x-1][y+1]==-1)mapCpy[x-1][y+1] = step+1;
					if(mapCpy[x][y+1]==-1)mapCpy[x][y+1] = step+1;
					if(mapCpy[x+1][y+1]==-1)mapCpy[x+1][y+1] = step+1;
					if(mapCpy[x+1][y]==-1)mapCpy[x+1][y] = step+1;
					if(mapCpy[x+1][y-1]==-1)mapCpy[x+1][y-1] = step+1;
					if(mapCpy[x][y-1]==-1)mapCpy[x][y-1] = step+1;
					if(mapCpy[x-1][y-1]==-1)mapCpy[x-1][y-1] = step+1;
					if(mapCpy[x-1][y]==-1)mapCpy[x-1][y] = step+1;
				}
			}
		}
	}
	bot->pathLength = mapCpy[bot->coordAku.x][bot->coordAku.y]+1;
	point *path = malloc(sizeof(point) * bot->pathLength);
	path[mapCpy[bot->coordAku.x][bot->coordAku.y]].x = bot->coordAku.x;
	path[mapCpy[bot->coordAku.x][bot->coordAku.y]].y = bot->coordAku.y;
	for(int i = mapCpy[bot->coordAku.x][bot->coordAku.y]; i>0; i--)
	{
		if(mapCpy[path[i].x-1][path[i].y+1]==i-1)
		{
			path[i-1].x = path[i].x-1;
			path[i-1].y = path[i].y+1;
			continue;
		}
		if(mapCpy[path[i].x][path[i].y+1]==i-1)
		{
			path[i-1].x = path[i].x;
			path[i-1].y = path[i].y+1;
			continue;
		}
		if(mapCpy[path[i].x+1][path[i].y+1]==i-1)
		{
			path[i-1].x = path[i].x+1;
			path[i-1].y = path[i].y+1;
			continue;
		}
		if(mapCpy[path[i].x+1][path[i].y]==i-1)
		{
			path[i-1].x = path[i].x+1;
			path[i-1].y = path[i].y;
			continue;
		}
		if(mapCpy[path[i].x+1][path[i].y-1]==i-1)
		{
			path[i-1].x = path[i].x+1;
			path[i-1].y = path[i].y-1;
			continue;
		}
		if(mapCpy[path[i].x][path[i].y-1]==i-1)
		{
			path[i-1].x = path[i].x;
			path[i-1].y = path[i].y-1;
			continue;
		}
		if(mapCpy[path[i].x-1][path[i].y-1]==i-1)
		{
			path[i-1].x = path[i].x-1;
			path[i-1].y = path[i].y-1;
			continue;
		}
		if(mapCpy[path[i].x-1][path[i].y]==i-1)
		{
			path[i-1].x = path[i].x-1;
			path[i-1].y = path[i].y;
			continue;
		}
	}
	bot->pathPos = 0;
	for(int x = 0; x < map->sizeX; x++)
	{
		free(mapCpy[x]);
	}
	free(mapCpy);
}
void forwardPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(bot->pathPos < bot->pathLength)
	{
		bot->pathPos++;
		bot->pos.x = bot->path[bot->pathPos].x;
		bot->pos.y = bot->path[bot->pathPos].y;
	}
}
void backwardPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(bot->pathPos > 0)
	{
		bot->pathPos--;
		bot->pos.x = bot->path[bot->pathPos].x;
		bot->pos.y = bot->path[bot->pathPos].y;
	}
}
void lengthPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	bot->integerAku = bot->pathLength - bot->pathPos;
}
void unobstructedPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	for(int i = bot->pathPos; i < bot->pathLength; i++)
	{
		if(map->vision[bot->isRed][bot->path[i].x][bot->path[i].y])
		{
			if(map->whole[bot->path[i].x][bot->path[i].y]!=-1)
			{
				bot->integerAku = 0;
				return;
			}
		}
	}
	bot->integerAku = 1;
}
void produceWithPathC(robot *bot, var variable, map *map, robot *tab[1000])
{
	int idT;
	for(idT = 0; idT<1000; idT++)
	{
		if(!tab[idT]->isAlive)break;
	}
	produceC(bot, variable, map, tab);
	findPathC(tab[idT], variable, map, tab);
}
