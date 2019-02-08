/*
    Programmer: Grant Ogden
    Date: 2/7/2019
    Filename: labC7.2.c
    Reason: to better understand else-if statements
*/
#include<stdio.h>

int main()
{
    //our three unsigned integers
    unsigned int var1 = 0;
    unsigned int var2 = 0;
    unsigned int var3 = 0;

    //gotta get that sweet input
    printf("Please enter two positive numbers seperated by a , : ");
    scanf("%u,%u",&var1,&var2);

    //if they are equal, well yeah narwhals
    if(var1 == var2)
    {
        printf("ERROR CODE: Narwhal\n");
    }
    //choose which is greater then clone it?
    else if(var1 > var2)
    {
        var3 = var1;
    }
    else
    {
        var3 = var2;
    }

    //if the user was creative enough to not put two ones then tell them what they entered
    if((var1 + var2 + var3) > 2)
    {
        printf("var1 = %d\nvar2 = %d\nvar3 = %d\n",var1,var2,var3);
    }
    
    return 0;
}