////////////////////////////////////////////
////////////////////////////////////////////
// bug 10

/******************************************
* Program Name: unittest_10.c
* Assignment Name: Final Project - Part B
* Author: Elizabeth Premer
* Date Due: 24 November 2019
* Description: This is a test suite for Dominion 
*               game play to catch 1 particular bug.
******************************************/


// ambassador
// Reveal a card from your hand. Return up to
//      two copies of it from your hand to the
//      Supply. Then each other player gains
//      a copy of it.

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    // initialize all variables
    int i, j;
    int handPos = 0;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int bonus = 0;
    int seed = 1000;
    int numPlayers = 2;

    // declare game state with testG as the control state
    struct gameState G, testG;

    // set kingdom cards to include 10 card supplies, including the Tribute card
    int cardSupplies[10] = {  adventurer, embargo, village, minion, mine,
                            cutpurse, sea_hag, tribute, smithy, council_room };

    // initialize a game state and player cards
    initializeGame(numPlayers, cardSupplies, seed, &G);

    printf("\n////////// Testing BUG_10 AMBASSADOR card does not find duplicate cards //////////\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    int currentPlayer = testG.whoseTurn;

    // make sure current player has the necessary cards to test Ambassador card effects
    //// three mine cards
    // for (int i = 0; i < 3; i++)
    // {
    //     testG.hand[currentPlayer][i] = mine;
    //     printf("hand %d: %d\n", i+1, testG.hand[currentPlayer][i]);
    // }

    // call the card in question
    cardEffect(ambassador, choice1, choice2, choice3, &testG, handPos, bonus);

    for (i = 0; i < testG.handCount[currentPlayer]; i++)
    {
        if (i != handPos && i == testG.hand[currentPlayer][choice1] && i != choice1)
        {
                printf("TEST BUG_10: FAILED: \n");
                j++;
        }
        else
        {
            printf("TEST BUG_10: FAILED: Card compared to index instead of card.\n");
        }

        if (i != handPos && testG.hand[currentPlayer][i]  == testG.hand[currentPlayer][choice1] && i != choice1)
        {
            printf("TEST BUG_10: PASSED\n");
            j++;
        }
        
    }

    printf("\n////////// SUCCESS: Testing Complete for BUG_10 //////////\n\n");

    return 0;
}