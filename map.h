#ifndef MAP_H
#define MAP_H


#include <stdbool.h>
typedef struct map
{
	/*	-3 - obstacle
		-2 - gold mine
		-1 -nothing
		0-1000 - units*/
	int sizeX, sizeY;
	int **whole;
	bool **vision[2];
	int resources[2];
}map;
map *initMap(int sizeX, int sizeY, int seed, int noisePar, int limitPar);

#endif
