/*
	Programmer: Grant Ogden
	Date: 3-1-2019
	Project:linklists
	Reason:
*/
#include <stdio.h>
#include "linklists.h"


typedef struct data{
	int num;
	char letter;
	char string[10];
}data_t;

int main()
{
	//Variable Decleration
	data_t myStuff = {1,'o',"Robot"};
	list_t *dataHolder = create_list(&myStuff);
	//Functions called here
	(data_t *)(dataHolder->head->data)->num;

	return 0;
}