/*
    Bullshit lab
*/
#include<stdio.h>
#include<string.h>
#include"MyStringHeader.h"

int main()
{
    char userInput[100] = {0};
    char * userInputPoint[] = {userInput};

    fprintf(stdout,"Please input a string to have it reversed: \n");
    fscanf(stdin,"%255[^\n]c",userInput);

    reverse_it(userInput, strlen(userInput));
    
    fprintf(stdout,"%s \n",userInput);
}