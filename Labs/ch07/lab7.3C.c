/*
    Programmer: Grant Ogden
    Date:2/8/2019
    Filename: lab7.3C.c
    Reason: To better understand do while loops
*/
#include<stdio.h>
#include<ctype.h>

int main()
{
    int myArry[26] ={0};
    char userChar = 0;
    int counter = 0;

    do
    {
        userChar = getc(stdin);
        if((userChar >= 65 && userChar <= 90) || (userChar >= 97 && userChar <= 122))
        {
            userChar = toupper(userChar);
            myArry[counter] = userChar;
            counter++;
        }
    } while (userChar != '\n');
    
    for(int i = 0; i < counter; i++)
    {
        putchar(myArry[i]);
    }
    
    printf("\n");

    return 0;
}