#include<stdio.h>

int main()
{
    char userInput[100] = {0};

    printf("Please enter a string: ");
    scanf("%99[^\n]c",userInput);
    
    if(userInput[0] != 0)
    {
        printf("Your string is:\n");
        printf("%s\n",userInput);
    }

    return 0;
}