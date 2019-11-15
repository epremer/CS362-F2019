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


    ////////// TEST #1: Test Copper as Trashed Treasure & Copper as Chosen Treasure
    printf("////////// TEST 1: Test Copper as Trashed Treasure & Copper as Chosen Treasure\n");


    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = copper;
    choice2 = copper;
    int currentPlayer = testG.whoseTurn;

    cardEffect(mine, choice1, choice2, choice3, &testG, handPos, bonus);


    // negative cases
    // picking a card that isn't copper, silver, gold
    if (testG.hand[currentPlayer][choice1] < copper || testG.hand[currentPlayer][choice1] > gold)
    {
        printf("FAILED: Test 1a: check card is not less than Copper or greater than Gold\n");
    }

    if (choice2 > treasure_map || choice2 < curse)
    {
        printf("FAILED: Test 1b: check card is greater than treasure map or less than curse\n");
    }

    if ((getCost(&testG.hand[currentPlayer][choice1]) +3) >= getCost(choice2) )
    {
        printf("FAILED: Test 1c: Cost is not at least the same as trashed card plus 3.\n");
    }

    // check gainCard()
    // Test: Drew right amount of cards
    if ((numHandCards(&testG)) == (numHandCards(&G))) 
    {
        printf("FAILED: Test 1d: Did not discard card.\n");
    }
    else if ((numHandCards(&testG)) == (numHandCards(&G) - 1))
    {
        printf("PASSED: Test 1d: Discarded card.\n");
    }

    // check supply
    if ((supplyCount(copper, &testG)) == supplyCount(copper, &G) - 1) 
    {
        printf("PASSED Test 1d: Copper Supply Pile Successfully Decremented.\n");
    }




    ////////// TEST #2: Test Adventurer as Trashed Treasure & Silver as Chosen Treasure
    printf("\n////////// TEST 2: Test Adventurer as Trashed Treasure & Silver as Chosen Treasure\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = adventurer;
    choice2 = silver;
    currentPlayer = testG.whoseTurn;

    cardEffect(mine, choice1, choice2, choice3, &testG, handPos, bonus);

    if (&testG.hand[currentPlayer][choice1] < copper || &testG.hand[currentPlayer][choice1] > gold)
    {
        printf("FAILED: Test 2a: check card is not less than Copper or greater than Gold\n");
    }

    if (choice2 > treasure_map || choice2 < curse)
    {
        printf("FAILED: Test 2b: check card is greater than treasure map or less than curse\n");
    }

    if ((getCost(&testG.hand[currentPlayer][choice1]) +3) > getCost(choice2) )
    {
        printf("FAILED: Test 2c: cost is too high\n");
    }
    else {
        printf("FAILED: Test 2d: Copper Supply Pile Failed to Decrement.\n");
    }


    ////////// TEST #3: Test that Copper can be exchanged for Silver
    printf("\n////////// TEST 3: Test that Copper can be exchanged for Silver\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = copper;
    choice2 = silver;
    currentPlayer = testG.whoseTurn;

    cardEffect(mine, choice1, choice2, choice3, &testG, handPos, bonus);
    
    // negative cases
    // picking a card that isn't copper, silver, gold
    if (&testG.hand[currentPlayer][choice2] < copper || &testG.hand[currentPlayer][choice2] > gold)
    {
        printf("FAILED: Test 3a: check card is not less than Copper or greater than Gold\n");
    }

    if (choice2 > treasure_map || choice2 < curse)
    {
        printf("FAILED: Test 3b: check card is greater than treasure map or less than curse\n");
    }

    if ((getCost(&testG.hand[currentPlayer][choice1]) +3) > getCost(choice2) )
    {
        printf("FAILED: Test 3c: cost is too high\n");
    }

    // check gainCard()
    // Test: Drew right amount of cards
    // Test: Did card get discarded? decked? handed?

    if ((numHandCards(&testG)) == (numHandCards(&G))) 
    {
        printf("FAILED: Test 3d: Did not discard card.\n");
    }

    // check supply
    if ((supplyCount(silver, &testG)) == supplyCount(silver, &G) - 1) 
    {
        printf("PASSED: Test 3e: Silver Supply Pile Successfully Decremented.\n");
    }
    else {
        printf("FAILED: Test 3e: Silver Supply Pile Failed to Decrement.\n");
    }


    printf("\n////////// SUCCESS: Testing Complete for %s //////////\n\n", TESTCARD);

    return 0;
}