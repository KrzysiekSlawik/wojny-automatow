#ifndef COMMANDS_H
#define COMMANDS_H
#include "map.h"
#include "robot.h"
#include "interpreter.h"
void loadIC(robot *bot, var variable, map *map, robot *tab[1000]);
void saveIC(robot *bot, var variable, map *map, robot *tab[1000]);
void loadXC(robot *bot, var variable, map *map, robot *tab[1000]);
void loadYC(robot *bot, var variable, map *map, robot *tab[1000]);
void loadCC(robot *bot, var variable, map *map, robot *tab[1000]);
void saveCC(robot *bot, var variable, map *map, robot *tab[1000]);
void addC(robot *bot, var variable, map *map, robot *tab[1000]);
void subC(robot *bot, var variable, map *map, robot *tab[1000]);
void addXC(robot *bot, var variable, map *map, robot *tab[1000]);
void subXC(robot *bot, var variable, map *map, robot *tab[1000]);
void addYC(robot *bot, var variable, map *map, robot *tab[1000]);
void subYC(robot *bot, var variable, map *map, robot *tab[1000]);
void greaterC(robot *bot, var variable, map *map, robot *tab[1000]);
void equalC(robot *bot, var variable, map *map, robot *tab[1000]);
void jumpC(robot *bot, var variable, map *map, robot *tab[1000]);
#endif
