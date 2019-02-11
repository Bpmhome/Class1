/*
    Programmer: Grant Ogden
    Date: 2/1/2018
    Filename: ch04_labC.c
    Reason: To understand fgets() and fputs()
*/
#include <stdio.h>

int main()
{
    char inputString[10] = {0};
    printf("Enter a string 9 characters long: ");
    fgets(inputString,sizeof(inputString),stdin);
    printf("Your string is.....\n");
    fputs(inputString,stdout);
    printf("\n");

    return 0;
}