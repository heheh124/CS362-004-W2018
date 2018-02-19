/**************************** 
Author: James Daniel
Assignment #4 
Random test for Adventurer
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
#define NUM_CARDS treasure_map

int main()
{
	int deck_treasures, hand_count, player, numPlayers, pre_count, post_count, seed, i, j;
	int k[10] = {baron,curse, copper, duchy, estate, province, smithy, treasure_map, minion, steward};
	
	srand(time(NULL));   
	struct gameState game;
	
	printf("--------------------Begin Random Test Adventurer--------------------\n");	
	
	//main loop
	for(i = 0;i < NUM_TESTS; i++)
	{ 
		pre_count = 0; 
		post_count = 0;
		//generate random players
		numPlayers = rand() % 3 + 2;
		seed = rand() % 100;	
		//initialize game
		if(initializeGame(numPlayers, k, seed, &game) == -1)
		{ 
			printf("Error: Cannot initialize game\n");
			exit(0);
		}
		//generate a random player 
		player = rand() % numPlayers; 
		game.whoseTurn = player;
		game.numActions = 1;
		game.handCount[player] = 5;
		game.deckCount[player] = rand() % MAX_HAND;
		game.discardCount[player] = 0;
		
		//generate a deck by random
		for(j = 0; j < game.deckCount[player]; j++)
		{
			game.deck[player][j] = rand() % NUM_CARDS;
			if(game.deck[player][j] >= copper && game.deck[player][j] <= gold)
			{ 
				deck_treasures++;
			}
		}
		//generate a hand by random
		for(j = 0; j < game.handCount[player]; j++)
		{	
			game.hand[player][j] = rand() % NUM_CARDS;
			if(game.hand[player][j] >= copper && game.hand[player][j] <= gold)
			{ 
				pre_count++;	
			}
		}
		//play adventurer card
		game.hand[player][0] = adventurer; 
		hand_count = game.handCount[player];
		playCard(0, 0, 0, 0, &game);
		
		//2 cards should have been placed in users hand
		if(hand_count + 2 != game.handCount[player])
		{
			printf("Test fail: Unable to put 2 cards into players hand\n");
			printf("--------------------Exiting Random Test Adventurer--------------------\n");
			exit(0);	
		}
		
		for(j = 0; j < game.handCount[player]; j++)
		{
			if(game.hand[player][j] >= copper && game.hand[player][j] <= gold)
					post_count++;
		}
		printf("Before: %d\n", pre_count);
		printf("After: %d\n", post_count);
		
		if(pre_count + 2 != post_count)
		{
			printf("Test fail: Unable to put put 2 cards into players hand\n");
			printf("--------------------Exiting Random Test Adventurer--------------------\n");
			exit(0);	
		}
		printf("Tests #%d: \n", i);
		
	}
	printf("--------------------Finished Random Test Adventurer--------------------\n");	
	return 0;
}