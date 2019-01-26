#ifndef DISPLAY_H
#define DISPLAY_H
#include "robot.h"
#include "map.h"
#include <ncurses.h>

void printMap(map *gameMap, robot *list[ROBOTSLIMIT], WINDOW *mainWin, int px, int py, int sizeX, int sizeY);

#endif
