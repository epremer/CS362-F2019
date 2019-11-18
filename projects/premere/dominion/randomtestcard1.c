// baron
// +1 Buy... You may discard an Estate for +4 treasure. 
//      If you don't, gain an Estate.

/******************************************
* Program Name: randomcardtest1.c
* Assignment Name: Assignment 4
* Author: Elizabeth Premer
* Date Due: 17 November 2019
* Description: This is a random test suite for Dominion 
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

#define TESTCARD "Baron"
#define N 60000

int testCard(int numPlayers, struct gameState G)
{
    int testsFailed = 0;

    // initialize all variables
    int handPos = 0;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int bonus = 0;
    int seed = 1000;
    
    struct gameState testG;
                                        
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
        testsFailed++;
    }


    ////////// TEST #2: Does Player have Estate to Discard?
    printf("\n////////// TEST 2: Does Player have Estate to discard?\n");
    int currentPlayer = testG.whoseTurn;
    // ensure new hand does NOT have an Estate
    //  use gainCard() ??

    int p = 0; // iterator for hand of cards
    for (p; p < numHandCards(&testG); p++)
    {
        if (&testG.hand[currentPlayer][p] == estate)
        { //Found an estate card!
            printf("FAILED: Test 2a: Cannot make this choice; you have an Estate Card to discard.\n");
            testsFailed++;
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
            testsFailed++;
        }
    }
    // estate supply should not be <= 0 currently     
    else if (supplyCount(estate, &testG) <= 0)
    {
        printf("FAILED: Test 3a: Supply Cannot Be Below 0.\n");
        testsFailed++;
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
    printf("\nSUPPLY COUNT1: %d\n", testG.supplyCount[estate]);
    while (supplyCount(estate, &G) != 0)
    {
        G.supplyCount[estate]--;
    }
    printf("\nSUPPLY COUNT2: %d\n", testG.supplyCount[estate]);

    // estate supply is currently EMPTY
    if (supplyCount(estate, &testG) > 0) 
    {
        if ((numHandCards(&testG)) == (numHandCards(&G))) 
        {
            printf("FAILED: Test 4a: Did not discard card.\n");
            testsFailed++;
        }
    }   
    
    if (supplyCount(estate, &testG) <= 0)
    {
        printf("FAILED: Test 4a: Supply Cannot Be Below 0.\n");
        testsFailed++;
       
        // did player receive an estate when the supply was empty/below?
        printf("\nSUPPLY COUNT3: %d\n", testG.supplyCount[estate]);
        if (supplyCount(estate, &testG) != supplyCount(estate, &G)) // because should not have given any estate cards
        {
            printf("FAILED: Test 4b: Gained an Estate when supply was supposed to be empty.\n");
            testsFailed++;
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
        testsFailed++;
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
            testsFailed++;
        }
    }
    if (foundEstate == 0)
    {
        printf("FAILED: Cannot discard an Estate; you do not have one.\n");
        testsFailed++;
    }

    ////////// TEST #7: Does Supply Still Give Estate When NOT Empty
    printf("\n////////// TEST 7: Does Supply Still Give Estate When NOT Empty\n");
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 0; // don't have an Estate to discard

    cardEffect(baron, choice1, choice2, choice3, &testG, handPos, bonus);

    // does Estate supply properly give player new Estate card?
    if (supplyCount(estate, &testG) >= 0)
    {
        if (testG.supplyCount[estate] == G.supplyCount[estate]-1)
        {
            printf("PASSED: Test 7a: Gives an Estate when supply contains Estates to give\n");
        }
        else 
        {
            printf("FAILED: Test 7a: Does NOT give an Estate when should\n");
            testsFailed++;
        }
            
        if ((numHandCards(&testG)) == (numHandCards(&G))) 
        {
            printf("FAILED: Test 7b: Did not put new Estate into discard.\n");
            testsFailed++;
        }
        else if ((numHandCards(&testG)) == (numHandCards(&G) + 1))
        {
            printf("PASSED: Test 7b: Correctly put new Estate into discard pile\n");
        }
    }


    ////////// TEST #8: Does Game End Early?
    printf("\n////////// TEST 8: Does Game End Early?\n");
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 0; // don't have an Estate to discard

    cardEffect(baron, choice1, choice2, choice3, &testG, handPos, bonus);

    testG.supplyCount[estate] = 0;

    if (choice1 <= 0)
    {
        if (supplyCount(estate, &testG) >= 0)
        {
            if (supplyCount(estate, &testG) == (supplyCount(estate, &G)-1))
            {
                printf("PASSED: Test 8a: Properly decremented the estate supply\n");
            }
            if (supplyCount(estate, &testG) == 0)
            {
                if (isGameOver(&testG) == isGameOver(&G))
                {
                    printf("FAILED: Test 8b: Game was supposed\n");
                    testsFailed++;
                }
            }
        }
    }

        ////////// TEST #1: NextPlayer's (NP's) deckCount gets decremented when NP's deck has cards for revealing
    printf("\n////////// TEST 1 TRIBUTE CARD: NextPlayer's (NP's) deckCount gets decremented when NP's deck has cards for revealing\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    int nextPlayer = currentPlayer + 1;
    
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);

    // if the nextPlayer's deck and discard <= 1 (they have none)
    //      and if nextPlayer's deck > 0
    //              tributeRevealedCards = {-1, -1} turns into
    //              tributeRevealedCards[0] = {top card of nextPlayer's deck}
    //              decrement nextPlayer's deckCount
   
    // test that nextPlayer's deckCount gets decremented when nextPlayer's deck has cards
    if ((testG.discardCount[nextPlayer] + testG.deckCount[nextPlayer]) >= 1)
    {
        if (testG.deckCount[nextPlayer] > 0)
        {
            if (testG.discardCount[nextPlayer] == G.discardCount[nextPlayer] - 1)
            {
                printf("PASSED: Test 1: Next Player's Discard properly decremented.\n");
            }
            else
            {
                printf("FAILED: Test 1: Next Player's Discard NOT properly decremented.\n");
            }
        }
    }


    return testsFailed;
}

int main() {

    int testsFailed = 0;
    srand(time(NULL));

    // Card Supplies available
    int cardSupplies[10] = {  baron, embargo, village, minion, mine, 
                            cutpurse, sea_hag, tribute, smithy, council_room };
    int seed = 1000;

    // loop however many number of times to test
    for (int i = 0; i < N; i++)
    {
        // create a new game state
        struct gameState G;
        int currentPlayer = G.whoseTurn;

        // randomize the values
        // randomize number of players
        int numPlayers = G.numPlayers;
        G.numPlayers = rand() % MAX_PLAYERS;
    
        // initialize game
        initializeGame(numPlayers, cardSupplies, seed, &G);

        // randomize number of cards in hand count for each player affected by card
        G.handCount[currentPlayer] = rand() % MAX_DECK;

        // randomize number of cards in the deck
        G.deckCount[currentPlayer] = rand() % MAX_DECK;

        // randomize number of cards in discard count
        G.discardCount[currentPlayer] = rand();

        // randomize number of cards played
        G.playedCards[MAX_DECK] = rand();

        // run unit tests for the card
        testsFailed += testCard(numPlayers, G);
    }

    printf("\n////////// SUCCESS: Testing Complete for %s //////////\n\n", TESTCARD);
    printf("Number of Tests Failed: %d\n\n", testsFailed);
    return 0;
}