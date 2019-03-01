/*
	Programmer: Grant Ogden
	Date: 3-1-2019
	Project:linklists
	Reason:
*/
#include <stdio.h>
#include <stdlib.h>
#include "linklists.h"

list_t * create_list(void * data)
{
	list_t * newList = (list_t *)malloc(sizeof(list_t));
	newList->head = (node_t*)malloc(sizeof(node_t));
	newList->head->data = malloc(sizeof(*data));
	newList->head->data = data;
	newList->head->previous = NULL;
	newList->head->next = NULL;
	newList->numberOfItems = 1;
	newList->head->ID = newList->numberOfItems;
	newList->tail = newList->head;

	return newList;
}

/*
 *  FUNCTION:   void add_student(list_t list, node_t *student)
 * 
 *  ARGUEMENTS: list_t list    -The list of the linked list to add the student to
 *              node_t *student -Pointer to the student's data to add
 * 
 *  RETURN:     VOID
 * 
 *  NOTES:      adds the new student to the end of the list
 */
void add_node(list_t *list, void* data)
{
    list->numberOfItems++;
	list->tail->next = (node_t *)malloc(sizeof(node_t));
	list->tail->next->previous = list->tail;
	list->tail = list->tail->next;
	list->tail->ID = list->numberOfItems;
	list->tail->data = data;
	list->tail->next=NULL;
}

/*
 *  FUNCTION:   void remove_last_student(list_t list)
 * 
 *  ARGUEMENTS: list_t list    -The head of the linked list to remove the student from
 * 
 *  RETURN:     VOID
 * 
 *  NOTES:      removes the last data position from the linked list
 */
void remove_last_index(list_t *list)
{
    node_t *current = list->tail;
	current = current->previous;
	free(current->next);
	current->next = NULL;
}

/*
 *  FUNCTION:   void remove_specific_student(list_t list,int ID)
 * 
 *  ARGUEMENTS: list_t list    -The head of the linked list to remove the student from
 *              int ID          -The unique ID assigned to the student to be removed
 * 
 *  RETURN:     VOID
 * 
 *  NOTES:      removes a specific student given by the ID
 */
void remove_specific_index(list_t *list,int ID)
{
    node_t *current = list->head;

    while(current->next->ID != ID){
        current = current->next;
    }

	node_t *delete = current->next;
    current->next = current->next->next;
	free(delete);
}
