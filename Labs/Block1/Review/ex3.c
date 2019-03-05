#include<stdio.h>

int main()
{
    int num1,num2,temp;

    printf("Enter first number: ");
    scanf("%d",&num1);
    printf("Enter second number: ");
    scanf("%d",&num2);

    //swapping
    temp = num1;
    num1 = num2;
    num2 = temp;

    printf("\nAfter swapping,\nFirst number: %d\nSecond number: %d\n",num1,num2);

    return 0;
}