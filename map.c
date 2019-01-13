#include "map.h"
#include <stdlib.h>
#include <stdio.h>

map *initMap(int sizeX, int sizeY, int seed, int noisePar, int limitPar)
{
	map *map = malloc(sizeof(map));
	map->whole = malloc(sizeof(int*)*sizeX);
	map->vision[0] = malloc(sizeof(bool*)*sizeX);
	map->vision[1] = malloc(sizeof(bool*)*sizeX);
	for(int i = 0; i < sizeX; i++)
	{
		map->vision[0][i] = malloc(sizeof(bool)*sizeY);
		map->vision[1][i] = malloc(sizeof(bool)*sizeY);
		map->whole[i] = malloc(sizeof(int)*sizeY);
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
			map->whole[x][y] = randV;
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
				if(map->whole[x][y]==-3)
				{
					xVec = rand()%3 - 1;
					yVec = rand()%3 - 1;
					if(x+xVec<sizeX && y+yVec<sizeY/2 && x+xVec>=0 && y+yVec>=0 )
					{
						map->whole[x+xVec][y+yVec] = -3;
						randV = rand()%5;
						if(randV!=1)randV=0;
						map->whole[x+xVec][y+yVec] += randV;
					}
				}
			}
		}
	}
	for(int x = 0; x < sizeX; x++)
	{
		for(int y = 0; y < sizeY/2; y++)
		{
			map->whole[x][sizeY-1-y]=map->whole[x][y];
		}
	}
	return map;
}
