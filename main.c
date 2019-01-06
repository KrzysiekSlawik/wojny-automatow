#include "interpreter.h"
#include <stdlib.h>
#include <stdio.h>
#include "robot.h"
#include "map.h"

int main()
{
	map map;
	robot bot;
	robot **list;
	script *test = makeScript("test");
	test->funcPtr[0](&bot, test->variable[0], &map, list);
	printf("%d", bot.integerAku);
}
