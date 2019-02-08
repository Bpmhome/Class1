/*
    Programmer: Grant Ogden
    Date: 2/8/2019
    Filename: lab7.3B.c
    Reason: to better understand while loops
*/
#include<stdio.h>

int main()
{
    char myArry[] = {"Carpe Diem\nRoses are Red\nShit stinks\0"};
    int counter = 0;
    puts(myArry);

    while(myArry[counter] != '\n' && myArry[counter] != '\0')
    {
        putchar(myArry[counter]);
        counter++;
    }

    return 0;
}