#include "commands.h"

void loadIC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->integerAku = variable.vid;
	}
	else
	{
		bot->integerAku = bot->integerMem[variable.vid];
	}
}
void saveIC(robot *bot, var variable, map *map, robot *tab[1000])
{
	bot->integerMem[variable.vid] = bot->integerAku;
}
void loadXC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->coordAku.x = variable.vid;
	}
	else
	{
		bot->coordAku.x = bot->integerMem[variable.vid];
	}
}
void loadYC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->coordAku.y = variable.vid;
	}
	else
	{
		bot->coordAku.y = bot->integerMem[variable.vid];
	}
}
void loadCC(robot *bot, var variable, map *map, robot *tab[1000])
{
	bot->coordAku.x = bot->coordMem[variable.vid].x;
	bot->coordAku.y = bot->coordMem[variable.vid].y;
}
void saveCC(robot *bot, var variable, map *map, robot *tab[1000])
{
	bot->coordMem[variable.vid].x = bot->coordAku.x;
	bot->coordMem[variable.vid].y = bot->coordAku.y;
}
void addC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->integerAku += variable.vid;
	}
	else
	{
		bot->integerAku += bot->integerMem[variable.vid];
	}
}
void subC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->integerAku -= variable.vid;
	}
	else
	{
		bot->integerAku -= bot->integerMem[variable.vid];
	}
}
void addXC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->coordAku.x += variable.vid;
	}
	else
	{
		bot->coordAku.x += bot->integerMem[variable.vid];
	}
}
void subXC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->coordAku.x -= variable.vid;
	}
	else
	{
		bot->coordAku.x -= bot->integerMem[variable.vid];
	}
}
void addYC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->coordAku.y += variable.vid;
	}
	else
	{
		bot->coordAku.y += bot->integerMem[variable.vid];
	}
}
void subYC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		bot->coordAku.y -= variable.vid;
	}
	else
	{
		bot->coordAku.y -= bot->integerMem[variable.vid];
	}
}
void greaterC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		if(bot->integerAku > variable.vid)
		{
			bot->integerAku = 1;
		}
		else
		{
			bot->integerAku = 0;
		}
	}
	else
	{
		if(bot->integerAku > bot->integerMem[variable.vid])
		{
			bot->integerAku = 1;
		}
		else
		{
			bot->integerAku = 0;
		}
	}
}
void equalC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(variable.isValue)
	{
		if(bot->integerAku == variable.vid)
		{
			bot->integerAku = 1;
		}
		else
		{
			bot->integerAku = 0;
		}
	}
	else
	{
		if(bot->integerAku == bot->integerMem[variable.vid])
		{
			bot->integerAku = 1;
		}
		else
		{
			bot->integerAku = 0;
		}
	}
}
void jumpC(robot *bot, var variable, map *map, robot *tab[1000])
{
	if(bot->integerAku != 0)
	{
		if(variable.isValue)
		{
			bot->taskCount = variable.vid;
		}
		else
		{
			bot->taskCount = bot->integerMem[variable.vid];
		}
	}
}
