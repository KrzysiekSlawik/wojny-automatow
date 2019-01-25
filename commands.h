#ifndef COMMANDS_H
#define COMMANDS_H
#include "map.h"
#include "robot.h"
#include "interpreter.h"
bool actionLength(robot *bot, int length);
bool visionUpdate(robot *bot, map *map);
//actual robots commands
bool loadIC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool saveIC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool loadXC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool loadYC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool loadCC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool saveCC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool addC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool subC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool addXC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool subXC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool addYC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool subYC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool greaterC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool equalC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool jumpC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool moveC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool attackC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool gatherC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool produceC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool howManyUnitsC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool distanceC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool whatIsC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool tellC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool nearestEnemyC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool nearestFriendC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool nearestResourceC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool nearestShadowC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool myBaseC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool yellC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool findPathC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool forwardPathC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool backwardPathC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool lengthPathC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool unobstructedPathC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
bool produceWithPathC(robot *bot, var variable, map *map, robot *tab[ROBOTSLIMIT]);
#endif
