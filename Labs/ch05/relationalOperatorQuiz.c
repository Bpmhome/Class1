/*
    Programmer: Grant Ogden
    Date: 2/5/2019
    Filename: relationalOperatorsQuiz.c
    Reason: To understand the relational operators better
*/
#include <stdio.h>

int main()
{
    int x = 2;
    int y = 6;

    //less than operator
    if( y < x ) { printf("true\n"); } else { printf("false\n"); }
    //less than or equal to operator
    if( y <= x ) { printf("true\n"); } else { printf("false\n"); }
    //greater than operator
    if( y > x ) { printf("true\n"); } else { printf("false\n"); }
    //greater than or equal to operator
    if( y >= x ) { printf("true\n"); } else { printf("false\n"); }
    //equal to operator
    if( y == x ) { printf("true\n"); } else { printf("false\n"); }
    //not equal to operator
    if( y != x ) { printf("true\n"); } else { printf("false\n"); }
    //equal to operator
    if( 2 == y ) { printf("true\n"); } else { printf("false\n"); }
    //not equal to operator
    if( 6 != x ) { printf("true\n"); } else { printf("false\n"); }
    //greater than or equal to operator
    if( 6 >= 2 ) { printf("true\n"); } else { printf("false\n"); }
    //less than operator
    if( 2 < 6 ) { printf("true\n"); } else { printf("false\n"); }
    //BONUS: so um yeah this thing
    if( (x <= 3) && (y != 3) && (x != 3) ) { printf("true\n"); } else { printf("false\n"); }

    return 0;
}