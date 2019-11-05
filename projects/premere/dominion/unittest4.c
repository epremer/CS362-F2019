// tribute
// The player to your left reveals then discards
//      the top 2 cards of his deck.
// For each differently named card revealed, if
//      it is:
//  1) Action Card: +2 Actions
//  2) Treasure Card: +2 treasure
//  3) Victory Card: +2 cards

/******************************************
* Program Name: unittest4.c
* Assignment Name: Assignment 3
* Author: Elizabeth Premer
* Date Due: 10 November 2019
* Description: This is a test suite for Dominion 
*               game play using the TRIBUTE card.
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

#define TESTCARD "tribute"

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
    
    struct gameState G, testG;
    int cardSupplies[10] = {  adventurer, embargo, village, minion, mine,
                            cutpurse, sea_hag, tribute, smithy, council_room };

    // initialize a game state and player cards
    initializeGame(numPlayers, cardSupplies, seed, &G);

    printf("\n////////// Testing Card %s //////////\n", TESTCARD);

    ////////// TEST #1: 
    printf("////////// TEST 1: \n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 1;
    // cardEffect for TRIBUTE

    ////////// TEST #2:
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 2;
    // cardEffect for TRIBUTE

    printf("\n////////// SUCCESS: Testing Complete for %s //////////\n\n", TESTCARD);

    return 0;
}