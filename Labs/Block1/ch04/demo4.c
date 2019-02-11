#include <stdio.h>

int main()
{
    int month = 0;
    int day= 0;
    int year = 0;

    printf("Please input the date in mm-dd-yyyy format: ");
    scanf("%2d-%2d-%4d",&month,&day,&year);
    printf("The date is:\n");
    printf("%2.2d/%2.2d/%4.4d \n", month, day, year);

    return 0;
}