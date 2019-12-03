/*
Bug: The last discardCard function call within the mine and tribute case statement of the cardEffect function are not actually trashing the cards. 
They are just being put into the currentPlayers discard pile when the chosen card should be trashed.
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

    //set kingdom cards to include mine action card
    int k[10] = {ambassador, minion, tribute, gardens, mine, remodel, smithy, village, baron, great_hall};

    //declare game state; testG is control state
    struct gameState g, testG;

    //set variables to initialize the game play
    int seed = 1000;
    int numPlayers = 2;
    int choice2Options[2] = {gold, silver};
    int r;

    for (int i = 0; i < 2; i++)
    {
        initializeGame(numPlayers, k, seed, &g);

        int handPos = 0;
        int choice1, choice2, choice3 = 0;

        //get the current player’s number
        int currentPlayer = g.whoseTurn;

        //set current player’s hand count = 0, so cards can be added in specified order
        g.handCount[currentPlayer] = 0;

        //hand mine card at position 0 and copper at position 1
        g.hand[currentPlayer][0] = mine;
        g.hand[currentPlayer][1] = copper;
        g.handCount[currentPlayer] += 2;
        g.supplyCount[copper]--;
        //choice1 is position 1 which is a copper
        choice1 = 1;
        //choice2 is a silver which costs exactly 3 more than a copper
        choice2 = choice2Options[i];

        //clear the discard pile for testing later
        int i;
        for (i = 0; i < g.discardCount[currentPlayer]; i++)
        {
            discardCard(0, currentPlayer, &g, 0);
        }
        //copy gameState into testG
        memcpy(&testG, &g, sizeof(struct gameState));
        r = cardEffect(mine, choice1, choice2, choice3, &g, handPos, 0);
        printf("%d\n", r);
        //since discardCard function is called twice, once for the mine card and once for choice2,
        //the bug should cause the discardCount to increase by 2
        if (g.discardCount[currentPlayer] != testG.discardCount[currentPlayer] + 1)
        {
            printf("Test failed: expected: %d vs actual %d; discardCount changed\n", testG.discardCount[currentPlayer] + 1, g.discardCount[currentPlayer]);
        }
        else
        {
            printf("Test passed; discardCount fine\n");
        }

        //since we know that the discardCard function also increases the played card count, we need to test that too
        //to make sure discardCard function is working correctly
        if (g.playedCardCount != testG.playedCardCount + 1)
        {
            printf("Test failed: expected: %d vs actual %d; playedCardCount changed\n", testG.playedCardCount + 1, g.playedCardCount);
        }
        else
        {
            printf("Test passed; playedCardCount fine\n");
        }
    }

    return 0;
}
