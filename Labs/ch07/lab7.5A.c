/*
    Programmer: Grant Ogden
    Date: 2/10/2019
    Filename: lab7.5A.c
    Reason: To better understand Nested Control flow.
*/
#include <stdio.h>
#include <ctype.h>

int main()
{
    char userInput = 0;

    do
    {
        fflush(stdin);
        printf("Please enter whether you want odds or evens by typing it: \n");
        userInput = getchar();
        if((userInput >= 65 && userInput <= 90) || (userInput >= 97 && userInput <= 122))
        {
            userInput = toupper(userInput);
        }
        else
        {
            continue;
        }
    } while (userInput != 69 && userInput != 79);

    if(userInput == 'E')
    {
        for(int i = 0; i <= 100; i+= 2)
        {
            if(i & 1)
            {
                i++;
            }
            printf("%d ",i);
        }    
        printf("\n");
    }
    else
    {
        int counter = 0;
        while(counter <= 100)
        {
            if((counter & 1) == 0)
            {
                counter++;
            }
            printf("%d ",counter);
            counter += 2;
        }
        printf("\n");
    }
    
    return 0;
}