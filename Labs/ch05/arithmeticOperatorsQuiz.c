/*
    Programmer: Grant Ogden
    Date: 2/5/2019
    Filename: arithmeticOperatorsQuiz.c
    Reason: To understand the arithmetic operators better
*/
#include <math.h>
#include <stdio.h>

int main()
{
    int x = 7;
    int y = 4;
    float z = 0;

    //multiply two variables
    printf("%d\n",(x*y));
    //divide and save into a flaot
    z = (float)x / y;   
    printf("%f\n", z);
    //use the modulas operator to get the remainder
    printf("%d\n",(x%y));
    //add two variables
    printf("%d\n", (y + x));
    //subract two variables
    printf("%d\n", (y - x));
    //inverse the sign of a variable
    printf("%d\n", -y);
    //increment a variable, then view it
    printf("%d\n", ++x);
    //view a variable, then increment it
    printf("%d\n", y++);
    //view a variable, then decrement it
    printf("%d\n", x--);
    //decrement a variable, then view it
    printf("%d\n", --y); 
    //a bunch of maths to show order of operations  
    printf("%d\n", (1 + 2*  (3 + y) + 5));
    
    return 0;
}