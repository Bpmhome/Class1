#include<stdio.h>

int main ()
{

    printf("#1 %f\n", 1.2);
    printf("#2 %+8.4f\n", -1.798);
    printf("#3 % 7.2f\n", 0.987654321);
    printf("#4 %-6.1f is yours\n", 13.37);
    printf("#5 Yours is %05.2f\n", 1.2345);
    printf("#6 %s", "Hello World!\n\0");
    printf("#7 %9.5s", "Hello world!\0");
    printf("\n");
    printf("#8 %016.11s", "Hello world!\0");
    printf("\n");
    return 0;
}