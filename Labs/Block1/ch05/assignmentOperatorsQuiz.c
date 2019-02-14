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

    x *= y;                 //x = x * y
    printf("#1 %d\n", x);
    reset();
    x /= y;                 //x = x / y
    printf("#2 %d\n", x);
    reset();
    x %= y;                 //x = x % y
    printf("#3 %d\n", x);
    reset();
    x += y;                 //x = x + y
    printf("#4 %d\n", x);
    reset();
    x -= y;                 //x = x - y
    printf("#5 %d\n", x);
    reset();
    x *= ++y;               //x = x * (y + 1)
    printf("#6 %d\n", x);
    reset();
    x /= y++;               //x = x * y, y + 1
    printf("#7 %d\n", x);
    reset();
    x %= --x;               //x = x % (x - 1)
    printf("#8 %d\n", x);
    reset();
    x += --y;               //x = x + (y - 1)
    printf("#9 %d\n", x);
    reset();
    x -= y++;               //x = x - y, y++
    printf("#10 %d\n", x);
    reset();
    
    printf("#11 %d\n", ( y %= y ) || ( x /= x--));

    return 0;
}

/*
 * FUNCTION:    Resets the variables values
 * ARGUEMENTS:  None
 * RETURN:      VOID
 * NOTES:       Sets x value = 9
 *              Sets y value = 3
 */
void reset()
{
    x = 9;
    y = 3;
}