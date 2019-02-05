/*
    Programmer: Grant Ogden
    Date: 2/5/2019
    Filename: logicalOperatorsQuiz.c
    Reason: to learn logical operators better
*/
#include <stdio.h>

int main()
{
    int x = 99;
    int y = 0;
    printf("%d\n", ( x && y ));
    printf("%d\n", ( y || x ));
    printf("%d\n", ( !y ));
    printf("%d\n", ( y && 0 ));
    printf("%d\n", ( x || 42 ));
    printf("%d\n", ( !x ));
    printf("%d\n", ( x && x ));
    printf("%d\n", ( y || y ));
    printf("%d\n", ( !1 ));
    printf("%d\n", ( 1 && 1 ));
    printf("%d\n", ( (0 && 1) || (2 && 3) ));

    return 0;

}