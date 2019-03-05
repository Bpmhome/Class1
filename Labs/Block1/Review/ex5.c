/*
    Programmer: Grant Ogden
    Date: 3/5/2019
    Filename: ex4.c
    Reason:
*/
#include<stdio.h>

int displayPrimeNumber(int x);

int main()
{
    int num1,num2,flag;

    printf("Enter two numbers: ");
    scanf("%d %d",&num1,&num2);

    printf("Prime numbers between %d and %d are: ",num1,num2);

    //go through the process of findinng prime numbers

    for(size_t i = num1 + 1; i < num2; i++)
    {
        flag = displayPrimeNumber(i);

        if(flag == 0)
        {
            printf("%d\t", i);
        }
    }
    
    return 0;
}

int displayPrimeNumber(int x)
{

   for(size_t j = 2; j < x/2; j++)
    {
        if( x % j == 0)
        {
            return 1;
        }
    }

    return 0;
}
