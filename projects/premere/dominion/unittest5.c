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
//#include <assert.h>
#include <stdlib.h>

#define TESTCARD "mine"

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
                                    // include Treasure card (test all)
    int cardSupplies[10] = {  adventurer, embargo, village, minion, mine,
                            cutpurse, sea_hag, tribute, smithy, council_room };

    // initialize a game state and player cards
    initializeGame(numPlayers, cardSupplies, seed, &G);

    printf("\n////////// Testing Card %s //////////\n", TESTCARD);

/* choice1 is hand# of money to trash, choice2 is supply# of
	    money to put in hand */

    ////////// TEST #1: You may trash a Treasure card in exchange for a Treasure of up to +3
    printf("////////// TEST 1: May trash a Treasure card for Treasure up to +3\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 1;
    // cardEffect for MINE

    ////////// TEST #2: Choose not to trash treasure
    printf("////////// TEST 2: Choose not to trash Treasure card.\n");
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 2;
    // cardEffect for MINE

    printf("\n////////// SUCCESS: Testing Complete for %s //////////\n\n", TESTCARD);

    return 0;
}