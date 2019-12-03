////////////////////////////////////////////
////////////////////////////////////////////
// bug 9

/******************************************
* Program Name: unittest_9.c
* Assignment Name: Final Project - Part B
* Author: Elizabeth Premer
* Date Due: 24 November 2019
* Description: This is a test suite for Dominion 
*               game play to catch 1 particular bug.
******************************************/


// tribute
// The player to your left reveals then discards
//      the top 2 cards of his deck.
// For each differently named card revealed, if
//      it is:
//  1) Action Card: +2 Actions
//  2) Treasure Card: +2 treasure
//  3) Victory Card: +2 cards

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

   // set variables to initialize game play necessary for the Tribute card effects
    int handPos = 0;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int bonus = 0;
    int seed = 1000;
    int numPlayers = 2;

    // initialize tributeRevealedCards[] array to hold { -1, -1 }
    int tributeRevealedCards[2] = {-1, -1};
    
    // declare game state with testG as the control state
    struct gameState G, testG;

    // set kingdom cards to include 10 card supplies, including the Tribute card
    int cardSupplies[10] = {  adventurer, embargo, village, minion, mine,
                            cutpurse, sea_hag, tribute, smithy, council_room };

    // initialize a game state and player cards
    initializeGame(numPlayers, cardSupplies, seed, &G);

    printf("\n////////// Testing for Bug 9:\nSame-type revealed cards are not properly caught in Tribute card effect function. //////////\n\n");

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    int currentPlayer = testG.whoseTurn;
    int nextPlayer = currentPlayer + 1;

    // hard-code nextPlayer's deck to reveal two Action cards
    tributeRevealedCards[0] = mine; // action card
    tributeRevealedCards[1] = adventurer; // action card

    // ensure the next player's cards are assigned as above
    printf("Test 1: Revealed cards are Mine and Adventurer, both Action cards.\n\n");

    printf("BEFORE CARD EFFECT:\n");
    printf("\tNum actions: %d\n", testG.numActions);

    // call the Tribute card to invoke its effects
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, &bonus);

    printf("\nAFTER CARD EFFECTS\n");
    // check the revealed cards' types


        if (tributeRevealedCards[0] == copper || tributeRevealedCards[0] == silver || tributeRevealedCards[0] == gold) { //Treasure cards
            printf("First card is Treasure.\n");
            testG.coins = testG.coins+2;

            if (tributeRevealedCards[1] == copper || tributeRevealedCards[1] == silver || tributeRevealedCards[1] == gold) { //Treasure cards
                printf("Second revealed card is also Treasure. Should NOT receive +2 coins again.\n");

                if (testG.coins > G.coins +2)
                {
                    printf("coins: %d\n", testG.coins);
                    printf("Test Bug_9: FAILED: +2 coins given twice.\n");
                }
            }
        }

        else if (tributeRevealedCards[0] == estate || tributeRevealedCards[0] == duchy || tributeRevealedCards[0] == province || tributeRevealedCards[0] == gardens || tributeRevealedCards[0] == great_hall) { //Victory Card Found
            printf("First card is Victory Card.\n");
            drawCard(currentPlayer, &testG);
            drawCard(currentPlayer, &testG);

            if (tributeRevealedCards[1] == estate || tributeRevealedCards[1] == duchy || tributeRevealedCards[1] == province || tributeRevealedCards[1] == gardens || tributeRevealedCards[1] == great_hall) { //Victory Card 
                printf("Second revealed card is also Victory. Should NOT receive +2 cards again.\n");

                printf("hand count: %d\n", testG.handCount[currentPlayer]);
                printf("Test Bug_9: FAILED: +2 cards given twice.\n");
            }
        }

        else if (tributeRevealedCards[0] == adventurer 
            || tributeRevealedCards[0] == council_room 
            || tributeRevealedCards[0] == feast 
            || tributeRevealedCards[0] == mine 
            || tributeRevealedCards[0] == smithy 
            || tributeRevealedCards[0] == village 
            || tributeRevealedCards[0] == baron 
            || tributeRevealedCards[0] == great_hall 
            || tributeRevealedCards[0] == minion 
            || tributeRevealedCards[0] == steward 
            || tributeRevealedCards[0] == tribute 
            || tributeRevealedCards[0] == ambassador 
            || tributeRevealedCards[0] == cutpurse 
            || tributeRevealedCards[0] == outpost 
            || tributeRevealedCards[0] == embargo 
            || tributeRevealedCards[0] == salvager 
            || tributeRevealedCards[0] == sea_hag 
            || tributeRevealedCards[0] == treasure_map) 
        { //Action Card
            
            printf("First card is Action Card.\n");
            testG.numActions = testG.numActions + 2;

            if (tributeRevealedCards[1] == adventurer 
            || tributeRevealedCards[1] == council_room 
            || tributeRevealedCards[1] == feast 
            || tributeRevealedCards[1] == mine 
            || tributeRevealedCards[1] == smithy 
            || tributeRevealedCards[1] == village 
            || tributeRevealedCards[1] == baron 
            || tributeRevealedCards[1] == great_hall 
            || tributeRevealedCards[1] == minion 
            || tributeRevealedCards[1] == steward 
            || tributeRevealedCards[1] == tribute 
            || tributeRevealedCards[1] == ambassador 
            || tributeRevealedCards[1] == cutpurse 
            || tributeRevealedCards[1] == outpost 
            || tributeRevealedCards[1] == embargo 
            || tributeRevealedCards[1] == salvager 
            || tributeRevealedCards[1] == sea_hag 
            || tributeRevealedCards[1] == treasure_map) 
            { //Action Card
                printf("Second revealed card is also Action. Should NOT receive +2 actions again.\n");

                printf("num actions: %d\n", testG.numActions);
                printf("Test Bug_9: FAILED: +2 actions given twice.\n");
            }
        }

        else // not Action, Treasure, or Victory
        {
            printf("Not an Action, Treasure, or Victory card.\n");
        }
    

    // copy game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    currentPlayer = testG.whoseTurn;
    nextPlayer = currentPlayer + 1;

    // hard-code nextPlayer's deck to reveal two Treasure cards
    tributeRevealedCards[0] = gold; // treasure card
    tributeRevealedCards[1] = copper; // treasure card

    // ensure the next player's cards are assigned as above
    printf("\nTEST 2: Revealed cards are Gold and Copper, both Treasure cards.\n\n");

    printf("BEFORE CARD EFFECT: \n\tCoins: %d\n", testG.coins);

    // call the Tribute card to invoke its effects
    cardEffect(tribute, choice1, choice2, choice3, &testG, handPos, &bonus);

    printf("\nAFTER CARD EFFECTS\n");
    // check the revealed cards' types

        if (tributeRevealedCards[0] == copper || tributeRevealedCards[0] == silver || tributeRevealedCards[0] == gold) { //Treasure cards
            printf("First card is Treasure.\n");
            testG.coins = testG.coins+2;

            if (tributeRevealedCards[1] == copper || tributeRevealedCards[1] == silver || tributeRevealedCards[1] == gold) { //Treasure cards
                printf("Second revealed card is also Treasure. Should NOT receive +2 coins again.\n");

                if (testG.coins > G.coins +2)
                {
                    printf("coins: %d\n", testG.coins);
                    printf("Test Bug_9: FAILED: +2 coins given twice.\n");
                }
            }
        }

        else if (tributeRevealedCards[0] == estate || tributeRevealedCards[0] == duchy || tributeRevealedCards[0] == province || tributeRevealedCards[0] == gardens || tributeRevealedCards[0] == great_hall) { //Victory Card Found
            printf("First card is Victory Card.\n");
            drawCard(currentPlayer, &testG);
            drawCard(currentPlayer, &testG);

            if (tributeRevealedCards[1] == estate || tributeRevealedCards[1] == duchy || tributeRevealedCards[1] == province || tributeRevealedCards[1] == gardens || tributeRevealedCards[1] == great_hall) { //Victory Card 
                printf("Second revealed card is also Victory. Should NOT receive +2 cards again.\n");

                printf("hand count: %d\n", testG.handCount[currentPlayer]);
                printf("Test Bug_9: FAILED: +2 cards given twice.\n");
            }
        }

        else if (tributeRevealedCards[0] == adventurer 
            || tributeRevealedCards[0] == council_room 
            || tributeRevealedCards[0] == feast 
            || tributeRevealedCards[0] == mine 
            || tributeRevealedCards[0] == smithy 
            || tributeRevealedCards[0] == village 
            || tributeRevealedCards[0] == baron 
            || tributeRevealedCards[0] == great_hall 
            || tributeRevealedCards[0] == minion 
            || tributeRevealedCards[0] == steward 
            || tributeRevealedCards[0] == tribute 
            || tributeRevealedCards[0] == ambassador 
            || tributeRevealedCards[0] == cutpurse 
            || tributeRevealedCards[0] == outpost 
            || tributeRevealedCards[0] == embargo 
            || tributeRevealedCards[0] == salvager 
            || tributeRevealedCards[0] == sea_hag 
            || tributeRevealedCards[0] == treasure_map) 
        { //Action Card
            
            printf("First card is Action Card.\n");
            testG.numActions = testG.numActions + 2;

            if (tributeRevealedCards[1] == adventurer 
            || tributeRevealedCards[1] == council_room 
            || tributeRevealedCards[1] == feast 
            || tributeRevealedCards[1] == mine 
            || tributeRevealedCards[1] == smithy 
            || tributeRevealedCards[1] == village 
            || tributeRevealedCards[1] == baron 
            || tributeRevealedCards[1] == great_hall 
            || tributeRevealedCards[1] == minion 
            || tributeRevealedCards[1] == steward 
            || tributeRevealedCards[1] == tribute 
            || tributeRevealedCards[1] == ambassador 
            || tributeRevealedCards[1] == cutpurse 
            || tributeRevealedCards[1] == outpost 
            || tributeRevealedCards[1] == embargo 
            || tributeRevealedCards[1] == salvager 
            || tributeRevealedCards[1] == sea_hag 
            || tributeRevealedCards[1] == treasure_map) 
            { //Action Card
                printf("Second revealed card is also Action. Should NOT receive +2 actions again.\n");

                printf("num actions: %d\n", testG.numActions);
                printf("Test Bug_9: FAILED: +2 actions given twice.\n");
            }
        }

        else // not Action, Treasure, or Victory
        {
            printf("Not an Action, Treasure, or Victory card.\n");
        }


    printf("\n////////// SUCCESS: Testing Complete for Bug 9. //////////\n\n");

    return 0;
}
