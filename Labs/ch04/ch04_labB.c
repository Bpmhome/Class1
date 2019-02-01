/*
    Programmer: Grant Ogden
    Date: 2/1/2019
    Filename: ch04_labA.c
    Reason: To practice implentation of getc() and putc()
*/
#include <stdio.h>

int main()
{
    //user input
    char input;
    
    printf("Please input your character to be decremented: ");
    //recieve the users input
    input = getc(stdin);
    printf("The next character is..... ");
    //print the desired answer by adding one
    putc(input - 1,stdout);
    printf("\n");

    return 0;
}
