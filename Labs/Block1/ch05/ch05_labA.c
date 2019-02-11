/*
    Programmer: Grant Ogden
    Date: 2/5/2019
    Filename: ch05_labA.c
    Reason: To use operators correctly
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main(void) 
{
    /* insert initialize variables here */
    int sideA = 0;
    int sideB = 0;
    double sideC = 0;
    /* insert input values and assign to variables here */
    printf("Please enter the two side of your triagle seperated by a , :\n");
    scanf("%d,%d",&sideA,&sideB);
    if ((sideA > 0) && (sideB > 0))
    {
        /* insert arithmetic hypotenuse calculation here */
        sideC = sqrt( (sideA * sideA) + (sideB * sideB) );
        /* insert -Print the hypotenuse here */
        printf("The hypotenuse is: %lf\n", sideC);
    }
    return 0;
}