#include "map.h"
#include "robot.h"
#include "commands.h"
#include "interpreter.h"
#include <stdlib.h>
#include <stdio.h>

map *initMap(int sizeX, int sizeY, int seed, int noisePar, int limitPar)
{
	map *newMap = calloc(1, sizeof(map));
	newMap->whole = calloc(sizeX, sizeof(int*));
	newMap->vision[0] = calloc(sizeX, sizeof(bool*));
	newMap->vision[1] = calloc(sizeX, sizeof(bool*));
	newMap->sizeX = sizeX;
	newMap->sizeY = sizeY;
	for(int i = 0; i < sizeX; i++)
	{
		newMap->vision[0][i] = calloc(sizeY, sizeof(bool));
		newMap->vision[1][i] = calloc(sizeY, sizeof(bool));
		newMap->whole[i] = calloc(sizeY, sizeof(int));
	}
	srand(seed);
	int randV;
	for(int x = 0; x < sizeX; x++)
	{
		for(int y = 0; y < sizeY/2; y++)
		{
			randV = rand()%noisePar - 1;
			if(randV<0)
			{
				randV = -3;
			}
			else randV = -1;
			newMap->whole[x][y] = randV;
		}
	}
	int xVec;
	int yVec;
	for(int i = 0; i < limitPar; i++)
	{
		for(int x = 0; x < sizeX; x++)
		{
			for(int y = 0; y < sizeY/2; y++)
			{
				if(newMap->whole[x][y]==-3)
				{
					xVec = rand()%3 - 1;
					yVec = rand()%3 - 1;
					if(x+xVec<sizeX && y+yVec<sizeY/2 && x+xVec>=0 && y+yVec>=0 )
					{
						newMap->whole[x+xVec][y+yVec] = -3;
						randV = rand()%5;
						if(randV!=1)randV=0;
						newMap->whole[x+xVec][y+yVec] += randV;
					}
				}
			}
		}
	}
	for(int x = 0; x < sizeX; x++)
	{
		for(int y = 0; y < sizeY/2; y++)
		{
			newMap->whole[x][sizeY-1-y]=newMap->whole[x][y];
		}
	}
	for(int x = 0; x < sizeX; x++)
	{
		for(int y = 0; y < sizeY; y++)
		{
			newMap->vision[1][x][y] = true;
		}
	}
	return newMap;
}
void freeMap(map* toFree)
{
	for(int x = 0; x < toFree->sizeX; x++)
	{
		free(toFree->vision[0][x]);
		free(toFree->vision[1][x]);
		free(toFree->whole[x]);
	}
	free(toFree->vision[0]);
	free(toFree->vision[1]);
	free(toFree->whole);
	free(toFree);
}
void initBases(map *gameMap, robot *list[1000])
{
	var variable;
	int i;
	int j = 0;
	variable.vid = 0;
	variable.isValue = false;
	list[0]->hp = 20;
	list[0]->isAlive = true;
	list[0]->isBase = true;
	list[0]->isRed = true;

	list[1]->hp = 20;
	list[1]->isAlive = true;
	list[1]->isBase = true;
	list[1]->isRed = false;
	while(list[0]->integerAku == 0 && j<gameMap->sizeY / 2 - gameMap->sizeY / 10)
	{
		list[0]->integerAku = 1;
		i = 0;
		while(i < gameMap->sizeX / 2)
		{
			if(gameMap->whole[gameMap->sizeX / 2 + i][gameMap->sizeY / 10 + j] == -1)
			{
				list[0]->pos.x = gameMap->sizeX / 2 + i;
				list[0]->pos.y = gameMap->sizeY / 10 + j;
				break;
			}
			if(gameMap->whole[gameMap->sizeX / 2 - i][gameMap->sizeY / 10 + j] == -1)
			{
				list[0]->pos.x = gameMap->sizeX / 2 - i;
				list[0]->pos.y = gameMap->sizeY / 10 + j;
				break;
			}
			i++;
		}
		if(i < gameMap->sizeX / 2)
		{
			list[0]->coordAku.x = list[0]->pos.x;
			list[0]->coordAku.y = gameMap->sizeY - list[0]->pos.y;
			j++;
			findPathC(list[0], variable, gameMap, list);//sets integerAku 0 if cant find path
		}
		else list[0]->integerAku = 0;
	}//when path is found
	list[1]->pos.x = list[0]->pos.x;
	list[1]->pos.y = list[0]->coordAku.y;

	free(list[0]->path);
	list[0]->path = NULL;
	list[0]->coordAku.x = 0;
	list[0]->coordAku.y = 0;
	gameMap->whole[list[0]->pos.x][list[0]->pos.y] = 0;//seting bases on map
	gameMap->whole[list[1]->pos.x][list[1]->pos.y] = 1;

	for(int x = 0; x < gameMap->sizeX; x++)
	{
		for(int y = 0; y < gameMap->sizeY; y++)
		{
			gameMap->vision[1][x][y] = false;
		}
	}
}
