#ifndef MAP_H
#define MAP_H

#define MAPSIZE 100

#include <stdbool.h>
typedef struct map
{
	/*	-3 - obstacle
		-2 - gold mine
		-1 -nothing
		0-1000 - units*/
	int whole[MAPSIZE][MAPSIZE];
	bool vision[2][MAPSIZE][MAPSIZE];
}map;

#endif
