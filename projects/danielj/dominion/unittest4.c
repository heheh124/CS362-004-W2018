#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "time.h"
#include "interface.h"

int testGetCost(){

	struct gameState state;
	int players = 2;
	int test = -1;
	int seed = 0;
	
	seed = rand();

	int k[10] = {adventurer, council_room, feast, gardens, mine,
	            remodel, smithy, village, baron, great_hall};

	// check to see if game runs
	test = initializeGame(players, k, seed, &state);

	assert (test == 0);

	// testing getCost function
	test = -1; 


	test = getCost(estate);

	// test passes if estate cost is 2
	if (test != 2){
		printf("\ngetCost '2' failed\n");
			return 1;
	} else {
		printf("\ngetCost '2' passed\n");
	}

	test = getCost(council_room);


	// test passes if council_room cost is 5
	if(test != 5){
		printf("\ngetCost '5' failed\n");
			return 1;
	} else {
		printf("\ngetCost '5' passed\n");
	}

	printf ("\ntestGetCost SUCCESSFULLY COMPLETED.\n");

    return 0;
}


int main (){

	printf ("\nSTARTING unittest4 TEST.\n");

	testGetCost();

	printf ("\nFINISHED unittest4 TEST.\n\n");

	return 0;
}