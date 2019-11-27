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

    printf("\n////////// Testing Card AMBASSADOR //////////\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    int currentPlayer = testG.whoseTurn;

    for (i = 0; i < &testG.handCount[currentPlayer]; i++)
    {
        if (i != handPos && &testG.hand[currentPlayer][i] && i != choice1)
        {
            if ()
            {
                printf("TEST BUG_10: FAILED: \n");
                j++;
            }
        }
    }


    ////////// TEST #1 When choice2 == 5
    printf("\n////////// TEST 1 When choice2 == 5\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    int currentPlayer = testG.whoseTurn;

    choice2 = 5; // should be no more than 2

    cardEffect(ambassador, choice1, choice2, choice3, &testG, handPos, bonus);

    if (choice2 < 2 || choice2 > 0)
    {
        printf("Test 1: FAILED for old bug\n");
    }
    if (choice2 > 2 || choice2 < 0)
    {
        printf("Test 1: FAILED for original code\n");
    }
    else 
    {
        printf("Test 1: FAILED for original code. Should be no more than 2.\n");
    }



    ////////// TEST #2 When choice2 == 0
    printf("\n////////// TEST 2 When choice2 == 0\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;

    choice2 = 0;

    cardEffect(ambassador, choice1, choice2, choice3, &testG, handPos, bonus);

    if (choice2 < 2 || choice2 > 0)
    {
        printf("Test 2: FAILED for old bug\n");
    }
    if (choice2 > 2 || choice2 < 0)
    {
        printf("Test 2: FAILED for original code\n");
    }
    else 
    {
        printf("Test 2: PASSED for original code. Can be 0 cards returned to supply.\n");
    }


    ////////// TEST #3 When choice2 == 1
    printf("\n////////// TEST 3 When choice2 == 1\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;

    choice2 = 1;

    cardEffect(ambassador, choice1, choice2, choice3, &testG, handPos, bonus);

    if (choice2 < 2 || choice2 > 0)
    {
        printf("Test 3: FAILED for old bug\n");
    }
    if (choice2 > 2 || choice2 < 0)
    {
        printf("Test 3: FAILED for original code\n");
    }
    else 
    {
        printf("Test 3: PASSED for original code. Can be up to 2 cards returned to supply\n");
    }


    ////////// TEST #4 When choice2 == -2
    printf("\n////////// TEST 4 When choice2 == -2\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;

    choice2 = -2; // cannot be negative number

    cardEffect(ambassador, choice1, choice2, choice3, &testG, handPos, bonus);

    if (choice2 < 2 || choice2 > 0)
    {
        printf("Test 4: FAILED for old bug\n");
    }
    if (choice2 > 2 || choice2 < 0)
    {
        printf("Test 4: FAILED for original code\n");
    }
    else 
    {
        printf("Test 4: FAILED for original code. Cannot be negative number of cards.\n");
    }



    ////////// TEST #5 when choice1 == handPos
    printf("\n////////// TEST 5 when choice1 == handPos\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    choice1 = 1; // position in hand
    choice2 = 2; // number of cards to discard

    cardEffect(ambassador, choice1, choice2, choice3, &testG, handPos, bonus);

    if (choice1 == handPos)
    {
        printf("Test 5: FAILED: When choice1 == handPos\n");
    }
    else
    {
        printf("Test 5: PASSED When choice1 == handPos\n");
    }


    ////////// TEST #6
    printf("\n////////// TEST 6\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    choice1 = 1; // position in hand
    choice2 = 2; // number of cards to discard

    cardEffect(ambassador, choice1, choice2, choice3, &testG, handPos, bonus);

    for (i = 0; i < testG.handCount[currentPlayer]; i++)
    {
        if (i != handPos && i == testG.hand[currentPlayer][choice1] && i != choice1)
        {
            printf("Test 6_%d: PASSED\n", i);
            j++;
        }
        else
        {
            printf("Test 6_%d: FAILED\n", i);
            j++;
        }
    }


// Reveal a card from your hand. Return up to
//      two copies of it from your hand to the
//      Supply. Then each other player gains
//      a copy of it.

    ////////// TEST #7 Increase supply count for chosen card by amount being discarded
    printf("\n////////// TEST 7 Increase supply count for chosen card by amount being discarded\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    choice1 = 1; // position in hand
    choice2 = 2; // number of cards to discard
    
    cardEffect(ambassador, choice1, choice2, choice3, &testG, handPos, bonus);

    if ((testG.supplyCount[testG.hand[currentPlayer][choice1]] += choice2) == (G.supplyCount[G.hand[currentPlayer][choice1]] += choice2))
    {
        printf("Test 7: PASSED Supply is increased for chosen card.\n");
    }


    ////////// TEST #8 Introduced bug that loops through number of players -1 for numPlayers == 5
    printf("\n////////// TEST 8 Introduced bug that loops through number of players -1 for numPlayers == 5\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    choice1 = 1; // position in hand
    choice2 = 2; // number of cards to discard
    

    cardEffect(ambassador, choice1, choice2, choice3, &testG, handPos, bonus);

    testG.numPlayers = 5;

    int gotCard = 0;  // number of players who received the card (including currentPlayer)
    printf("NUMPLAYERS: %d\n", testG.numPlayers);
    for (i = 0; i < testG.numPlayers; i++)
    {
        if (i != currentPlayer)
        {
            gotCard++;
        }
    }
    printf("GotCard: %d\n", gotCard);

    if (gotCard == (testG.numPlayers))
    {
        printf("Test 8a: PASSED: All other players were traversed.\n");
    }
    else
    {
        printf("Test 8a: FAILED: NOT all players were traversed.\n");
    }


    if (testG.discardCount[currentPlayer] == (G.discardCount[currentPlayer]+1))
    {
        printf("Test 8b: PASSED: testG discard == G discard\n");
    }
    else
    {
        printf("Test 8b: FAILED: testG discard != G DISCARD\n");
    }



    ////////// TEST #9 Introduced bug that loops through number of players -1 for numPlayer=2
    printf("\n////////// TEST 9 Introduced bug that loops through number of players -1 for numPlayers==2\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    choice1 = 1; // position in hand
    choice2 = 2; // number of cards to discard
    

    cardEffect(ambassador, choice1, choice2, choice3, &testG, handPos, bonus);

    testG.numPlayers = 2;

    gotCard = 0;  // number of players who received the card (including currentPlayer)
    printf("NUMPLAYERS: %d\n", testG.numPlayers);
    for (i = 0; i < testG.numPlayers; i++)
    {
        if (i != currentPlayer)
        {
            gotCard++;
        }
    }
    printf("GotCard: %d\n", gotCard);

    if (gotCard == (testG.numPlayers))
    {
        printf("Test 8a: PASSED: The other player was traversed.\n");
    }
    else
    {
        printf("Test 8a: FAILED: The other player was NOT traversed.\n");
    }


    if (testG.discardCount[currentPlayer] == (G.discardCount[currentPlayer]+1))
    {
        printf("Test 8b: PASSED: testG discard == G discard\n");
    }
    else
    {
        printf("Test 8b: FAILED: testG discard != G DISCARD\n");
    }


    ////////// TEST #10 Each other player gains copy of revealed card
    printf("\n////////// TEST 10 Each other player gains copy of revealed card\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    choice1 = 1; // position in hand
    choice2 = 2; // number of cards to discard

    cardEffect(ambassador, choice1, choice2, choice3, &testG, handPos, bonus);

    // for loop j=0..choice2
    for (j = 0; j < choice2; j++)
    //  for loop i=0..testG.handCount[currentPlayer]
    {
        for (i = 0; i < testG.handCount[currentPlayer]; i++)
        {
            if(testG.hand[currentPlayer][i] == testG.hand[currentPlayer][choice1])
            {
                if (testG.discardCount[currentPlayer] == G.discardCount[currentPlayer])
                {
                    printf("Test 10: \n");
                }
                else
                {
                    printf("Test 10: \n");
                }
            }
        }
    }
    


    printf("\n////////// SUCCESS: Testing Complete for AMBASSADOR //////////\n\n");

    return 0;
}