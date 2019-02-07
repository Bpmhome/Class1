
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
    int score = 0;
    char dealerHand[2] = {0};
    char playerHand[2] = {0};
    int playerValue = 0;
    int dealerValue = 0;

    gameIntro();
    do
    {
        drawHand(dealerHand,playerHand);
        printGameScreen(score,dealerHand[0],dealerHand[1],playerHand[0],playerHand[1]);
        dealerValue = handValue(dealerHand[0],dealerHand[1]);
        playerValue = handValue(playerHand[0],playerHand[1]);        
        printf("%d\n", dealerValue);
        printf("%d\n", playerValue);
        if(playerValue > dealerValue)
        {
            printf("Player Wins!\n");
            score++;
        }
        else
        {
            printf("Dealer Wins :(\n");
        }
        
        count++;

    } while (lose == false && count <= 5);
    
    return 0;
}

void drawHand(char *dealerHand, char *playerHand)
{
    dealerHand[0] = getCard();
    dealerHand[1] = getCard();
    playerHand[0] = getCard();
    playerHand[1] = getCard();
}