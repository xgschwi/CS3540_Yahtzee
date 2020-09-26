#include "yahtzee.h"
#include <iostream>
#include <ctime>
using namespace std;


Die::Die() {
	val = 1;
}

int Die::rollDie() {
	return rand() % 6 + 1;
}

Dice::Dice() {
	int values[] = { 1, 1, 1, 1, 1 };

	dice = new Die*[5]; // Dice can hold 5 allocated Die spaces

	for (int i = 0; i < 5; i++) dice[i] = new Die; // Initializes array of Dice with blank die
}

int *Dice::rollDice() {
	for (int i = 0; i < 5; i++) {
		values[i] = dice[i]->rollDie(); // Calls roll die function on each die object in dice and stores the values
	}

	return values;
}