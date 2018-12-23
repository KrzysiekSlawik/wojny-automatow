#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXLENGTH 20

typedef struct line
{
	char *first;
	char *second;
	char *third;
}line;

typedef struct var
{
	int vid;
	bool isValue;
}var;

char * readWord(FILE *file, int maxLength)
{
	char *str;
	if((str = malloc(sizeof(char)*maxLength))==NULL)return NULL;
	if(fscanf(file, "%s", str)==EOF)return NULL;
	return str;
}

int wcl(FILE *file)
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
void readToTab(FILE *file, line tab[])
{
	char *buff;
	int i=0;
	while((buff=readWord(file, MAXLENGTH))!=NULL)
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
bool compStr(char *str1, char *str2)
{
	int i=0;
	while(str1[i]!='\0' && str2[i]!='\0')
	{
		if(str1[i]!=str2[i])return false;
		i++;
	}
	return true;
}
void tagToId(line tag[], int tabf[], var tabv[], int length)
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
void makeScript(char *fileName)
{
	FILE *file = fopen(fileName, "r");
	int lines = wcl(file);
	line *tab= malloc(sizeof(line)*lines);
	int *first = malloc(sizeof(int)*lines);
	int *second = malloc(sizeof(int)*lines);
	var *third = malloc(sizeof(var)*lines);

	readToTab(file, tab);

}
int main()
{

}
