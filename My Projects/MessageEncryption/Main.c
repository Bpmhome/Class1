/*
	Programmer: Grant Ogden
	Date: 2-26-2019
	Project:MessageEncryption
	Reason:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
	//Variable Decleration
	if(argc == 1)
	{
		printf("encrypt.out <input file.txt> <encrypted filename>\n");
	}
	if(argc == 2)
	{
		if(strcmp("help",argv[1]) == 0)
		{
			printf("encrypt.out <input file.txt>\t\tTo Decrypt\n");
			printf("encrypt.out <input file.txt> <encrypted filename> \tTo Encrypt");
		}
		else 
		{
			
		}
	}
	//Functions called here

	return 0;
}