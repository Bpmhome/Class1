/*
    Programmer: Grant Ogden
    Date: 2/8/2019
    Filename: lab7.4A.c
    Reason: to better understand coninue
*/
#include<stdio.h>

int main()
{
    //unsigned integer for user input
    unsigned int x = 0;
    //counter variable to count how many times we have placed a divisible number
    int count = 0;

    //repeat while the user input isn't over 999
    do
    { 
        //reset the count variable
        count =0;
        //get the user input
        printf("Please input a positive number: ");
        fscanf(stdin,"%u",&x);
        //if the users input is over 999 then break out of loop
        if(x > 999)
        {
            break;
        }
        //for every number between the number and 1
        for(int i = 1; i <= x; i++)
        {
            //if the number is divisible and we have less than 20
            if((x%i) == 0 && count < 20)
            {
                //print it and count it
                printf("%d ",i);
                count ++;
            }
            //else break
            else if(count >= 20)
            {
                break;
            }
        }
        printf("\n");
    } while (x <= 999);

    return 0;
}