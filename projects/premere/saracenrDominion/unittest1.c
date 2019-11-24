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
#include <stdlib.h>

#define TESTCARD "baron"

int main() {

    // initialize all variables
    int newCards = 0;
    int discarded = 1;
    int extraCoins = 0;
    int shuffledCards = 0;

    int i, j, k;
    int handPos = 0;
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
                                        
    // Card Supplies available
    int cardSupplies[10] = {  baron, embargo, village, minion, mine, 
                            cutpurse, sea_hag, tribute, smithy, council_room };

    // initialize a game state and player cards
    initializeGame(numPlayers, cardSupplies, seed, &G);


    printf("\n////////// Testing Card %s //////////\n", TESTCARD);
    
    ////////// TEST #1: +1 Buy
    printf("\n////////// TEST 1: +1 Buy\n");
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 0; // don't have an Estate to discard
    
    cardEffect(baron, choice1, choice2, choice3, &testG, handPos, bonus);

    // did number of buys increase?
    if (&testG.numBuys == (&G.numBuys + 1))
    {
        printf("PASSED: Test 1a: +1 Buys.\n");
    }
    else 
    {
        printf("FAILED: Test 1a: Did not increment num of Buys.\n");
    }


    ////////// TEST #2: Does Player have Estate to Discard?
    printf("\n////////// TEST 2: Does Player have Estate to discard?\n");
    int currentPlayer = testG.whoseTurn;
    // ensure new hand does NOT have an Estate
    //  use gainCard() ??

    int p = 0; // iterator for hand of cards
    int card_not_discarded = 1;//Flag for discard set!
    for (p; p < numHandCards(&testG); p++)
    {
        if (&testG.hand[currentPlayer][p] == estate)
        { //Found an estate card!
            printf("FAILED: Test 2a: Cannot make this choice; you have an Estate Card to discard.\n");
        }
        else
        {
            printf("PASSED: Test 2a: No estate card in your hand.\n");
        }
    }



    ////////// TEST #3: Does Supply Still Give Estate When Empty
    printf("\n////////// TEST 3: Does Supply Still Give Estate When Empty\n");
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 0; // don't have an Estate to discard
    
    cardEffect(baron, choice1, choice2, choice3, &testG, handPos, bonus);

    // estate supply is currently full b/c new game
    if (supplyCount(estate, &testG) > 0) 
    {
        if ((numHandCards(&testG)) == (numHandCards(&G))) 
        {
            printf("FAILED: Test 3a: Did not discard card.\n");
        }
    }
    // estate supply should not be <= 0 currently     
    else if (supplyCount(estate, &testG) <= 0)
    {
        printf("FAILED: Test 3a: Supply Cannot Be Below 0.\n");
    }
   

    ////////// TEST #4: Does Supply Still Give Estate When Empty
    printf("\n////////// TEST 4: Does Supply Still Give Estate When Empty\n");
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 0; // don't have an Estate to discard

    cardEffect(baron, choice1, choice2, choice3, &testG, handPos, bonus);

    // does Estate supply properly NOT give player new Estate card when supply is OUT?
    while (supplyCount(estate, &testG) != 0)
    {
        testG.supplyCount[estate]--;
    }
    while (supplyCount(estate, &G) != 0)
    {
        G.supplyCount[estate]--;
    }

    // estate supply is currently EMPTY
    if (supplyCount(estate, &testG) > 0) 
    {
        if ((numHandCards(&testG)) == (numHandCards(&G))) 
        {
            printf("FAILED: Test 4a: Did not discard card.\n");
        }
    }   
    
    if (supplyCount(estate, &testG) <= 0)
    {
        printf("FAILED: Test 4a: Supply Cannot Be Below 0.\n");
       
        // did player receive an estate when the supply was empty/below?
        if (supplyCount(estate, &testG) != supplyCount(estate, &G)) // because should not have given any estate cards
        {
            printf("FAILED: Test 4b: Gained an Estate when supply was supposed to be empty.\n");
        }
    }



    ////////// TEST #5: Does proper amount of treasure get added to player's purse?
    printf("\n////////// TEST 5: Does proper amount of treasure get added to player's purse?\n");
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 1; // discard an estate for +4 treasure

    cardEffect(baron, choice1, choice2, choice3, &testG, handPos, bonus);

    if (&testG.coins == &G.coins + 4)
    {
        printf("PASSED: Test 5a: Correct number of treasure given.\n");
    }
    else{
        printf("FAILED: Test 5a: INcorrect number of treasure given.\n");
    }


    ////////// TEST #6: Player Chooses to discard an Estate when they do not have an Estate
    printf("\n////////// TEST 6: Player Chooses to discard an Estate when they do not have an Estate.\n");
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 1; // wants to discard an Estate
    
    // ensure new hand does NOT have an Estate for testing
    for (p = 0; p < numHandCards(&testG); p++)
    {
        if (testG.hand[currentPlayer][p] == estate)
        { //Found an estate card!
            // reassign it to another card for testing purposes
            testG.hand[currentPlayer][p] = 11;
        }
    }

    cardEffect(baron, choice1, choice2, choice3, &testG, handPos, bonus);
    currentPlayer = testG.whoseTurn;


    int foundEstate = 0;
    for (p = 0; p < numHandCards(&testG); p++)
    {
        if (testG.hand[currentPlayer][p] == estate)
        { //Found an estate card!
            printf("FAILED: Test 6a: Cannot make this choice; you have an Estate Card to discard.\n");
            foundEstate = 1;
        }
    }
    if (foundEstate == 0)
    {
        printf("FAILED: Cannot discard an Estate; you do not have one.\n");
    }
    






    // does hand get traversed infinitely?
    // a bug I introduced in Ass #2 causes an infinite loop, 
    //      which cannot be properly tested because of
    //      the halting problem ... unless I use a unit testing
    //      framework to track the amount of time it takes to
    //      complete the loop, which I don't have access to
    


    printf("\n////////// SUCCESS: Testing Complete for %s //////////\n\n", TESTCARD);

    return 0;
}