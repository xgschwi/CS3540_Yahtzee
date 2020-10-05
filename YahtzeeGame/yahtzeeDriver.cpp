

#include "yahtzee.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	string answer;
	unsigned int seed = time(0); // Or use NULL
	srand(seed); // Random numbers are seeded once for the rollDie function (srand(time(0)))

	Dice dice;
	int *values; // Holds array of dice face values
	values = dice.rollDice(); // Dont forget to re-roll

	for (int i = 0; i < 5; i++) cout << values[i]; // Demos the roll dice function

	if (cin = "exit") //Exits out of the program
    close();

	if (cin = "restart"){
		cout << "Are you sure you want to restart the game? Input Y to restart; input anything else to continue." << endl;
		cin << answer;
		if (answer = 'Y'){
			std::fill_n(values[], elementCount, 0); //need a way to start at beginning again

		}
		else { //need a way to ask this question again; might want to make this a function
			break;
		}

	}

}
