#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXLENGTH 20//max length of any string representing tag, function name or variable

typedef struct line
{
	char *first;//string with tag
	char *second;//string with name of function
	char *third;//string with argument of function
}line;

typedef struct var
{
	int vid;//value or id of variable
	bool isValue;//if true, vis is value - not id of variable
}var;

char * readWord(FILE *file)//returns NULL if it fails to read word
{
	char *str;
	if((str = malloc(sizeof(char)*MAXLENGTH))==NULL)return NULL;
	if(fscanf(file, "%s", str)==EOF)return NULL;
	return str;
}

int wcl(FILE *file)//counts lines just as wc -l
{
	char buff;
	int lines=1;
	while((buff=fgetc(file))!=EOF)
	{
		if(buff = '\n')lines++;
	}
	fseek(file, 0, SEEK_SET);
	return lines;
}
void readToTab(FILE *file, line tab[])//reads whole file into tab of lines
{
	char *buff;
	int i=0;
	while((buff=readWord(file))!=NULL)
	{
		switch(i%3)
		{
			case 0:
				tab[i].first=buff;
				break;
			case 1:
				tab[i].second=buff;
				break;
			case 2:
				tab[i].third=buff;
				break;

		}
		i++;
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
void makeScript(char *fileName)//returns structure representing scrips of robot
{
	FILE *file = fopen(fileName, "r");
	int lines = wcl(file);
	line *tab= malloc(sizeof(line)*lines);
	int *first = malloc(sizeof(int)*lines);
	int *second = malloc(sizeof(int)*lines);
	var *third = malloc(sizeof(var)*lines);

	readToTab(file, tab);

	tagToId(tab, first, third, lines);

}
int main()
{

}
