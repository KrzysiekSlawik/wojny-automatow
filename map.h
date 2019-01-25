#ifndef MAP_H
#define MAP_H


#include <stdbool.h>
#include "robot.h"
typedef struct map
{
	/*	-3 - obstacle
		-2 - gold mine
		-1 -nothing
		0-ROBOTSLIMIT - units*/
	int sizeX, sizeY;
	int **whole;
	bool **vision[2];
	int resources[2];
}map;
map *initMap(int sizeX, int sizeY, int seed, int noisePar, int limitPar);
void freeMap(map*);
void initBases(map *gameMap, robot *list[ROBOTSLIMIT]);
map *initMapfromCF(char *name);
#endif
