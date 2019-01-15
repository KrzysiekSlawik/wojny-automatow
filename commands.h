#ifndef COMMANDS_H
#define COMMANDS_H
#include "map.h"
#include "robot.h"
#include "interpreter.h"
bool actionLength(robot *bot, int length);
//actual robots commands
bool loadIC(robot *bot, var variable, map *map, robot *tab[1000]);
bool saveIC(robot *bot, var variable, map *map, robot *tab[1000]);
bool loadXC(robot *bot, var variable, map *map, robot *tab[1000]);
bool loadYC(robot *bot, var variable, map *map, robot *tab[1000]);
bool loadCC(robot *bot, var variable, map *map, robot *tab[1000]);
bool saveCC(robot *bot, var variable, map *map, robot *tab[1000]);
bool addC(robot *bot, var variable, map *map, robot *tab[1000]);
bool subC(robot *bot, var variable, map *map, robot *tab[1000]);
bool addXC(robot *bot, var variable, map *map, robot *tab[1000]);
bool subXC(robot *bot, var variable, map *map, robot *tab[1000]);
bool addYC(robot *bot, var variable, map *map, robot *tab[1000]);
bool subYC(robot *bot, var variable, map *map, robot *tab[1000]);
bool greaterC(robot *bot, var variable, map *map, robot *tab[1000]);
bool equalC(robot *bot, var variable, map *map, robot *tab[1000]);
bool jumpC(robot *bot, var variable, map *map, robot *tab[1000]);
bool moveC(robot *bot, var variable, map *map, robot *tab[1000]);
bool attackC(robot *bot, var variable, map *map, robot *tab[1000]);
bool gatherC(robot *bot, var variable, map *map, robot *tab[1000]);
bool produceC(robot *bot, var variable, map *map, robot *tab[1000]);
bool howManyUnitsC(robot *bot, var variable, map *map, robot *tab[1000]);
bool distanceC(robot *bot, var variable, map *map, robot *tab[1000]);
bool whatIsC(robot *bot, var variable, map *map, robot *tab[1000]);
bool tellC(robot *bot, var variable, map *map, robot *tab[1000]);
bool nearestEnemyC(robot *bot, var variable, map *map, robot *tab[1000]);
bool nearestFriendC(robot *bot, var variable, map *map, robot *tab[1000]);
bool nearestResourceC(robot *bot, var variable, map *map, robot *tab[1000]);
bool nearestShadowC(robot *bot, var variable, map *map, robot *tab[1000]);
bool myBaseC(robot *bot, var variable, map *map, robot *tab[1000]);
bool yellC(robot *bot, var variable, map *map, robot *tab[1000]);
bool findPathC(robot *bot, var variable, map *map, robot *tab[1000]);
bool forwardPathC(robot *bot, var variable, map *map, robot *tab[1000]);
bool backwardPathC(robot *bot, var variable, map *map, robot *tab[1000]);
bool lengthPathC(robot *bot, var variable, map *map, robot *tab[1000]);
bool unobstructedPathC(robot *bot, var variable, map *map, robot *tab[1000]);
bool produceWithPathC(robot *bot, var variable, map *map, robot *tab[1000]);
#endif
