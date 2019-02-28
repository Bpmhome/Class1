/*
    Programmer: Grant Ogden
    Date: 2/27/2019
    Filename: lab14.linked_lists.c
    Reason: to better understand structs and linked lists
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node                                     //struct nodes for data storage
{
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
void print_full_list(node_t *head);    

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
void print_specific_element(node_t *head, char output);

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
void print_specific_student(node_t *head, char *student);


int main()
{
    node_t Butler = { "JAB","Picasso","Any"};           //New student Butler
    node_t Young = { "JHY","Eminem","Cruze"};           //New student Young
    node_t Beasley = { "JAB","Erratic","Tesla"};        //New student Beasley
    node_t *current;                                    //*current for use in writing student names later

    int userChoice = 0;                                 //An integer holding the user's choices

    node_t  *head = &Butler;                            //A pointer to the head(begining) of the linked list, Assigned the value of butler
    head->next = &Young;                                //assign the *next to young to link
    head->next->next = &Beasley;                        //assign the *next in young to beasley to link
    head->next->next->next = NULL;                      //assign *next in beasley to NULL because he is the tail

    //Print the Menu for the user and scan in their choicee
    printf("Welcome to the class link list!\n");
    printf("What would you like to do?\n1. Print All Students\n2. Print Specific Fact About Student\n3. Print Specific Student\n\n");
    printf("Enter the Number of Your Choice: ");
    scanf("%d",&userChoice);

    switch (userChoice)                                         
    {
        case 1:                                         //If they selected 1. then print all
            print_full_list(head);
            break;

        case 2:                                         //If the selected 2. present menu to see what data element
            printf("What Fact Do You Want To See?\n1. Favorite Artist\n2. Dream Car\n\n Enter the Number of Your Choice: ");
            scanf("%d",&userChoice);
            if(userChoice == 1)                         //Based on user choice print the selected data element
            {
                print_specific_element(head,'a');
            }
            else if(userChoice == 2)
            {
                print_specific_element(head,'c');
            }
            else
            {
                printf("ERROR");
            }
            break;

        case 3:                                         //If they selected 3. Then print a menu of user initials for them to slect

            current = head;                             //set current equal to the head
            int i = 1;                                  //initialize our counter variable
            char userChoice[4] = {0};                   //char array to hold user's choice of initials

            //print the menu and scan in user input
            printf("Please Select The Student You Want!\n");
            while(current != NULL)
            {
                printf("%d. %s\n",i,current->initials);
                current = current->next;
                i++;
            }
            printf("\nPlease Enter The Students Initials: ");
            scanf("%3s",userChoice);
            print_specific_student(head,userChoice);    //print the specific student
            break;

        default:
            break;
    }

    return 0;
}

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
void print_specific_student(node_t *head, char *student)
{
    node_t *current = head;                             //Set our current pointer to head

    while(current != NULL)                              //While current has value
    {
        if(strcmp(current->initials,student) == 0)      //If the Initials match the one passed in
        {
            //Print that student's information
            printf("Student Initials:\t\t%s\n",current->initials);
            printf("Student Favorite Artist:\t%s\n",current->favArtists);
            printf("Student Dream Car:\t\t%s\n\n",current->dreamCar);
        }
        current = current->next;
    }
}
