/*
    Programmer: Grant Ogden
    Date: 2/1/2019
    Filename: ch04_labA.c
    Reason: To practice implentation of getchar() and putchar()
*/
#include <stdio.h>

int main()
{
    //user input
    char input;
    
    printf("Please input your character to be incremented: ");
    //recieve the users input
    input = getchar();
    printf("The next character is.....");
    //print the desired answer by adding one
    putchar(input + 1);
    printf("\n");

    return 0;
}
