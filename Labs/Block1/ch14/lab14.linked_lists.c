/*
    Programmer: Grant Ogden
    Date: 2/27/2019
    Filename: lab14.linked_lists.c
    Reason: to better understand structs and linked lists
*/
#include <stdio.h>
#include <stdlib.h>

struct student
{
    char intials[3];
    char favArtits[40];
    char dreamCar[40];
};

struct node
{
    void *data;
    struct node *next;
};




int main()
{
    
}