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

	start();


	/*if (answer = "scoreboards"){ //shows scores
		while (int i = 0; i < 5; i++){
			cout << values[i];
		}
	}

	if else (cin = "exit") //Exits out of the program
    close();

	if else (cin = "restart"){
		cout << "Are you sure you want to restart the game? Input Y to restart; input anything else to continue." << endl;
		cin << answer;
		if (answer = 'Y'){
			std::fill_n(values[], elementCount, 0); //need a way to start at beginning again

		}
		else { //need a way to ask this question again; might want to make this a function
			break;
		}

	}*/


}

void start(){
	int answer = 0;
	cout << "Press 1 to play the game, or press 2 to learn how this works."
	cin >> answer;
	if (answer = 1){
	play();}
	else if (answer = 2){
		cout << "This is like a game of Yahtzee , but with a twist: you don't keep individal dice to keep as you reroll, but you instead keep scores instead! This goes on until all the scoring catagories are full. Now, we'll ask again:" << endl;
		start();
	}
	else {
		cout << "Sorry, that's not a valid number: please try again." << endl;
		start();
	}

}
