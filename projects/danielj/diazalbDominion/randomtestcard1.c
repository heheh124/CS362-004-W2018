/**************************** 
Author: James Daniel
Assignment #4 
Random test for Smithy
****************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#define NUM_TESTS 1000

int main()
{
		int card, players, postEffect, seedVal, i;
		int ctr = 0, fail = 0, initial = 0, pass = 0, player = 0;
		int k[10] = {adventurer, cutpurse, embargo, gardens, mine, minion, sea_hag, smithy, tribute, village};
        struct gameState *game;

        printf("--------------------Begin Random Test Smithy--------------------\n");

        //main loop
        for (i = 0; i < NUM_TESTS; i++)
        {
            //generate random players
            players = rand() % MAX_PLAYERS;
            seedVal = rand();

            game = malloc(sizeof(struct gameState));

            //initialize game
            initializeGame(players, k, seedVal, game);

            //initialize valid state variables
            game->deckCount[player] = rand() % MAX_DECK;
            game->discardCount[player] = rand() % MAX_DECK;
            game->handCount[player] = rand() % MAX_HAND;

            //play the card
            for(card = 0; card < game->handCount[player]; card++)
            {
                if(game->hand[player][card] == gold || game->hand[player][card] == copper || game->hand[player][card] == silver){
                    ctr += 1; }
            }

            //Check the deck
            cardEffect(smithy,1,1,1,game,0,0);
			postEffect = game->handCount[player];

            if(postEffect == initial + 2)
            {
                pass += 1;}
            else
            {
                fail += 1;}
        }

        printf("%d tests out of %d passed.\n", pass, NUM_TESTS);
		printf("--------------------Finished Random Test Smithy--------------------\n");
       
        free(game);

        return 0;
}