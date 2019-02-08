/*
    Programmer: Grant Ogden
    Date: 2/7/2019
    Filename: labD7.2.c
    Reason: To better understand switch case statements and how to use them
*/
#include<stdio.h>

int main()
{
    int userInput1 = 0;
    int userInput2 = 0;
    char operator = 0;

    printf("Please enter two numbers seperated by an operator (+,-,*,/): ");
    scanf("%d%[/*-+]c%d",&userInput1,&operator,&userInput2);
    printf("%d\n",userInput2);
    printf("%d%c%d\n",userInput1,operator,userInput2);
}