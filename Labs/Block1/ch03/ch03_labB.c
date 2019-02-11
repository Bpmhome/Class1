/*
    Programmer: Grant Ogden
    Date: 1/30/2019
    Filename: ch03_labB.c
    Reason: For a better understanding of strings
*/
#include <stdio.h>

int main()
{
    char charStringArr[256] = {0};
    charStringArr[0] = 'c';
    charStringArr[1] = 'a';
    charStringArr[2] = 'r';
    charStringArr[3] = 'p';
    charStringArr[4] = 'e';
    charStringArr[5] = ' ';
    charStringArr[6] = 'd';
    charStringArr[7] = 'i';
    charStringArr[8] = 'e';
    charStringArr[9] = 'm';
    charStringArr[10] = '\0';

    printf("%s\n",charStringArr);

    return 0;
}