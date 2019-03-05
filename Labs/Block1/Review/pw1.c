#include <stdio.h>
#include <string.h>

int main()
{
    char password[] = {"sand"};
    char input[15];
    int match;

    printf("Password: ");
    scanf("%s",input);

    match = strcmp(input,password);

    if(match == 0)
    {
        puts("Password Accepted");
    }
    else
    {
        puts("Invalid Password");
    }
    
}