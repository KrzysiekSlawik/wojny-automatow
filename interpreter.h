#ifndef INTERPRETER_H
	#define INTERPRETER_H
	#define MAXLENGTH 20//max length of any string representing tag, function name or variable
	#include <stdbool.h>
	#include <stdio.h>
	#include "map.h"
	#include "robot.h"
	typedef struct var
	{
		int vid;//value or id of variable
		bool isValue;//if true, vis is value - not id of variable
	}var;

	typedef struct line
	{
		char *first;//string with tag
		char *second;//string with name of function
		char *third;//string with argument of function
	}line;

	typedef struct script
	{
		void (**funcPtr)(robot*, var, map*, robot**);
		var *variable;
	}script;

	char * readWord(FILE*);//returns NULL if it fails to read word

	int wcl(FILE*);//counts lines just as wc -l

	void readToTab(FILE*, line*);//reads whole file into tab of lines

	bool compStr(char*, char*);//compares strings, true if strings are the same

	void tagToId(line*, int*, var*, int);//translates tags into ids

	void variableInterpret(line*, var*, int);//translates arguments from string to var structure

	void functionInterpret(line*, void (**funcPtr)(robot*, var, map*, robot**), int);

	script *makeScript(char*);//returns structure representing scripts of robot
#endif
