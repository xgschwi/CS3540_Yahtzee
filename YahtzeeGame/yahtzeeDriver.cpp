#include "yahtzee.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {

	unsigned int seed = time(0);
	srand(seed); // Random numbers are seeded once for the rollDie function

	Dice dice;
	int *values;
	values = dice.rollDice();

	for (int i = 0; i < 5; i++) cout << values[i]; // Demos the roll dice function

}