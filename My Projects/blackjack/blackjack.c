
#define bool int
#define true 1
#define false 0

#include <stdio.h>
#include "cardEngine.h"
#include "graphics.h"

void drawHand(char *dealerHand, char *playerHand);

int main()
{
    bool lose = false;
    int count = 0;
    char dealerHand[2] = {0};
    char playerHand[2] = {0};

    gameIntro();
    do
    {
        printf("%c %c\n",dealerHand[0],dealerHand[1]);
        drawHand(dealerHand,playerHand);
        printGameScreen(0,dealerHand[0],dealerHand[1],playerHand[0],playerHand[1]);
        count++;

    } while (lose == false || count <= 5);
    
    return 0;
}

void drawHand(char *dealerHand, char *playerHand)
{
    dealerHand[0] = getCard();
    dealerHand[1] = getCard();
    playerHand[0] = getCard();
    playerHand[1] = getCard();
}