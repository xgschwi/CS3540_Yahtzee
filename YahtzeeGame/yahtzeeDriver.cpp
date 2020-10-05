
if (cin = "exit")
    close();

#include "yahtzee.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	unsigned int seed = time(0); // Or use NULL
	srand(seed); // Random numbers are seeded once for the rollDie function (srand(time(0)))

	Dice dice;
	int *values; // Holds array of dice face values
	values = dice.rollDice(); // Dont forget to re-roll

	for (int i = 0; i < 5; i++) cout << values[i]; // Demos the roll dice function

	if (answer = "scoreboards"){ //shows scores
		while (int i = 0; i < 5; i++){
			cout << values[i];
		}
	}
}
