#include "yahtzee.h"
#include <stdlib.h>
#include <time.h>

Die::Die() {
	val = 0;
}

int Die::rollDie() {
	unsigned int seed = 0;
	srand(seed);

	return rand() % 6 + 1;
}