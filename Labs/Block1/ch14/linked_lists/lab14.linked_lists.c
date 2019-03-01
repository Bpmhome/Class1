/*
    Programmer: Grant Ogden
    Date: 2/27/2019
    Filename: lab14.linked_lists.c
    Reason: to better understand structs and linked lists
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_lists.h"




int main()
{
    node_t Butler = { 1,"JAB","Picasso","Any",};           //New student Butler
    node_t Young = { 2,"JHY","Eminem","Cruze"};           //New student Young
    node_t Beasley = { 3,"JAB","Erratic","Tesla"};        //New student Beasley
    node_t *current;                                    //*current for use in writing student names later

    int userChoice = 0;                                 //An integer holding the user's choices

    node_t  *head = &Butler;                            //A pointer to the head(begining) of the linked list, Assigned the value of butler
    head->next = &Young;                                //assign the *next to young to link
    head->next->next = &Beasley;                        //assign the *next in young to beasley to link
    head->next->next->next = NULL;                      //assign *next in beasley to NULL because he is the tail

    do
    {
    
        //Print the Menu for the user and scan in their choicee
        printf("Welcome to the class link list!\n");

        printf("Would you like to...\n1. Edit List\n2. View List\n0. To Exit\nEnter the Number of Your Choice: ");
        scanf("%d",&userChoice);

        if(userChoice == 1)
        {
            printf("What would you like to do?\n1. Add Student\n2. Remove Last Student\n3. Remove Specific Student\n");
            printf("Enter the Number of Your Choice: ");
            scanf("%d",&userChoice);

            switch (userChoice)
            {
                case 1:
                    ;
                    node_t *newStudent = (node_t*)malloc(sizeof(node_t));
                    newStudent->next = NULL;
                    printf("Enter Student Initials: ");
                    scanf("%3s",newStudent->initials);
                    printf("Enter Student's Favorite Artist: ");
                    scanf("%19s",newStudent->favArtists);
                    printf("Enter Student's Dream Car: ");
                    scanf("%19s",newStudent->dreamCar);
                    add_student(head,newStudent);
                    print_full_list(head);
                    break;

                case 2:
                    remove_last_student(head);
                    print_full_list(head);
                    break;

                case 3:                                         //If they selected 3. Then print a menu of user initials for them to slect

                    current = head;                             //set current equal to the head
                    int i = 1;                                  //initialize our counter variable

                    //print the menu and scan in user input
                    printf("Please Select The Student You Want!\n");
                    while(current != NULL)
                    {
                        printf("%d. %s\n",i,current->initials);
                        current = current->next;
                        i++;
                    }
                    printf("\nPlease Enter The Number of the Student: ");
                    scanf("%d",&userChoice);
                    remove_specific_student(head,userChoice);   //remove said student
                    print_full_list(head);
                    break;

                default:
                    break;
            }
        }
        else if(userChoice == 2)
        {
            printf("What would you like to do?\n1. Print All Students\n2. Print Specific Fact About Student\n3. Print Specific Student\n\n");
            printf("Enter the Number of Your Choice: ");
            scanf("%d",&userChoice);

            switch (userChoice)                                         
            {
                case 1:                                         //If they selected 1. then print all
                    print_full_list(head);
                    break;

                case 2:                                         //If the selected 2. present menu to see what data element
                    printf("What Fact Do You Want To See?\n1. Favorite Artist\n2. Dream Car\n\nEnter the Number of Your Choice: ");
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

                    //print the menu and scan in user input
                    printf("Please Select The Student You Want!\n");
                    while(current != NULL)
                    {
                        printf("%d. %s\n",i,current->initials);
                        current = current->next;
                        i++;
                    }
                    printf("\nPlease Enter The Number of the Student: ");
                    scanf("%d",&userChoice);
                    print_specific_student(head,userChoice);    //print the specific student
                    break;

                default:
                    break;
            }
        }
    }while(userChoice != 0);
    

    return 0;
}
