#include <stdio.h>
#include "cardEngine.h"
#include <unistd.h> //use for sleep function in testing
//#include <time.h> //use for nanosleep function

void gameIntro();


//struct timespec tim, tim2; //struct required for nanosleep

int main()
{
    gameIntro();
    return 0;
}

void gameIntro()
{
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
}