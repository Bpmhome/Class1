/*
	Programmer: Grant Ogden
	Date: 3-1-2019
	Project:linklists
	Reason:
*/
#ifndef LINKEDLISTS

#define LINKEDLISTS


typedef struct node                                     //struct nodes for data storage
{
	int ID; 
    struct node *previous;
	void *data;
    struct node *next;                                  //struct pointer for the next item
}node_t;

typedef struct list
{
	node_t *head;
	node_t *tail;
	int numberOfItems;
}list_t;

/*
 *  FUNCTION:   void add_student(node_t *head, node_t *student)
 * 
 *  ARGUEMENTS: node_t *head    -The head of the linked list to add the student to
 *              node_t *student -Pointer to the student's data to add
 * 
 *  RETURN:     VOID
 * 
 *  NOTES:      adds the new student to the end of the list
 */
extern list_t * create_list(void *data);

/*
 *  FUNCTION:   void add_student(node_t *head, node_t *student)
 * 
 *  ARGUEMENTS: node_t *head    -The head of the linked list to add the student to
 *              node_t *student -Pointer to the student's data to add
 * 
 *  RETURN:     VOID
 * 
 *  NOTES:      adds the new student to the end of the list
 */
extern void add_node(list_t *list, void *data);

/*
 *  FUNCTION:   void remove_last_student(node_t *head)
 * 
 *  ARGUEMENTS: node_t *head    -The head of the linked list to remove the student from
 * 
 *  RETURN:     VOID
 * 
 *  NOTES:      removes the last data position from the linked list
 */
extern void remove_last_index(list_t *list);

/*
 *  FUNCTION:   void remove_specific_student(node_t *head,int ID)
 * 
 *  ARGUEMENTS: node_t *head    -The head of the linked list to remove the student from
 *              int ID          -The unique ID assigned to the student to be removed
 * 
 *  RETURN:     VOID
 * 
 *  NOTES:      removes a specific student given by the ID
 */
extern void remove_specific_index(list_t *list,int ID);

/*
 *  FUNCTION:   void remove_specific_student(node_t *head,int ID)
 * 
 *  ARGUEMENTS: node_t *head    -The head of the linked list to remove the student from
 *              int ID          -The unique ID assigned to the student to be removed
 * 
 *  RETURN:     VOID
 * 
 *  NOTES:      removes a specific student given by the ID
 */
extern void* retrieve_specific_data(list_t *list,int ID);



#endif