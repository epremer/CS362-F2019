/*
isGameOver bug
There is a bug in the isGameOver function. While checking if there are 3 cards with a card count of 0, it only loops through 25 cards.
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main()
{
    int i;
    int totalTests = 15;
    int failed = 0;
    //set card array
    int k[10] = { ambassador, minion, tribute, gardens, mine, remodel, sea_hag, village, baron, great_hall };

    //declare game state
    struct gameState g;
    int seed = 1000;
    int numPlayers = 3;

    printf("\n\nBegin Testing isGameOver:\n");
    initializeGame(numPlayers, k, seed, &g);

    for(i = 0; i < 27; i++)
    {
        g.supplyCount[i] = MAX_DECK;
    }
    
    g.supplyCount[0] = 0; //curse
    g.supplyCount[24] = 0; //copper
    g.supplyCount[25] = 0; //26th card sea_hag

    int gameOver = isGameOver(&g);
    if(gameOver)
    {
        printf("Test passed; function checked the 26th card\n");
    }
    else
    {
        printf("Test failed; function did not check 26th card\n");
    }
    

    for(i = 0; i < 27; i++)
    {
        g.supplyCount[i] = MAX_DECK;
    }
    
    g.supplyCount[0] = 0; //curse
    g.supplyCount[4] = 0; //copper
    g.supplyCount[26] = 0; //27th card treasure_map

    gameOver = isGameOver(&g);
    if(gameOver)
    {
        printf("Test passed; function checked the 27th card\n");
    }
    else
    {
        printf("Test failed; function did not check 27th card\n");
    }

    for(i = 0; i < 27; i++)
    {
        g.supplyCount[i] = MAX_DECK;
    }
    
    g.supplyCount[0] = 0; //curse
    g.supplyCount[25] = 0; //26th card sea_hag
    g.supplyCount[26] = 0; //27th card treasure_map

    gameOver = isGameOver(&g);
    if(gameOver)
    {
        printf("Test passed; function checked the 26th and 27th cards\n");
    }
    else
    {
        printf("Test failed; function did not check 26th and 27th cards\n");
    }

    return 0;
}