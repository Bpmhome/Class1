#include<stdio.h>

int main()
{
    float num = 0.0f;

    printf("Enter a number: ");
    scanf("%f", &num);

    if(num < 0.0f)
    {
        printf("You have entered a negative number.");
    }
    else if (num > 0.0f) 
    {
        printf("You have entered a positive number.");
    }
    else
    {
        printf("You have entered zero.");
    }

    return 0;
}