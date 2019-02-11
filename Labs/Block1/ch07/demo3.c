#include<stdio.h>

int main()
{
    int var1 = 0;
    int var2 = 0;
    int var3 = 0;

    printf("Please enter two numbers seperated by a , : ");
    scanf("%d,%d",&var1,&var2);

    if(var1 > var2)
    {
        var3 = var1 - var2;
    }
    else if (var2 > var1)
    {
        var3 = var2 - var1;
    }
    else
    {
        var3 = 0;
    }
    
    if(var3 >= 0)
    {
        printf("%d",var3);
    }
    else
    {
        printf("ERROR");
    }
    
    
}