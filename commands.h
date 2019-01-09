#ifndef COMMANDS_H
#define COMMANDS_H
#include "map.h"
#include "robot.h"
#include "interpreter.h"
//actual robots commands
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
void moveC(robot *bot, var variable, map *map, robot *tab[1000]);
void attackC(robot *bot, var variable, map *map, robot *tab[1000]);
void gatherC(robot *bot, var variable, map *map, robot *tab[1000]);
void produceC(robot *bot, var variable, map *map, robot *tab[1000]);
void howManyUnitsC(robot *bot, var variable, map *map, robot *tab[1000]);
void distanceC(robot *bot, var variable, map *map, robot *tab[1000]);
void whatIsC(robot *bot, var variable, map *map, robot *tab[1000]);
void tellC(robot *bot, var variable, map *map, robot *tab[1000]);
void nearestEnemyC(robot *bot, var variable, map *map, robot *tab[1000]);
void nearestFriendC(robot *bot, var variable, map *map, robot *tab[1000]);
void nearestResourceC(robot *bot, var variable, map *map, robot *tab[1000]);
void nearestShadowC(robot *bot, var variable, map *map, robot *tab[1000]);
void myBaseC(robot *bot, var variable, map *map, robot *tab[1000]);
void yellC(robot *bot, var variable, map *map, robot *tab[1000]);
void findPathC(robot *bot, var variable, map *map, robot *tab[1000]);
void forwardPathC(robot *bot, var variable, map *map, robot *tab[1000]);
void backwardPathC(robot *bot, var variable, map *map, robot *tab[1000]);
void lengthPathC(robot *bot, var variable, map *map, robot *tab[1000]);
void unobstructedPathC(robot *bot, var variable, map *map, robot *tab[1000]);
void produceWithPathC(robot *bot, var variable, map *map, robot *tab[1000]);
#endif
