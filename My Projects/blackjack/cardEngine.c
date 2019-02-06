#include "cardEngine.h"
#include <stdlib.h>
#include <time.h>
//#include <unistd.h> //use for sleep function in testing
//#include <stdio.h>  //use to print to screen during testing

const int NUM_CARDS = 13;

unsigned int randNum(void)
{
    srand(time(NULL) * rand());
    unsigned int x = (RAND_MAX + 1u)/NUM_CARDS;
    unsigned int y = x * NUM_CARDS;
    unsigned int r;
    
    do
    {
        r = rand();
    }while(r >= y);

    return (r/x) + 1;
}

char getCard(void)
{
    unsigned int cardValue = randNum();
    switch(cardValue)
    {
        case 1:
            return 'A';
            break;
        case 2:
            return '2';
            break;
        case 3:
            return '3';
            break;
        case 4:
            return '4';
            break;
        case 5:
            return '5';
            break;
        case 6:
            return '6';
            break;
        case 7:
            return '7';
            break;
        case 8:
            return '8';
            break;
        case 9:
            return '9';
            break;
        case 10:
            return 'X';
            break;
        case 11:
            return 'J';
            break;
        case 12:
            return 'Q';
            break;
        case 13:
            return 'K';
            break;
    }
}

int handValue(char card1, char card2)
{
    return cardValue(card1) + cardValue(card2);
}

int cardValue(char card)
{
    switch(card)
    {
        case 'A':
            return 1;
            break;                
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        case 'X':
            return 10;
            break;
        case 'J':
            return 10;
            break;
        case 'Q':
            return 10;
            break;
        case 'K':
            return 10;
            break;
    }
}

