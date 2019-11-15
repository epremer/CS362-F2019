// minion
// +1 Action ... Choose One:
//      1) +2 treasure
//      2) Discard your hand, +4 cards and each
//          other player with at least 5 cards
//          in hand discards their hand and
//          draws 4 cards.

/******************************************
* Program Name: unittest2.c
* Assignment Name: Assignment 3
* Author: Elizabeth Premer
* Date Due: 10 November 2019
* Description: This is a test suite for Dominion 
*               game play using the MINION card.
* NOTE: The initialized variables and skeleton
*       of this code is loosely borrowed from
*       the sample code provided in the 
*       lectures/course modules.
******************************************/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TESTCARD "minion"

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

    printf("\n////////// Testing Card %s //////////\n", TESTCARD);



    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    int currentPlayer = testG.whoseTurn;

    printf("Before Card Effect\nTestG NumActions: %d\nG NumActions: %d\n", testG.numActions, G.numActions);

    cardEffect(minion, choice1, choice2, choice3, &testG, handPos, bonus);


    ////////// TEST #1: Test +1 Action
    printf("\n////////// TEST 1: Test +1 Action\n");

    // Test +1 action 
    if (testG.numActions == (G.numActions + 1))
    {
        printf("Test 1: PASSED: +1 Action Success\n");
    }
    else
    {
        printf("Test 1: FAILED: +1 Action Not Given\n");
    }

    // Test card in hand is discarded
    ////////// TEST #2: Card in hand gets discarded
    printf("\n////////// TEST 2: Card in hand gets discarded\n");
    if (testG.discardCount[currentPlayer] == (G.discardCount[currentPlayer]++))
    {
        printf("Test 2: PASSED: Card was discarded.\n");
    }
    else
    {
        printf("Test 2: FAILED: Card was NOT discarded.\n");
    }


    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    choice1 = 1;

    cardEffect(minion, choice1, choice2, choice3, &testG, handPos, bonus);


    // Test if choice1
    //      are 4 new cards drawn (should fail since 5 are now)

    ////////// TEST #3 Are 4 New Cards Drawn?
    printf("\n////////// TEST 3:Are 4 New Cards Drawn?\n");
    if (choice1 == 1)
    {
        if (numHandCards(&testG) > 0)
        {
            if (numHandCards(&testG) == 4)
            {
                printf("Test 4: PASSED: Proper number of cards drawn.\n");
            }
            else
            {
                printf("Test 4: FAILED: IMProper number of cards drawns.\n");
            }
        }
    }


    // Test is choice1
    //      for all players
    //          if other player (OP) has > 4 cards
    //              Test: is hand properly discarded
    //              Test: are 4 new cards drawn

    ////////// TEST #5 Are proper number of cards drawn for other players
    printf("\n////////// TEST 5: Are proper number of cards drawn for other players\n");
    if (choice1 == 1)
    {
        for (int i = 0; i < testG.numPlayers; i++)
        {
            if (testG.handCount[i] > 0)
            {
                if (testG.handCount[i] == 4)
                {
                    printf("Test 5: PASSED: Proper number of cards drawn for other player.\n");
                }
                else
                {
                    printf("Test 5: FAILED: IMProper number of cards drawn for other player.\n");
                }
            }
        }
    }


    // Test if choice2
    //      are testG.coins == G.coins +2 

    ////////// TEST #6 +2 coins when choosing coin option
    printf("\n////////// TEST 6: +2 coins when choosing coin option\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    choice2 = 1;

    cardEffect(minion, choice1, choice2, choice3, &testG, handPos, bonus);

    if (testG.coins == (G.coins + 2))
    {
        printf("Test 6: PASSED: +2 coins for second choice\n");
    }
    else
    {
        printf("Test 6: FAILED: NOT +2 coins... problem\n");
    }

    printf("\n////////// SUCCESS: Testing Complete for %s //////////\n\n", TESTCARD);

    return 0;
}