/*
    Programmer: Grant Ogden
    Date: 3/5/2019
    Filename: ex4.c
    Reason:
*/
#include<stdio.h>

int main()
{
    int num1,num2,flag;

    printf("Enter two numbers: ");
    scanf("%d %d",&num1,&num2);

    printf("Prime numbers between %d and %d are: ",num1,num2);

    //go through the process of findinng prime numbers

    for(size_t i = num1 + 1; i < num2; i++)
    {
        flag = 0;
        for(size_t j = 2; j < i/2; j++)
        {
            if( i % j == 0)
            {
                flag=1;
                break;
            }
        }

        if(flag == 0)
        {
            printf("%d\t",i);
        }
        
    }
    
    return 0;
}