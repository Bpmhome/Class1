/*
    Programmer: Grant Ogden
    Date: 2/7/2019
    Filename: labA7.2.c
    Reason: For better understanding of the usage of the if() statement
*/
#include<stdio.h>

int main()
{
    //char array for the users input
    char myArry[256] = {0};

    //take users input using chars because the string thing is weird
    printf("Please enter a string my good sir/ma'dam: ");
    scanf("%255[^\n]c",myArry);

    //if the first char is a printable char
    if(myArry[0] >= 32 && myArry[0] < 126)
    {
        //THEN PRINT!!!!
        printf("%s\n",myArry);
    }

    return 0;
}
