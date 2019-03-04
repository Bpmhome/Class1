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

void print_data(list_t *list);

int main()
{
	//Variable Decleration
	data_t myStuff = {1,'o',"Robot"};
	data_t yourStuff = {2,'n',"Merge"};
	list_t *dataHolder = create_list(&myStuff);
	add_node(dataHolder, &myStuff);
	add_node(dataHolder, &yourStuff);
	//Functions called here
	data_t * data = retrieve_specific_data(dataHolder,1);
	print_data(dataHolder);
	return 0;
}

void print_data(list_t *list)
{
	node_t *current = list->head;
	data_t *currentData;
	while(current != NULL)
	{
		currentData = current->data;
		printf("%d\n", currentData->num);
		current = current->next;
	}
}