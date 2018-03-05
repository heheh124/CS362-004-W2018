/**************************** 
Author: James Daniel
Assignment #4 
Random test for Village
****************************/

#include <string.h>
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
	int players, player, postEffect, seed, i, r, errors = 0, initial = 0, pass = 0, fail = 0;
	int k[10] = {adventurer, cutpurse, embargo, gardens, mine, minion, sea_hag, smithy, tribute, village}; 
	struct gameState game;
	struct gameState temp; 

	printf("--------------------Begin Random Test Village--------------------\n");
	
	srand(time(NULL));
	
	//main loop
	for (i = 0; i < NUM_TESTS; i++) 
	{
		//generate random players
		do {
			players = rand() % 4;
		} while (players < 2);

		//random seed
		seed = rand();
		//initialize game
		initializeGame(players, k, seed, &game);	

		do {
			player = rand() % players; 
		} while (player == 0);	

		//initiate valid state variables
		game.whoseTurn = player;
		//generate random deck size
		game.deckCount[player] = rand() % MAX_DECK;
		game.discardCount[player] = rand() % MAX_DECK;
		game.handCount[player] = rand() % MAX_HAND;
		game.hand[player][0] = village;
		game.numActions = rand() % 10;		
		memcpy(&temp, &game, sizeof(struct gameState));
		
		//play village card
		r = cardEffect(village, 0, 0, 0, &game, 0, 0);
		assert (r == 0);
		postEffect = game.handCount[player];
		
		if(postEffect == initial + 1)
		{
			pass += 1;}
		else
		{
			fail += 1;}
		/*
		//count errors
		if(game.deckCount[player] != (temp.deckCount[player] - 1)) 
		{ 
			errors++; 
		}
		//2 more actions for village
		if(game.numActions != (temp.numActions + 2)) 
		{ 
			errors++; 
		}*/

	}	
	//printf("Errors: %d\n", errors);
	printf("%d tests out of %d passed.\n", pass, NUM_TESTS);
	printf("--------------------Finished Random Test Village--------------------\n");
	return 0;
}