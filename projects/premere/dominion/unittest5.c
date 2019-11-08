// mine
// You may trash a Treasure card from your hand.
//      Gain a Treasure to your hand costing
//      up to 3 more treasure than it.

/******************************************
* Program Name: unittest5.c
* Assignment Name: Assignment 3
* Author: Elizabeth Premer
* Date Due: 10 November 2019
* Description: This is a test suite for Dominion 
*               game play using the MINE card.
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

#define TESTCARD "mine"

int main() {

    // initialize all variables
    int newCards = 0;
    int discarded = 1; // the current card being used
    int extraCoins = 0;
    int shuffledCards = 0;

    int i, j, k;
    int handpos = 0;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    
    struct gameState G, testG;
                                    
    int cardSupplies[10] = {  adventurer, embargo, village, minion, mine,
                            cutpurse, sea_hag, tribute, smithy, council_room };

    // initialize a game state and player cards
    initializeGame(numPlayers, cardSupplies, seed, &G);

    printf("\n////////// Testing Card %s //////////\n", TESTCARD);


    ////////// TEST #1: Test Copper as Trashed Treasure
    printf("////////// TEST 1: Test Copper as Trashed Treasure\n");


    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = copper;
    choice2 = copper;
    cardEffect(mine, choice1, choice2, choice3, &testG, handPos, bonus);

    if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
    {
        printf("FAILED: Test : check card is not less than Copper or greater than Gold");
    }

    if (choice2 > treasure_map || choice2 < curse)
    {
        printf("FAILED: Test : check card is greater than treasure map or less than curse");
    }

    if ((getCost(testG->hand[currentPlayer][choice1]) +3) > getCost(choice2) )
    {
        printf("FAILED: Test :");
    }

    // negative case
    // picking a card that isn't copper, silver, gold
    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = adventurer;
    choice2 = silver;
    cardEffect(mine, choice1, choice2, choice3, &testG, handPos, bonus);

    if (&testG->hand[currentPlayer][choice1] < copper || &testG->hand[currentPlayer][choice1] > gold)
    {
        printf("FAILED: Test : check card is not less than Copper or greater than Gold");
    }

    if (choice2 > treasure_map || choice2 < curse)
    {
        printf("FAILED: Test : check card is greater than treasure map or less than curse");
    }

    if ((getCost(testG->hand[currentPlayer][choice1]) +3) > getCost(choice2) )
    {
        printf("FAILED: Test :");
    }

    // check gainCard()
    // Test: Drew right amount of cards
    if ((numHandCards(&testG)) == (numHandCards(&G))) 
    {
        printf("FAILED: Did not discard and draw a card.")
    } 

    // check supply
    if ((supplyCount(copper, &testG)) == supplyCount(copper, &G) - 1) 
    {
        printf("PASSED: ")
    }









    ////////// TEST #2: Test that Copper can be exchanged for Silver
    printf("////////// TEST 2: Test that Copper can be exchanged for Silver\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    cardEffect(mine, copper, silver, choice3, &testG, handPos, bonus);
    
    gainCard(choice2, &testG, 2, currentPlayer)


    memcpy(&testG, &G, sizeof(struct gameState));
    if ((testG->supplyCount[choice2]))

    ////////// TEST #2: Choose not to trash treasure
    printf("////////// TEST 2: Choose not to trash Treasure card.\n");
    memcpy(&testG, &G, sizeof(struct gameState));
    // nothing changes, except mine is discarded
    // handcount

    ////////// TEST #4: Check chosen treasure supply decremented
    printf("////////// TEST 4: Check chosen treasure supply is decremented\n");
    memcpy(&testG, &G, sizeof(struct gameState));
   
    // cardEffect for MINE

    ////////// TEST #5: Check that discard pile unchanged
    printf("////////// TEST 5: Check that discard pile is unchanged (card should be trashed, not discarded)\n");
    memcpy(&testG, &G, sizeof(struct gameState));
    
    // cardEffect for MINE

    ////////// TEST #6: If Copper trashed, gain Copper or Silver only
    printf("////////// TEST 6: If Copper trashed, gain Copper or Silver only\n");
    memcpy(&testG, &G, sizeof(struct gameState));
    
    // cardEffect for MINE

    ////////// TEST #7: If Silver trashed, gain Silver or Gold only
    printf("////////// TEST 7: If Silver trashed, gain Silver or Gold only\n");
    memcpy(&testG, &G, sizeof(struct gameState));

    ////////// TEST #6: If Gold trashed, gain Gold only
    printf("////////// TEST 6: If Gold trashed, gain Gold only\n");
    memcpy(&testG, &G, sizeof(struct gameState));
    
    // cardEffect for MINE
    
    // cardEffect for MINE

    printf("\n////////// SUCCESS: Testing Complete for %s //////////\n\n", TESTCARD);

    return 0;
}