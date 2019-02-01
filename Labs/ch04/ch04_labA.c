#include <stdio.h>

int main()
{
    char input;
    
    printf("Please input your character to be incremented: ");
    input = getchar();
    printf("The next character is.....");
    putchar(input + 1);
    printf("\n");

    return 0;
}
