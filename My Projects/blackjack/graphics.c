#include "graphics.h"
#include <stdio.h>
#include <stdlib.h> //use for system command
#include <termios.h>
#include <unistd.h> //use for sleep function in testing

void gameIntro()
{
    system("cls||clear");
    printf(" ||===\\  ||     ||===|| ||=== ||  / ====== ||===|| ||=== ||  / \n");
    printf( " ||    | ||     ||   || ||    || /     ||  ||   || ||    || /  \n");
    printf( " ||===[  ||     ||===|| ||    ||{      ||  ||===|| ||    ||{   \n");
    printf( " ||    | ||     ||   || ||    || \\     ||  ||   || ||    || \\ \n");
    printf( " ||===/  ||==== ||   || ||=== ||  \\ ===||  ||   || ||=== ||  \\ \n");
    sleep(2);
    printf("\n\n");
    printf("\t\t\tCreated By\n");
    printf("\t\t\t\tGrant Ogden\n");
    sleep(2);
    printf("\n\n");
    printf("\t\t   Because Why The Hell Not!\n");
    sleep(5);
    wait();
    system("cls||clear");
}

char printGameScreen(int score, char dealerCard1, char dealerCard2, char userCard1, char userCard2 )
{
    printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    printf("X S:%1.1d                                     X\n",score);
    printf("X              D: %c %c                     X\n",dealerCard1,dealerCard2);
    printf("X                                         X\n");
    printf("X                                         X\n");
    printf("X                                         X\n");
    printf("X                                         X\n");
    printf("X                                         X\n");
    printf("X              P: %c %c                     X\n",userCard1,userCard2);
    printf("X                                         X\n");
    printf("X h: hit  s: stand  d: double down        X\n");
    printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    return getchar();
}

void wait()
{ 
    printf("\nPress The Enter Key To Continue......\n");
    getchar();
}

