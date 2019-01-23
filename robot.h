#ifndef ROBOT_H
#define ROBOT_H

#include <stdbool.h>
#define ROBOTMEM 10
typedef struct point	{
	int x, y;
}point;
typedef struct robot	{
	int hp;//hit points
	point pos;//curent possition of robot
	int taskCount, taskCountBis;//taskCount which instruction should be executed
	bool isAlive, isRed, isWar, isSupp, isBase;//isRed to get nation of robot
	point coordAku;//akumulator for coordinates
	int integerAku;//akumulator for integer values
	point coordMem[ROBOTMEM];
	int integerMem[ROBOTMEM];//memory of robot
	int stratId;//id of strategy script
	point *path;
	int pathLength;
	int pathPos;
}robot;
#endif
