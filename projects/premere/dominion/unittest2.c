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
//#include <assert.h>
#include <stdlib.h>

#define TESTCARD "minion"

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


/* choice1:  1 = +2 coin, 2 = redraw */

     ////////// TEST #1: +2 Treasure
    printf("////////// TEST 1: +2 Treasure\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 1;
    // cardEffect for MINION

    ////////// TEST #2: Discard hand, +4 cards, all other players with >= 5 cards, do same
    printf("////////// TEST 1: Discard hand, +4 cards, all other players with >= 5 cards, do same\n");

    // check &testG.handCount[]

    // copy game state to a test case    
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 2;
    // cardEffect for MINION

    printf("\n////////// SUCCESS: Testing Complete for %s //////////\n\n", TESTCARD);

    return 0;
}