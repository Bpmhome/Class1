#ifndef LINKEDLISTS

#define LINKEDLISTS


typedef struct node                                     //struct nodes for data storage
{
    int ID;
    char initials[4];                                   //4 positions for initials, 4 position is null
    char favArtists[20];                                //char array of 20 for artist
    char dreamCar[20];                                  //char array of 20 for car
    struct node *next;                                  //struct pointer for the next item
}node_t;

/*
 *  FUNCTION:   void print_full_list(node_t *head)
 * 
 *  ARGUEMENTS: node_t *head    -The head of the list to be printed
 * 
 *  RETURN:     VOID
 * 
 *  NOTES:      Prints all of the nodes in the linked list
 */
extern void print_full_list(node_t *head);    

/*
 *  FUNCTION:   void print_specific_element(node_t *head, char output)
 * 
 *  ARGUEMENTS: node_t *head    -The head of the list to be printed
 *              char output     -The selected data element of the output('a'-Artist,'c'-Car)
 * 
 *  RETURN:     VOID
 * 
 *  NOTES:      Prints the students initials and selected data element
 *              'a' - Favorite Artist
 *              'c' - Dream Car
 */
extern void print_specific_element(node_t *head, char output);

/*
 *  FUNCTION:   void print_specific_student(node_t *head, char *student)
 * 
 *  ARGUEMENTS: node_t  *head   -The head of the list to be printed
 *              char *student   -A pointer to the initials of the selected student
 * 
 *  RETURN:     VOID
 * 
 *  NOTES:      If two students have the same initials it will print both of them
 *                  because there isn't a unique ID in this linked list
 *                  (Consider Implementation)
 */
extern void print_specific_student(node_t *head,int ID);

/*
 *  FUNCTION:
 * 
 *  ARGUEMENTS:
 * 
 *  RETURN:
 * 
 *  NOTES:
 */
extern void add_student(node_t *head, node_t *student);

/*
 *  FUNCTION:
 * 
 *  ARGUEMENTS:
 * 
 *  RETURN:
 * 
 *  NOTES:
 */
extern void remove_last_student(node_t *head);

/*
 *  FUNCTION:
 * 
 *  ARGUEMENTS:
 * 
 *  RETURN:
 * 
 *  NOTES:
 */
extern void remove_specific_student(node_t *head,int ID);


#endif