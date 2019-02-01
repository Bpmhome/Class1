/*
    Programmer: Grant Ogden
    Date: 1/29/2019
    FileName: ch02_labA.c
    Reason: Because I was told too and to relearn how to declare variables and initialize them
*/
#include<stdio.h>

int main()
{
    int iAmANumber = 42;
    float iAmASmallNumber =   .001;
    double iAmASmallerNumber = .00002;
    char iAmALetter = 'G';

    printf("My integer is %d \n", iAmANumber);
	printf("My float is %f \n", iAmASmallNumber);
	printf("My double is %lf \n", iAmASmallerNumber);
	printf("My char is %c \n", iAmALetter);

	printf("Size of int is %d \n", sizeof(iAmANumber));
	printf("Size of float is %d \n", sizeof(iAmASmallNumber));
	printf("Size of double is %d \n", sizeof(iAmASmallerNumber));
	printf("Size of char 1 is %d \n", sizeof(iAmALetter));

    return 0;
}