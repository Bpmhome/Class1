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
    //My integer array to hold the string
    int myArry[26] ={0};
    //Temporary holding variable
    char userChar = 0;
    //My counter to know how many characters have been put into the array
    int counter = 0;

    //do while the input is not a new line
    do
    {
        userChar = getc(stdin);
        //if the user input is a letter
        if((userChar >= 65 && userChar <= 90) || (userChar >= 97 && userChar <= 122))
        {
            //Take the input and upper it
            userChar = toupper(userChar);
            myArry[counter] = userChar;
            counter++;
        }
    } while (userChar != '\n');
    
    //for every letter input, output to screen
    for(int i = 0; i < counter; i++)
    {
        putchar(myArry[i]);
    }
    
    printf("\n");

    return 0;
}