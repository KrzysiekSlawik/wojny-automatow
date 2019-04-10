#ifndef DISPLAY_H
#define DISPLAY_H
#include "robot.h"
#include "map.h"
#include <ncurses.h>
void initDisplay();
void setDelay(int delay);
WINDOW *initWindow(int winSizeY, int winSizeX, int y, int x);
void delWindow(WINDOW *win);
void endDisplay();
void printMap(map *gameMap, robot *list[ROBOTSLIMIT], WINDOW *mainWin, int px, int py, int sizeX, int sizeY, WINDOW *statsWin);

#endif
