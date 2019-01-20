#include "map.h"
#include <stdlib.h>
#include <stdio.h>

map *initMap(int sizeX, int sizeY, int seed, int noisePar, int limitPar)
{
	map *newMap = malloc(sizeof(map));
	newMap->whole = malloc(sizeof(int*)*sizeX);
	newMap->vision[0] = malloc(sizeof(bool*)*sizeX);
	newMap->vision[1] = malloc(sizeof(bool*)*sizeX);
	newMap->sizeX = sizeX;
	newMap->sizeY = sizeY;
	for(int i = 0; i < sizeX; i++)
	{
		newMap->vision[0][i] = malloc(sizeof(bool)*sizeY);
		newMap->vision[1][i] = malloc(sizeof(bool)*sizeY);
		newMap->whole[i] = malloc(sizeof(int)*sizeY);
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
			newMap->vision[0][x][y]=true;
			newMap->vision[1][x][y]=true;
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
