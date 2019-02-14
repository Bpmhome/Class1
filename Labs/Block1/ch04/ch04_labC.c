/*
    Programmer: Grant Ogden
    Date: 2/1/2018
    Filename: ch04_labC.c
    Reason: To understand fgets() and fputs()
*/
#include <stdio.h>

int main()
{
    //decleartion and zeroising of the char array
    char inputString[10] = {0};
    //grab the users input
    printf("Enter a string 9 characters long: ");
    fgets(inputString,sizeof(inputString),stdin);
    //give it back to them
    printf("Your string is.....\n");
    fputs(inputString,stdout);
    printf("\n");

    return 0;
}