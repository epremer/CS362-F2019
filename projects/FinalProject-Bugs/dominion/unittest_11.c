////////////////////////////////////////////
////////////////////////////////////////////
// bug 11

/******************************************
* Program Name: unittest_11.c
* Assignment Name: Final Project - Part B
* Author: Elizabeth Premer
* Date Due: 24 November 2019
* Description: This is a test suite for Dominion 
*               game play to catch 3 particular bugs.
******************************************/


// minion
// +1 Action ... Choose One:
//      1) +2 treasure
//      2) Discard your hand, +4 cards and each
//          other player with at least 5 cards
//          in hand discards their hand and
//          draws 4 cards.



#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    // initialize all variables

    int handPos = 0;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    
    struct gameState G, testG;
    int cardSupplies[10] = {  adventurer, embargo, village, minion, mine,
                            cutpurse, sea_hag, tribute, smithy, council_room };

    // initialize a game state and player cards
    initializeGame(numPlayers, cardSupplies, seed, &G);

    printf("\n////////// Testing Card MINION //////////\n");


    // Test if choice3 or other invalid choice

    ////////// TEST BUG_11 Is invalid choice chosen?
    printf("\n////////// TEST BUG_11: Is invalid choice chosen?\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    int currentPlayer = testG.whoseTurn;
    choice1 = 0;
    choice2 = 0;
    choice3 = 1;

    cardEffect(minion, choice1, choice2, choice3, &testG, handPos, bonus);
    if ((!choice1 && !choice2) || choice3)
    {
        // PERFORM AS THOUGH CHOICE2 WAS CHOSEN
        if (numHandCards(&testG) > 0)
        {
            if (numHandCards(&testG) == 4)
            {
                printf("Test Bug_11: PASSED: Proper number of cards drawn.\n");
            }
            else
            {
                printf("Test Bug_11: FAILED: IMProper number of cards drawns.\n");
            }
        }
    }

    printf("\n////////// SUCCESS: Testing Complete for MINION //////////\n\n");

    return 0;
}