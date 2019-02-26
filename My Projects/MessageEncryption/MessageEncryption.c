/*
	Programmer: Grant Ogden
	Date: 2-26-2019
	Project:MessageEncryption
	Reason:
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctime.h>

struct tm tm;

extern int encryptor(char input)
{
	int output = input;

	int cypher1 = tm.tm_mon * 5;
	int cypher2 = tm.tm_mday * 5;
	int cypher3 = tm.tm_year * 5;

	output = (((output / cypher1) + cypher2) * cypher3);

	return output;
}

extern void time_setter()
{
	time_t now = time(NULL);
	tm = *localtime(&now);
}

extern int cypher_set()
{
	
}