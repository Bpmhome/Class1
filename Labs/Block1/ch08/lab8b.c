/*
    Programmer: Grant Ogden
    Date: 2/14/2019
    Filename: lab8b.c
    Reason: To better understand functions in header files
*/
#include<stdio.h>
#include<string.h>
#include"MyStringHeader.h"

int main()
{
    //variable decleration
    char userInput[100] = {0};

    //get the string from the user
    fprintf(stdout,"Please input a string to have it reversed: \n");
    fscanf(stdin,"%255[^\n]c",userInput);

    //reverse it
    reverse_it(userInput, strlen(userInput));
    
    //spit it back out to them
    fprintf(stdout,"%s \n",userInput);
}