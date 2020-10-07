#include "yahtzee.h"
#include <iostream>
#include <ctime>

using namespace std;

void start() {
	int answer = 0;
	cout << "Press 1 to play the game, or press 2 to learn how this works: ";
	cin >> answer;
	if (answer == 1) {
		Game game;
		game.play();
	}
	else if (answer == 2) {
		cout << "\nThis is like a game of Yahtzee , but with a twist: \nYou don't keep individal dice to keep as you reroll, but you instead keep scores instead! \nThis goes on until all the scoring catagories are full. \n\nNow, we'll ask again: \n";
		start();
	}
	else {
		cout << "Sorry, that's not a valid number: please try again." << endl;
		start();
	}

}
		
int main() {
	unsigned int seed = time(0); // Or use NULL
	srand(seed); // Random numbers are seeded once for the rollDie function (srand(time(0)))
	start();
	Dice dice;
	int* values; // Holds array of dice face values
	values = dice.rollDice(); // Dont forget to re-roll

	for (int i = 0; i < 5; i++) cout << values[i]; // Demos the roll dice function
}
