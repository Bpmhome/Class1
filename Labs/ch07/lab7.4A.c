/*
    Programmer: Grant Ogden
    Date: 2/8/2019
    Filename: lab7.4A.c
    Reason: to better understand coninue
*/
#include<stdio.h>

int main()
{
    unsigned int x = 0;
    int count = 0;

    do
    { 
        count =0;
        printf("Please input a positive number: ");
        fscanf(stdin,"%u",&x);
        if(x > 999)
        {
            break;
        }
        for(int i = 1; i <= 999; i++)
        {
            if((x%i) == 0 && count < 20)
            {
                printf("%d ",i);
                count ++;
            }
            else if(count >= 20)
            {
                break;
            }
        }
        printf("\n");
    } while (1);



    return 0;
}