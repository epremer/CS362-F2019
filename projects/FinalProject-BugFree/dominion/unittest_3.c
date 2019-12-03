/*
In the remodel case within the cardEffect function, 
the if statement that compares the two choice statements needs to be switched (around Line #846).
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
    printf("Begin Testing remodel:\n");

    initializeGame(numPlayers, k, seed, &g);

    printf("Test : invalid choice 2 and choice1 treasure---------------------------------------------\n");
    currentPlayer = g.whoseTurn;
    for (i = 0; i < g.handCount[currentPlayer]; i++)
    {
        discardCard(0, currentPlayer, &g, 0);
    }
    g.handCount[currentPlayer] = 0;
    g.hand[currentPlayer][0] = remodel;
    g.handCount[currentPlayer]++;
    g.hand[currentPlayer][1] = copper;
    g.handCount[currentPlayer]++;
    choice1 = 1;
    choice2 = silver; //3 extra than copper

    memcpy(&testG, &g, sizeof(struct gameState));
    int r = cardEffect(remodel, choice1, choice2, choice3, &g, handPos, 0);
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

    printf("Test : invalid choice 2 and choice1 treasure--------------------------------------------\n");
    initializeGame(numPlayers, k, seed, &g);
    currentPlayer = g.whoseTurn;
    for (i = 0; i < g.handCount[currentPlayer]; i++)
    {
        discardCard(0, currentPlayer, &g, 0);
    }
    g.handCount[currentPlayer] = 0;
    g.hand[currentPlayer][0] = remodel;
    g.handCount[currentPlayer]++;
    g.hand[currentPlayer][1] = estate;
    g.handCount[currentPlayer]++;
    choice1 = 1;
    choice2 = province; //5 more than estate

    memcpy(&testG, &g, sizeof(struct gameState));
     r = cardEffect(remodel, choice1, choice2, choice3, &g, handPos, 0);
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
