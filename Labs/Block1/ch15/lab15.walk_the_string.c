/*
    Programmer: Grant Ogden
    Date: 3/4/2019
    Filename: lab15.walk_the_sting.c
    Reason: To better understand errorhandling in c
*/
#include <stdio.h>
#include <assert.h>

int main()
{
    char string[10] = {0};

    printf("Please enter a string: ");
    scanf("%49s",string);

    assert(string[9]=='\0');

    printf("The string: %s",string);

    printf("\nPlease enter a 10 letter string: ");
    scanf("%s",string);

    assert(string[9]=='\0');

    return 0;
}