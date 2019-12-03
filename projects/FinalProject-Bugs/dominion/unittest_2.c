/*
For the Mine switch statement in the cardEffect function (around line 821), 
it seems that it checks the cost of the card they trash against the cost of the card they want to buy incorrectly. 
It looks like if the cost of the treasure that they choose to trash plus 3, 
is greater than the cost of the card they want to buy, then it will return -1.
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
    //set card array
    int k[10] = {ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall};

    //declare game state
    struct gameState g, testG;

    int seed = 1000;
    int numPlayers = 2;
    int handPos = 0;
    int choice1, choice2, choice3 = 0;
    int currentPlayer;
    printf("Begin Testing mine:\n");

    initializeGame(numPlayers, k, seed, &g);

    printf("Test : invalid choice 2 and choice1----------------------------------------------\n");
    currentPlayer = g.whoseTurn;
    for (i = 0; i < g.handCount[currentPlayer]; i++)
    {
        discardCard(0, currentPlayer, &g, 0);
    }
    g.handCount[currentPlayer] = 0;
    g.hand[currentPlayer][0] = mine;
    g.handCount[currentPlayer]++;
    g.hand[currentPlayer][1] = copper;
    g.handCount[currentPlayer]++;
    choice1 = 1;
    choice2 = gold;

    memcpy(&testG, &g, sizeof(struct gameState));
    int r = cardEffect(mine, choice1, choice2, choice3, &g, handPos, 0);
    if (r == -1)
    {

        printf("Test passed; exited before gaining card\n");
    }
    else
    {
        printf("Test failed; did not exit before gaining card\n");
    }

    if (g.handCount[currentPlayer] == testG.handCount[currentPlayer])
    {
        printf("Test passed; handCount unchanged\n");
    }
    else
    {
        printf("Test failed: expected: %d vs actual %d; handCount changed\n", testG.handCount[currentPlayer], g.handCount[currentPlayer]);
    }

    int hasCard = 0;
    for(i = 0; i < g.handCount[currentPlayer]; i++)
    {
        if(g.hand[currentPlayer][i] == choice2)
        {
            hasCard = 1; 
        }
    }

    if(hasCard != 1)
    {
        printf("Test passed; did not gain choice2\n");
    }
    else{
        printf("Test failed; gained choice2\n");
    }


    printf("Test : invalid choice 2 and choice1----------------------------------------------\n");
    currentPlayer = g.whoseTurn;
    for (i = 0; i < g.handCount[currentPlayer]; i++)
    {
        discardCard(0, currentPlayer, &g, 0);
    }
    g.handCount[currentPlayer] = 0;
    g.hand[currentPlayer][0] = mine;
    g.handCount[currentPlayer]++;
    g.hand[currentPlayer][1] = copper;
    g.handCount[currentPlayer]++;
    choice1 = 1;
    choice2 = gold;

    memcpy(&testG, &g, sizeof(struct gameState));
    r = cardEffect(mine, choice1, choice2, choice3, &g, handPos, 0);
    if (r == -1)
    {

        printf("Test passed; exited before gaining card\n");
    }
    else
    {
        printf("Test failed; did not exit before gaining card\n");
    }

    if (g.handCount[currentPlayer] == testG.handCount[currentPlayer])
    {
        printf("Test passed; handCount unchanged\n");
    }
    else
    {
        printf("Test failed: expected: %d vs actual %d; handCount changed\n", testG.handCount[currentPlayer], g.handCount[currentPlayer]);
    }

    hasCard = 0;
    for(i = 0; i < g.handCount[currentPlayer]; i++)
    {
        if(g.hand[currentPlayer][i] == choice2)
        {
            hasCard = 1; 
        }
    }

    if(hasCard != 1)
    {
        printf("Test passed; did not gain choice2\n");
    }
    else{
        printf("Test failed; gained choice2\n");
    }


    return 0;
}
