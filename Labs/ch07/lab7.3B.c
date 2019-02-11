/*
    Programmer: Grant Ogden
    Date: 2/8/2019
    Filename: lab7.3B.c
    Reason: to better understand while loops
*/
#include<stdio.h>

int main()
{
    //My array of strings seperated by new lines
    char myArry[] = {"Carpe Diem\nRoses are Red\nShit stinks\0"};
    //My counter variable to iterate through my array
    int counter = 0;
    //puts(myArry);

    //while the character isnt a new line or null repeat
    while(myArry[counter] != '\n' && myArry[counter] != '\0')
    {
        //put the character to the string
        putchar(myArry[counter]);
        counter++;
    }
    return 0;
}