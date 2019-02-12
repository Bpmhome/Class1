/*
    Bullshit lab
*/
#include<stdio.h>
#include<string.h>
#include"MyStringHeader.h"

int main()
{
    char userInput[256] = {0};
    char * userInputPoint[] = {userInput};

    reverse_it( * userInputPoint, strlen(userInput));
}