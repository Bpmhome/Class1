#include <stdio.h>

int main()
{
    int userInput = 0;
    printf("Please enter a number: ");
    scanf("%d",&userInput);

    if(userInput & 1)
    {
        userInput *= 2;
        printf("%d\n",userInput);
    }
    else
    {
        printf("It is even!\n");
    }
    
    return 0;
}