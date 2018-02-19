#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "time.h"
#include "interface.h"

int testMineCard(){

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

	// testing mineCard function
	test = -1; // reset test to -1

    int i;
    int handPos = 0;
    
    // card currently in hand
    state.hand[0][0] = mine;
    state.hand[0][1] = copper;
    state.handCount[0] = 2;

    test = cardEffect(mine, 1, 5, -1, &state, handPos, NULL);

    // assert that mine card works
    if(test != 0){
        printf("\nmineCard failed\n");
            return 1;
    } else {
        printf("\nmineCard passed\n");
    }

    // assert that the current hand count should be 1
    if(state.handCount[0] != 1){
    	printf("\nhandCount '1' failed\n");
            return 1;
    } else {
        printf("\nhandCount '1' passed\n");
    }

    // assert that the cards in hand should be silver
    if(state.hand[0][0] != silver){
        printf("\nsilver in hand failed\n");
            return 1;
    } else {
        printf("\nsilver in hand passed\n");
    }
  
	printf ("\ntestMineCard SUCCESSFULLY COMPLETED.\n");
	

    return 0;
}


int main (){

	printf ("\nSTARTING cardtest3 TEST.\n");

	testMineCard();

	printf ("\nFINISHED cardtest3 TEST.\n\n");

	return 0;
}