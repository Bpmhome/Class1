/*
    Programmer: Grant Ogden
    Date: 2/7/2019
    Filename: ch06_Lab6A.c
    Reason: to better understand bitwise operators and minipulation of the bits
*/
#include<stdio.h>
#include<inttypes.h>

int main()
{
    //User Input
    uint32_t userInput = 0;
    //Variable used to check binary positions. Defaulted so only the right most bit is on
    uint32_t bitChecker = 0x01;
    //Counter used for spacing into bytes
    int counter = 0;

    //retrieve users input
    printf("Please enter a positive integer: ");
    fscanf(stdin,"%u",&userInput);

    //ensure that only the left most bit is on by shifting
    bitChecker = bitChecker << 31;


    printf("Your number in binary is:\n");

    //While bitchecker has a bit in it it will be greater than zero
    //So repeat until the bit has been shifted out
    while(bitChecker > 0)
    {
        //if the remainder of counter / 4 is zero then it is a byte and put a space
        //Also we don't need a space to begin with so if counter == zero don't skip it
        if((counter % 4)==0 && counter != 0)
        {
            printf(" ");
        }

        //Compare the users binary to yours using &
        //if it held a value then it will return a number greater than 0
        //If the value is zero then we print a zero because there was no value
        if((userInput & bitChecker) == 0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
        //afterwords shift the bit to the right to check the next position
        bitChecker = bitChecker >> 1;
        //increment counter saying we added a bit
        counter++;
    }
}