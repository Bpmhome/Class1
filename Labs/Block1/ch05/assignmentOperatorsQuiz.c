/*
    Programmer: Grant Ogden
    Date: 2/5/2019
    Filename: assignmentOperatorsQuiz.c
    Reason: to better understand assignment operators
*/
#include <stdio.h>

void reset();

int x = 9;
int y = 3;

int main()
{

    x *= y;
    printf("#1 %d\n", x);
    reset();
    x /= y;
    printf("#2 %d\n", x);
    reset();
    x %= y;
    printf("#3 %d\n", x);
    reset();
    x += y;
    printf("#4 %d\n", x);
    reset();
    x -= y;
    printf("#5 %d\n", x);
    reset();
    x *= ++y;
    printf("#6 %d\n", x);
    reset();
    x /= y++;
    printf("#7 %d\n", x);
    reset();
    x %= --x;
    printf("#8 %d\n", x);
    reset();
    x += --y;
    printf("#9 %d\n", x);
    reset();
    x -= y++;
    printf("#10 %d\n", x);
    reset();
    
    printf("#11 %d\n", ( y %= y ) || ( x /= x--));

    return 0;
}

void reset()
{
    x = 9;
    y = 3;
}