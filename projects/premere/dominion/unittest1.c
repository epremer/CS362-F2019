// baron
// +1 Buy... You may discard an Estate for +4 treasure. 
//      If you don't, gain an Estate.

/******************************************
* Program Name: unittest1.c
* Assignment Name: Assignment 3
* Author: Elizabeth Premer
* Date Due: 10 November 2019
* Description: This is a test suite for Dominion 
*               game play using the BARON card.
* NOTE: The initialized variables and skeleton
*       of this code is loosely borrowed from
*       the sample code provided in the 
*       lectures/course modules.
******************************************/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
//#include <assert.h>
#include <stdlib.h>

#define TESTCARD "baron"

int main() {

    // initialize all variables
    int newCards = 0;
    int discarded = 1;
    int extraCoins = 0;
    int suffledCards = 0;

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

    int result; // used for testing if tests pass??
    
    struct gameState G, testG;
                                        // does this include an Estate?
    // Card Supplies available
    // must be 'k'?
    int cardSupplies[10] = {  adventurer, embargo, village, minion, mine, 
                            cutpurse, sea_hag, tribute, smithy, council_room };

    // initialize a game state and player cards
    initializeGame(numPlayers, cardSupplies, seed, &G);

    printf("\n////////// Testing Card %s //////////\n", TESTCARD);

    ////////// TEST #1: If you have an Estate, Discard an Estate for +4 Treasure
    printf("////////// TEST 1: If you have an Estate, Discard one for +4 Treasure\n");

    // copy game state to a test case
    // do I need to 
    //memset(&G, 23, sizeof(struct gameState)); // what is 23 here?
    memcpy(&testG, &G, sizeof(struct gameState));   // for new test
    choice1 = 1;
    // cardEffect for BARON
    result = cardBaron(whoseTurn(&testG), choice1, &testG); // what do i do with result??

    // assertions
    if (result == 0)
    {
        printf("RESULT == 0"); 
        // also test the game state ... not sure what that means
        // test preState against gameState ... ??   &testG vs &G ??
    }
    else if (result == 1)
    {
        printf("RESULT == 1");
    }
    else
    {
        printf("RESULT != 0 && RESULT != 1");
    }

    ////////// TEST #2: If no Estate, gain one.
    printf("////////// TEST 1: If no Estate, gain one.\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));   // for new test

    // cardEffect for BARON
    // test if the hand doesn't have an estate
    // if doesn't, add one from Supply
    //      Estate Supply -1
    //      Hand +1

    printf("\n////////// SUCCESS: Testing Complete for %s //////////\n\n", TESTCARD);

    return 0;
}