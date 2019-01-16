#include "interpreter.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "interpreter.h"
#include "robot.h"
#include "commands.h"
#include "map.h"


char * readWord(FILE *file)//returns NULL if it fails to read word
{
	char *str;
	if((str = malloc(sizeof(char)*MAXLENGTH))==NULL)return NULL;
	if(fscanf(file, "%s", str)==EOF)
	{
		free(str);
		return NULL;
	}
	return str;
}

int wcl(FILE *file)//counts lines just as wc -l
{
	char buff;
	int lines=0;
	while((buff=fgetc(file))!=EOF)
	{
		if(buff == '\n')lines++;
	}
	fseek(file, 0, SEEK_SET);
	return lines;
}
void readToTab(FILE *file, line tab[])//reads whole file into tab of lines
{
	char *buff;
	int i=0;
	int k=0;
	while((buff=readWord(file))!=NULL)
	{
		switch(k%3)
		{
			case 0:
				tab[i].first=buff;
				break;
			case 1:
				tab[i].second=buff;
				break;
			case 2:
				tab[i].third=buff;
				i++;
				break;
		}
		k++;
	}
}
bool compStr(char *str1, char *str2)//compares strings, true if strings are the same
{
	int i=0;
	while(str1[i]!='\0' && str2[i]!='\0')
	{
		if(str1[i]!=str2[i])return false;
		i++;
	}
	return true;
}
void tagToId(line tag[], int tabf[], var tabv[], int length)//translates tags into ids
{
	for(int i=0; i<length; i++)
	{
		if(compStr(tag[i].first,"_"))tabf[i]=i;
		else
		{
			tabf[i]=i;
			for(int j=0; j<length; j++)
			{
				if(compStr(tag[i].first, tag[j].third))
				{
					tabv[j].vid = i;
					tabv[j].isValue = true;
				}
			}
		}
	}
}
void variableInterpret(line tag[], var tabv[], int length)//translates arguments from string to var structure
{
	for(int i=0; i<length; i++)
	{
		if(tag[i].third[0]=='=')
		{
			tabv[i].isValue = true;
			tabv[i].vid = atoi(tag[i].third + 1);
			continue;
		}
		if(tag[i].third[0]>='0' && tag[i].third[0]<='9')
		{
			tabv[i].isValue = false;
			tabv[i].vid = atoi(tag[i].third);
			continue;
		}
	}
}
void functionInterpret(bool (*listfuncPtr[])(robot*, var, map*, robot**), char **functions, line tag[], bool (**funcPtr)(robot*, var, map*, robot**), int length)
{
	for(int i=0; i<length; i++)
	{
		int j=0;
		while(!compStr(functions[j], tag[i].second))
		{
			j++;
		}
		funcPtr[i]=listfuncPtr[j];
	}
}

script *makeScript(char *fileName)//returns structure representing scripts of robot
{
	char *functions[35];
	//list of commands from commands.h
	functions[0] = "loadI";
	functions[1] = "saveI";
	functions[2] = "loadX";
	functions[3] = "loadY";
	functions[4] = "loadC";
	functions[5] = "saveC";
	functions[6] = "add";
	functions[7] = "sub";
	functions[8] = "addX";
	functions[9] = "subX";
	functions[10] = "addY";
	functions[11] = "subY";
	functions[12] = "greater";
	functions[13] = "equal";
	functions[14] = "jump";
	functions[15] = "move";
	functions[16] = "attack";
	functions[17] = "gather";
	functions[18] = "produce";
	functions[19] = "howManyUnits";
	functions[20] = "distance";
	functions[21] = "whatIs";
	functions[22] = "tell";
	functions[23] = "nearestEnemy";
	functions[24] = "nearestFriendC";
	functions[25] = "nearestResource";
	functions[26] = "nearestShadow";
	functions[27] = "myBase";
	functions[28] = "yell";
	functions[29] = "findPath";
	functions[30] = "forwardPath";
	functions[31] = "backwardPath";
	functions[32] = "lengthPath";
	functions[33] = "forwardunobstructedPath";
	functions[34] = "produceWithPath";

	bool (*listfuncPtr[35])(robot*, var, map*, robot**)={loadIC, saveIC, loadXC,
		loadYC, loadCC, saveCC, addC, subC, addXC, subXC, addYC, subYC, greaterC,
		equalC, jumpC, moveC, attackC, gatherC, produceC, howManyUnitsC, distanceC,
		whatIsC, tellC, nearestEnemyC, nearestFriendC, nearestResourceC, nearestShadowC,
		myBaseC, yellC, findPathC, forwardPathC, backwardPathC, lengthPathC,
		unobstructedPathC, produceWithPathC};

	FILE *file = fopen(fileName, "r");
	if(file==NULL)
	{
		return NULL;
	}
	int lines = wcl(file);
	line *tab= malloc(sizeof(line)*lines);
	int *first = malloc(sizeof(int)*lines);
	bool (**funcPtr)(robot*, var, map*, robot**) = malloc(sizeof(long int)*lines);
	var *third = malloc(sizeof(var)*lines);

	readToTab(file, tab);

	variableInterpret(tab, third, lines);

	tagToId(tab, first, third, lines);

	functionInterpret(listfuncPtr, functions, tab, funcPtr, lines);

	script *new=malloc(sizeof(script));
	new->funcPtr=funcPtr;
	new->variable=third;
	new->length = lines;
	//freeing memory
	for(int i=0; i<lines; i++)
	{
		//if(tab[i].first)free(tab[i].first);
		//if(tab[i].second)free(tab[i].second);
		//if(tab[i].third)free(tab[i].third);
	}
	//free(tab);
	//free(first);
	fclose(file);
	return new;
}
void freeScript(script *scr)
{
	for(int i = 0; i<scr->length; i++)
	{
		free(scr->funcPtr[i]);
	}
	free(scr->variable);
	free(scr);
}
int tickRobots(script *book, robot *tab[1000],  map *map)
{
	for(int i = 0; i < 1000; i++)
	{
		if(tab[i]->taskCount>=book->length)tab[i]->isAlive = false;
		if(tab[i]->isAlive)
		{
			if(book->funcPtr[tab[i]->taskCount]
				(tab[i], book->variable[tab[i]->taskCount], map, tab))
			{
				if(tab[i]->taskCount<book->length)
				{
					tab[i]->taskCount++;
					printf("%d ", tab[i]->taskCount);
				}
			}
		}
	}
}
