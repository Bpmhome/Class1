/*
    Programmer: Grant Ogden
    Date: 2/27/2019
    Filename: lab14.linked_lists.c
    Reason: to better understand structs and linked lists
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node                                                     //struct nodes for data storage
{
    char initials[4];                                                   //4 positions for initials, 4 position is null
    char favArtists[20];                                                //char array of 20 for artist
    char dreamCar[20];                                                  //char array of 20 for car
    struct node *next;                                                  //struct pointer for the next item
}node_t;

void print_full_list(node_t *head);
void print_specific_element(node_t *head, char output);
void print_specific_student(node_t *head, char *student);


int main()
{
    node_t Butler = { "JAB","Picasso","Any"};
    node_t Young = { "JHY","Eminem","Cruze"};
    node_t Beasley = { "JAB","Erratic","Tesla"};
    node_t *current;

    int userChoice = 0;

    node_t  *head = &Butler;
    head->next = &Young;
    head->next->next = &Beasley;
    head->next->next->next = malloc(sizeof(node_t));
    head->next->next->next->next = NULL;

    printf("Welcome to the class link list!\n");
    printf("What would you like to do?\n1. Print All Students\n2. Print Specific Fact About Student\n3. Print Specific Student\n\n");
    printf("Enter the Number of Your Choice: ");
    scanf("%d",&userChoice);

    switch (userChoice)
    {
        case 1:
            print_full_list(head);
            break;

        case 2:
            printf("What Fact Do You Want To See?\n1. Favorite Artist\n2. Dream Car\n\n Enter the Number of Your Choice: ");
            scanf("%d",&userChoice);
            if(userChoice == 1)
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

        case 3:

            current = head;
            int i = 1;
            char userChoice[4] = {0};

            printf("Please Select The Student You Want!\n");
            while(current->next != NULL)
            {
                printf("%d. %s\n",i,current->initials);
                current = current->next;
                i++;
            }
            printf("\nPlease Enter The Students Initials: ");
            scanf("%s",userChoice);
            print_specific_student(head,userChoice);
            break;

        default:
            break;
    }

    return 0;
}

void print_full_list(node_t *head)
{
    node_t *current = head;

    while(current->next != NULL)
    {
        printf("Student Initials:\t\t%s\n",current->initials);
        printf("Student Favorite Artist:\t%s\n",current->favArtists);
        printf("Student Dream Car:\t\t%s\n\n",current->dreamCar);
        current = current->next;
    }   
}

void print_specific_element(node_t *head, char output)
{
    node_t *current = head;

    switch (output)
    {
        case 'a':
            while(current->next != NULL)
            {
                printf("Student Initials:\t\t%s\n",current->initials);
                printf("Student Favorite Artist:\t%s\n\n",current->favArtists);
                current = current->next;
            }
            break;
        case 'c':
            while(current->next != NULL)
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

void print_specific_student(node_t *head, char *student)
{
    node_t *current = head;

    while(current->next != NULL)
    {
        if(strcmp(current->initials,student) == 0)
        {
            printf("Student Initials:\t\t%s\n",current->initials);
            printf("Student Favorite Artist:\t%s\n",current->favArtists);
            printf("Student Dream Car:\t\t%s\n\n",current->dreamCar);
        }
        current = current->next;
    }
}
