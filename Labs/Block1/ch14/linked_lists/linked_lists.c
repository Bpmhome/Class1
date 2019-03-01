#include <stdio.h>
#include <stdlib.h>
#include "linked_lists.h"

/*
 *  FUNCTION:   void print_full_list(node_t *head)
 * 
 *  ARGUEMENTS: node_t *head    -The head of the list to be printed
 * 
 *  RETURN:     VOID
 * 
 *  NOTES:      Prints all of the nodes in the linked list
 */
void print_full_list(node_t *head)
{
    node_t *current = head;                             //Set our current pointer to head

    while(current != NULL)                              //while current has value
    {
        //print the values of current
        printf("Student ID:\t\t%d\n",current->ID);
        printf("Student Initials:\t\t%s\n",current->initials);
        printf("Student Favorite Artist:\t%s\n",current->favArtists);
        printf("Student Dream Car:\t\t%s\n\n",current->dreamCar);

        //set current to the next value
        current = current->next;
    }   
}

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
void print_specific_element(node_t *head, char output)
{
    node_t *current = head;                             //Set our current pointer to head

    switch (output)                                     //Based on the passed input choose what to output
    {
        case 'a':                                       //If a then output Artist
            while(current != NULL)
            {
                printf("Student Initials:\t\t%s\n",current->initials);
                printf("Student Favorite Artist:\t%s\n\n",current->favArtists);
                current = current->next;
            }
            break;

        case 'c':                                       //If c then output Car
            while(current != NULL)
            {
                printf("Student Initials:\t\t%s\n",current->initials);
                printf("Student Dream Car:\t\t%s\n\n",current->dreamCar);
                current = current->next;
            }
            break;

        default:
            printf("ERROR");
            break;
    }
}

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
void print_specific_student(node_t *head,int ID)
{
    node_t *current = head;                             //Set our current pointer to head

    while(current != NULL)                              //While current has value
    {
        if(current->ID == ID)      //If the Initials match the one passed in
        {
            //Print that student's information
            printf("Student Initials:\t\t%s\n",current->initials);
            printf("Student Favorite Artist:\t%s\n",current->favArtists);
            printf("Student Dream Car:\t\t%s\n\n",current->dreamCar);
        }
        current = current->next;
    }
}

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
void add_student(node_t *head, node_t *student)
{
    node_t *current = head;
    int i = 1;
    
    while(current->next != NULL){
        current = current->next;
        i++;
    }

    current->next = student;
    current->next->ID = i + 1;
}

/*
 *  FUNCTION:   void remove_last_student(node_t *head)
 * 
 *  ARGUEMENTS: node_t *head    -The head of the linked list to remove the student from
 * 
 *  RETURN:     VOID
 * 
 *  NOTES:      removes the last data position from the linked list
 */
void remove_last_student(node_t *head)
{
    node_t *current = head;

    while(current->next->next != NULL)
    {
        current = current->next;
    }

    free(current->next->next);
    current->next = NULL;
}

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
void remove_specific_student(node_t *head,int ID)
{
    node_t *current = head;

    while(current->next->ID != ID){
        current = current->next;
    }

    free(current->next);
    current->next = current->next->next;
}
