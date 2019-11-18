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
#include <stdlib.h>

#define TESTCARD "tribute"
#define N 60000

void testCard(int numPlayers, struct gameState G)
{
    int testsFailed = 0;

    // initialize all variable
    int handPos = 0;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int bonus = 0;
    int seed = 1000;
    int tributeRevealedCards[2] = {-1, -1};
    
    struct gameState testG;
    int cardSupplies[10] = {  adventurer, embargo, village, minion, mine,
                            cutpurse, sea_hag, tribute, smithy, council_room };


    // initialize a game state and player cards
    initializeGame(numPlayers, cardSupplies, seed, &G);

    printf("\n////////// Testing Card %s //////////\n", TESTCARD);


    printf("PRETEST:\n");
    printf("TRIBUTE REVEALED CARDs: \n Copper: %d,\n Silver: %d,\n Estate: %d,\n Duchy: %d,\n Adventurer: %d,\n Sea Hag: %d\n", copper, silver, estate, duchy, adventurer, sea_hag);

    ////////// TEST #1: NextPlayer's (NP's) deckCount gets decremented when NP's deck has cards for revealing
    printf("\n////////// TEST 1: NextPlayer's (NP's) deckCount gets decremented when NP's deck has cards for revealing\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    int currentPlayer = testG.whoseTurn;
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
    ////////// TEST #2a: Is revealed card the top of NP's deck
    printf("\n////////// TEST 2a: Is revealed card the top of NP's deck?\n");
    // test that top of deck is properly stored as tributeRevealedCard
    printf("1st Tribute Card Revealed: %d\n", tributeRevealedCards[0]);
    printf("Top of NP's Deck: %d\n", testG.deck[nextPlayer]);
    printf("BUG FOUND: NP's deck not properly formated without hardcoding tributeRevealedCards[].\n");
    if (tributeRevealedCards[0] == -1)
    {
        printf("FAILED: Test 2a: Revealed Card Not Properly Stored for Tribute effects.\n");
    }
    else
    {
        if (testG.deck[nextPlayer] == tributeRevealedCards[0])
        {
            printf("Test 2a: Revealed Card is the top card of NP's deck.\n");
        }
        else
        {
            printf("Test 2a: Revealed Card is NOT the top card of NP's deck.\n");
        }
    }



    ////////// TEST #2b: Is revealed card the top of NP's deck
    printf("\n////////// TEST 2b: Is revealed card the top of NP's deck?\n");
    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);
    
    // test that top of deck is properly stored as tributeRevealedCard
    // hardcode top of NP's deck for testing
    printf("Hardcode Top of NP's deck to be Copper\n");
    //testG.deck[nextPlayer] = 4;

    printf("1st Tribute Card Revealed: Copper: %d\n", tributeRevealedCards[0]);
    
    printf("BUG FOUND: NP's deck not properly formated without hardcoding tributeRevealedCards[].\n");

    if (tributeRevealedCards[0] == -1)
    {
        printf("FAILED: Test 2b: Revealed Card Not Properly Stored for Tribute effects.\n");
    }
    else
    {
        if (testG.deck[nextPlayer] == tributeRevealedCards[0])
        {
            printf("Test 2b: Revealed Card is the top card of NP's deck.\n");
        }
        else
        {
            printf("Test 2b: Revealed Card is NOT the top card of NP's deck.\n");
        }
    }

    ////////// TEST #3: Does NP's discardCount get properly decremented when revealed card is from the discard deck?
    printf("\n////////// TEST 3: Does NP's discardCount get properly decremented when revealed card is from the discard deck?\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);

    // if the nextPlayer's deck and discard <= 1 (they have none)
    //      and if nextPlayer's discard deck > 0
    //              tributeRevealedCards = top card of nextPlayer's discard deck
    //              decrement nextPlayer's discard deck
    
    // test that nextPlayer's discardCount gets decremented when nextPlayer's discard has cards and deck does not
    if ((testG.discardCount[nextPlayer] + testG.deckCount[nextPlayer]) >= 1)
    {
        printf("testG.discardCount[nextPlayer]: %d\n", testG.discardCount[nextPlayer]);
        printf("testG.deckCount[nextPlayer]: %d\n", testG.deckCount[nextPlayer]);
        printf("testG.deckCount[nextPlayer]: %d\n", testG.deckCount[nextPlayer]);
        printf("G.deckCount[nextPlayer] minus cards in hand: %d\n", G.deckCount[nextPlayer] - 4);
        
        
        if (testG.discardCount[nextPlayer] > 0)
        {
            if (testG.discardCount[nextPlayer] == G.discardCount[nextPlayer] - 1)
            {
                printf("PASSED: Test 3: Next Player's Discard properly decremented.\n");
            }
            else
            {
                printf("FAILED: Test 3: Next Player's Discard NOT properly decremented.\n");
            }
        }
        if (testG.deckCount[nextPlayer] > 0)
        {
            if (testG.deckCount[nextPlayer] == G.deckCount[nextPlayer] - 5)
            // 5 instead of 1 because of the 4 cards in player's hand ... which is a bug in and of itself since player's are supposed to have 5 cards in their hand
            {
                printf("PASSED: Test 3: Next Player's deck properly decremented.\n");
            }
            else
            {
                printf("FAILED: Test 3: Next Player's deck NOT properly decremented.\n");
            }
        }
    }


    ////////// TEST #4: Is revealed card from NP's discard?
    printf("\n////////// TEST 4: Is revealed card from NP's discard?\n");
    // test that top of discard is properly stored as tributeRevealedCard
    printf("1st Tribute Card Revealed: %d\n", tributeRevealedCards[0]);
    printf("Top of NP's Discard Deck: %d\n", testG.discard[nextPlayer]);
    printf("BUG FOUND: NP's discard deck not properly formated.\n");
    if (tributeRevealedCards[0] == -1)
    {
        printf("FAILED: Test 4: Revealed Card Not Properly Stored for Tribute effects.\n");
    }
    else
    {
        if (testG.discard[nextPlayer] == tributeRevealedCards[0])
        {
            printf("PASSED Test 4: Revealed Card is the top card of NP's discard deck.\n");
        }
        else
        {
            printf("FAILED Test 4: Revealed Card is NOT the top card of NP's discard deck.\n");
        }
    }


    ////////// TEST #5: Validate type of card with proper +2 bonus
    printf("\n////////// TEST 5: Validate type of card with proper +2 bonus\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    nextPlayer = currentPlayer + 1;

    // validate the type of card (action, treasure, victory) with flag
    //      do a +2 thing for each, up to once per flag
    // discardCard()
    int isVictoryCard = 0;
    int isTreasureCard = 0;
    int isActionCard = 0;

    // when tribute cards are copper, silver
    printf("Test 5a: When tribute cards are copper, silver\n");
    tributeRevealedCards[0] = 4;
    tributeRevealedCards[1] = 5;
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);

    isTreasureCard = 1; // one or both cards are treasure cards

    // if both cards are treasure cards
    if (isTreasureCard == 1 && isVictoryCard == 0 && isActionCard == 0) 
    {
        if (testG.coins == G.coins + 2)
        {
            printf("Test 5a_1: PASSED: Both treasure; receive +2 coins\n");
        }
        else
        {
            printf("Test 5a_1: FAILED: Both Treasure; DIDN'T receive +2 coins\n");
        }
                
        // test my FIRST introduced bug
        if (&testG.playedCardCount == (&G.playedCardCount +1))
        {
            printf("Test 5a_2: PASSED: playedCardCount is right for both cards being same type\n");
        }
        else
        {
            printf("Test 5a_2: FAILED: playedCardCount is not right for both cards being same type\n");
        }
    }

    // when tribute cards are copper, estate
    printf("Test 5b: When tribute cards are copper, estate\n");
    tributeRevealedCards[0] = 4;
    tributeRevealedCards[1] = 1;
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);
    
    isTreasureCard = 1; // one or both cards are treasure cards
    isVictoryCard = 1; // one or both cards are Victory cards

    // if cards are one treasure, one victory
    if (isTreasureCard == 1 && isVictoryCard == 1 && isActionCard == 0) 
    {
        if (testG.coins == G.coins + 2)
        {
            printf("Test 5b: PASSED: 1 treasure; receive +2 coins\n");
        }
        else
        {
            printf("Test 5b: FAILED: 1 Treasure; DIDN'T receive +2 coins\n");
        }
        if (numHandCards(&testG) == (numHandCards(&G) + 2))
        {
            printf("Test 5b: PASSED: 1 Victory; receive +2 cards\n");
        }
        else
        {
            printf("Test 5b: FAILED: 1 Victory; DIDN'T receive +2 cards\n");
        }
    }


    // when tribute cards are estate, duchy
    printf("Test 5c: When tribute cards are estate, duchy\n");
    tributeRevealedCards[0] = 1;
    tributeRevealedCards[1] = 2;
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);
    isTreasureCard = 0; // neither cards are treasure cards
    isVictoryCard = 1; // one or both cards are Victory cards

    // if cards are both victory
    if (isTreasureCard == 0 && isVictoryCard == 1 && isActionCard == 0) 
    {
        if (numHandCards(&testG) == (numHandCards(&G) + 2))
        {
            printf("Test 5c: PASSED: Both Victory; receive +2 cards\n");
        }
        else
        {
            printf("Test 5c: FAILED: Both Victory; DIDN'T receive +2 cards\n");
        }
    }

    // when tribute cards are duchy, adventurer
    printf("Test 5d: When tribute cards are duchy, adventurer\n");
    tributeRevealedCards[0] = 2;
    tributeRevealedCards[1] = 7;
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);

    isTreasureCard = 0; // neither cards are treasure cards
    isVictoryCard = 1; // one or both cards are Victory cards
    isActionCard = 1; // one or both cards are Action cards

    // if cards are one action, one victory
    if (isTreasureCard == 0 && isVictoryCard == 1 && isActionCard == 1) 
    {
        if (numHandCards(&testG) == (numHandCards(&G) + 2))
        {
            printf("Test 5d: PASSED: 1 Victory; receive +2 cards\n");
        }
        else
        {
            printf("Test 5d: FAILED: 1 Victory; DIDN'T receive +2 cards\n");
        }
        if (testG.numActions == (G.numActions + 2))
        {
            printf("Test 5d: PASSED: 1 Action; received +2 actions\n");
        }
        else
        {
            printf("Test 5d: FAILED: 1 Action; DIDN'T receive +2 actions\n");
        }
    }


    // when tribute cards are copper, adventurer
    printf("Test 5e: When tribute cards are copper, adventurer\n");
    tributeRevealedCards[0] = 4;
    tributeRevealedCards[1] = 7;
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);

    isTreasureCard = 1; // neither cards are treasure cards
    isVictoryCard = 0; // one or both cards are Victory cards
    isActionCard = 1; // one or both cards are Action cards

    // if cards are one action, one treasure
    if (isTreasureCard == 1 && isVictoryCard == 0 && isActionCard == 1) 
    {
        if (testG.coins == G.coins + 2)
        {
            printf("Test 5e: PASSED: 1 treasure; receive +2 coins\n");
        }
        else
        {
            printf("Test 5e: FAILED: 1 Treasure; DIDN'T receive +2 coins\n");
        }
        if (testG.numActions == (G.numActions + 2))
        {
            printf("Test 5e: PASSED: 1 Action; received +2 actions\n");
        }
        else
        {
            printf("Test 5e: FAILED: 1 Action; DIDN'T receive +2 actions\n");
        }
    }


    // when tribute cards are gold, adventurer
    printf("Test 5f: When tribute cards are gold, adventurer\n");
    tributeRevealedCards[0] = 6;
    tributeRevealedCards[1] = 7;
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);

    isTreasureCard = 1; // neither cards are treasure cards
    isVictoryCard = 0; // one or both cards are Victory cards
    isActionCard = 1; // one or both cards are Action cards

    // if cards are one action, one treasure
    if (isTreasureCard == 1 && isVictoryCard == 0 && isActionCard == 1) 
    {
        if (testG.coins == G.coins + 2)
        {
            printf("Test 5f: PASSED: 1 treasure; receive +2 coins\n");
        }
        else
        {
            printf("Test 5f: FAILED: 1 Treasure; DIDN'T receive +2 coins\n");
        }
        if (testG.numActions == (G.numActions + 2))
        {
            printf("Test 5f: PASSED: 1 Action; received +2 actions\n");
        }
        else
        {
            printf("Test 5f: FAILED: 1 Action; DIDN'T receive +2 actions\n");
        }
    }




    ////////// TEST #: 
    //printf("\n////////// TEST : \n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);

    //printf("NP's deckCount : %d\n", testG.deckCount[nextPlayer]);
    // else
    // if nextPlayer's deck == 0
    //      loop through nextPlayer's discard pile
    //             nextPlayer's deck[i] = nextPlayer's discard[i]
    //             increment nextPlayer's deckCount + 1
    //             remove nextPlayer's card from discard (discard[np][i] = -1)
    //             decrement nextPlayer's discard



    ////////// TEST #: 
    //printf("\n////////// TEST : \n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    nextPlayer = currentPlayer + 1;
    
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);

    // else
    // if nextPlayer's deck == 0
    //      loop through nextPlayer's discard pile
    //             nextPlayer's deck[i] = nextPlayer's discard[i]
    //             increment nextPlayer's deckCount + 1
    //             remove nextPlayer's card from discard (discard[np][i] = -1)
    //             decrement nextPlayer's discard
    //      shuffle new deck


    ////////// TEST #: 
    //printf("\n////////// TEST : \n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    nextPlayer = currentPlayer + 1;
    
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);

    // else
    // if nextPlayer's deck == 0
    //      loop through nextPlayer's discard pile
    //             nextPlayer's deck[i] = nextPlayer's discard[i]
    //             increment nextPlayer's deckCount + 1
    //             remove nextPlayer's card from discard (discard[np][i] = -1)
    //             decrement nextPlayer's discard
    //      shuffle new deck
    // tributeRevealedCards[0] = top of deck
    // decrement nextPlayer's deckCount


    ////////// TEST #: 
    //printf("\n////////// TEST : \n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    nextPlayer = currentPlayer + 1;
    
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);

    // else
    // if nextPlayer's deck == 0
    //      loop through nextPlayer's discard pile
    //             nextPlayer's deck[i] = nextPlayer's discard[i]
    //             increment nextPlayer's deckCount + 1
    //             remove nextPlayer's card from discard (discard[np][i] = -1)
    //             decrement nextPlayer's discard
    //      shuffle new deck
    // tributeRevealedCards[0] = top of deck
    // decrement nextPlayer's deckCount
    //  SECOND card revealed = tributeRevealedCards[1] = top of deck
    //  decrement nextPlayer's deckCount


    ////////// TEST #: 
    //printf("\n////////// TEST : \n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    nextPlayer = currentPlayer + 1;
    
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);

    // do A of above (if/else)
    // if nextPlayer's revealed cards are ==
    //      currentPlayer's playedCards adds the second card revealed


    ////////// TEST #: 
    //printf("\n////////// TEST : \n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    nextPlayer = currentPlayer + 1;
    
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);

    // do A of above (if/else)
    // if nextPlayer's revealed cards are ==
    //      currentPlayer's playedCards adds the second card revealed
    //      currentPlayer's playedCards increments +1 (should fail since it decrements -1 currently)


    ////////// TEST #: 
    //printf("\n////////// TEST : \n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    nextPlayer = currentPlayer + 1;
    
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);

    // do A of above (if/else)
    // if nextPlayer's revealed cards are ==
    //      currentPlayer's playedCards adds the second card revealed

    // do B of above (if/else)
    // if nextPlayer's revealed cards are ==
    //      currentPlayer's playedCards adds the second card revealed


    ////////// TEST #: 
    //printf("\n////////// TEST : \n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    nextPlayer = currentPlayer + 1;
    
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);

    // do B of above (if/else)
    // Test1
    //  if nextPlayer's revealed cards are ==
    //      currentPlayer's playedCards adds the second card revealed
    //      currentPlayer's playedCards increments +1 (should fail since it decrements -1 currently)
    // Test2
    //  ensure on revealed card is a gold
    //      between the two revealed cards
    //          if it's a copper, silver, or gold
    //              testG.coins += 2
    // (should fail if it's a gold, because it's not included in the current dominion.c code)
    //          else if it's an estate, provice, duchy, gardens, great_hall
    //              assert currentPlayer's testG.deckCount == G.deckCount + 2
    //          else if one of kingdom cards
    //              assert testG.numActions == G.numActions + 2


    ////////// TEST #: 
    //printf("\n////////// TEST : \n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    nextPlayer = currentPlayer + 1;
    
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);

    // do B of above (if/else)
    // Test3
    //  ensure on revealed card is an estate
    //      between the two revealed cards
    //          if it's a copper, silver, or gold
    //              testG.coins += 2
    // (should fail if it's a gold, because it's not included in the current dominion.c code)
    //          else if it's an estate, provice, duchy, gardens, great_hall
    //              assert currentPlayer's testG.deckCount == G.deckCount + 2
    //          else
    //              assert testG.numActions == G.numActions + 2



    ////////// TEST #: 
    //printf("\n////////// TEST : \n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    nextPlayer = currentPlayer + 1;
    
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, bonus);

    // do B of above (if/else)
    // Test4
    //  ensure on revealed card is an adventurer
    //      between the two revealed cards
    //          if it's a copper, silver, or gold
    //              testG.coins += 2
    // (should fail if it's a gold, because it's not included in the current dominion.c code)
    //          else if it's an estate, provice, duchy, gardens, great_hall
    //              assert currentPlayer's testG.deckCount == G.deckCount + 2
    //          else
    //              assert testG.numActions == G.numActions + 2


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
        testCard(numPlayers, G);
    }

    printf("\n////////// SUCCESS: Testing Complete for %s //////////\n\n", TESTCARD);
    // printf("Number of Tests Failed: %d\n\n", testsFailed + 10);
    return 0;
}