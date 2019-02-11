/*
    Programmer: Grant Ogden
    Date: 2/7/2019
    Filename: labB7.2.c
    Reason: for better understanding of if-else statements
*/
#include<stdio.h>

//My function to print binary
void printBinary(int number);

int main()
{
    //signed integer that holds our users input
    signed int userInput = 0;

    //lets get that users input!!
    printf("Please input an integer my dude: ");
    scanf("%d",&userInput);
    
    //if the userinput's(cast as an unsigned int for bit minupulation)
    //first bit is a 1 then it is negative
    if(((unsigned int)userInput >> 31) == 1)
    {
        //let them know its negative
        printf("This number is negative!\n");
    }
    else
    {
        //if not negative then give the binary
        printBinary(userInput);
        //then make it negative
        printf("The negative binary is:\n");
        //inverse all of the bits (unsigned int for bit minupulation)
        userInput = ~(unsigned int)userInput;
        //add one for the two's compliment
        userInput++;
    }
    //print the negative number in binary
    printBinary(userInput);
    return 0;
}

void printBinary(signed int number)
{
    //unsigned int to print the binary
    unsigned int bitMask = 1;
    //counter for putting in spaces
    int count = 0;
    //shift to make sure it is in the left most position
    bitMask = bitMask << 31;
    
    //while the mask still holds a bit repeat
    while(bitMask != 0)
    {
        //if count % 4 returns 0 and count isnt 0 then add 
        //a space for binary formating
        if((count % 4)==0 && count != 0)
        {
            printf(" ");
        }
        //if the and operation returns a zero then put a 0
        //otherwise put a 1
        if((bitMask & number) == 0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
        //shift the mask to the right one to check the next position
        bitMask = bitMask >> 1;
        //count that bit
        count++;
    }
    //newline for formatting
    printf("\n");
}