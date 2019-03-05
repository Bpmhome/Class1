#include <stdio.h>

int main()
{
    int year;

    printf("Enter a year you want to check: ");
    scanf("%d", &year);

    //leap year conditions
    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
            {
                printf("%d is a leap year!\n",year);
            }
            else
            {
                printf("%d is not a leap year\n",year);
            } 
        }
        else
        {
            printf("%d is not a leap year\n",year);
        }
    }
    else
    {
        printf("%d is not a leap year\n",year);
    }
}