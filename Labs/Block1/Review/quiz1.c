#include <stdio.h>

int main()
{
    int num1,num2,num3;

    printf("Please enter three numbers seperated by spaces: ");
    scanf("%d %d %d",&num1,&num2,&num3);

    if(num1 >= num2 && num1 >= num3)
    {
        printf("\nThe largest number given is %d.\n",num1);
    }
    else if (num2 >= num1 && num2 >= num3)
    {
        printf("\nThe largest number given is %d.\n",num2);       
    }
    else if (num3 >= num1 && num3 >= num2)
    {
        printf("\nThe largest number given is %d.\n",num3);       
    }
    

    return 0;
}