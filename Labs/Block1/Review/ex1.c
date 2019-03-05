/*
    Programmer: Grant Ogden
    Date: 3/5/2019
    Filename: ex1.c
    Reason:
*/
#include<stdio.h>

int main()
{
    float celcius = 0.0f;
    float farenheit = 0.0f;

    printf("Enter a celsius temp: ");
    scanf("%f",&celcius);

    farenheit = (celcius * 1.5) + 32;

    printf("\nTemp. in Farenheit: %.2f\n",farenheit);

    return 0;
}