// ambassador
// Reveal a card from your hand. Return up to
//      two copies of it from your hand to the
//      Supply. Then each other player gains
//      a copy of it.

/******************************************
* Program Name: unittest3.c
* Assignment Name: Assignment 3
* Author: Elizabeth Premer
* Date Due: 10 November 2019
* Description: This is a test suite for Dominion 
*               game play using the AMBASSADOR card.
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

#define TESTCARD "ambassador"

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
                                    // include ambassador and up to three of another card
    int cardSupplies[10] = {  adventurer, embargo, village, minion, mine,
                            cutpurse, sea_hag, tribute, smithy, council_room };

    // initialize a game state and player cards
    initializeGame(numPlayers, cardSupplies, seed, &G);

    printf("\n////////// Testing Card %s //////////\n", TESTCARD);

/* choice1 = hand#, choice2 = number to return to supply */

    ////////// TEST #1: Reveal a card from your hand. Return up to
                //      two copies of it from your hand to the
                //      Supply. Then each other player gains
                //      a copy of it.
    printf("////////// TEST 1: \n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 1;
    // cardEffect for AMBASSADOR

    ////////// TEST #2:
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 2;
    // cardEffect for AMBASSADOR

    printf("\n////////// SUCCESS: Testing Complete for %s //////////\n\n", TESTCARD);

    return 0;
}