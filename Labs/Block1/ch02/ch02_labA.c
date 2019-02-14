/*
    Programmer: Grant Ogden
    Date: 1/29/2019
    FileName: ch02_labA.c
    Reason: relearn how to declare variables and initialize them
*/
#include<stdio.h>

int main()
{
    int iAmANumber = 42;                //an integer with value 42
    float iAmASmallNumber =   .001;     //a float with value .001
    double iAmASmallerNumber = .00002;  //a double with value .00002
    char iAmALetter = 'G';              //a char with value G

    printf("My integer is %d \n", iAmANumber);          //print "My integer is 42"
	printf("My float is %f \n", iAmASmallNumber);       //print "My float is .001"
	printf("My double is %lf \n", iAmASmallerNumber);   //print "My double is .00002"
	printf("My char is %c \n", iAmALetter);             //print "My char is G"

	printf("Size of int is %d \n", sizeof(iAmANumber));             //print "Size of int is 4"
	printf("Size of float is %d \n", sizeof(iAmASmallNumber));      //print "Size of float is 4"
	printf("Size of double is %d \n", sizeof(iAmASmallerNumber));   //print "Size of double is 8"
	printf("Size of char 1 is %d \n", sizeof(iAmALetter));          //print "Size of char 1 is 1"

    return 0;
}