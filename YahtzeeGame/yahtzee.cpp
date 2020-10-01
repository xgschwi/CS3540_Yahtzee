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

ScoreCard::ScoreCard() {
	score = 0;
	aceb, twob, threeb, fourb, fiveb, sixb = true; // All scoring categories are available

	threeKb, fourKb, fullHb, smallb, largeb, yahtzeeb, chanceb = true;
}

ScoreCard::~ScoreCard() {
	delete this;
}

void ScoreCard::availableScores(int* values) {
	cout << "Here are all of the available scoring categories: \n";
	bool ace, two, three, four, five, six, flag = true;
	bool threeK, fourK, fullH, small, large, yahtzee, chance = true;

	char type;
	int a, b, c, d, e, f = 0;

	for (int i = 0; i < 5; i++) {
		if (values[i] == 1 && aceb) { 
			ace = false;
			a++;

		}
		if (values[i] == 2 && twob) {
			two = false; 
			b++;
	    }
		if (values[i] == 3 && threeb) {
			three = false;
			c++;
		}

		if (values[i] == 4 && fourb) {
			four = false;
			d++;
		}
		if (values[i] == 5 && fiveb) {
			five = false;
			e++;
		}
		if (values[i] == 6 && sixb) {
			six = false;
			f++;
		}

		// Other if statements for other score types
	}

	if (a > 3) {
		fourK = true;
		threeK = true;
	}
	else if (a > 2) threeK = true;
	
	if (b > 3) {
		fourK = true;
		threeK = true;
	}
	else if (b > 2) threeK = true;

	if (c > 3) {
		fourK = true;
		threeK = true;
	}
	else if (c > 2) threeK = true;

	if (d > 3) {
		fourK = true;
		threeK = true;
	}
	else if (d > 2) threeK = true;

	if (e > 3) {
		fourK = true;
		threeK = true;
	}
	else if (e > 2) threeK = true;

	if (f > 3) {
		fourK = true;
		threeK = true;
	}
	else if (f > 2) threeK = true;

	if (!ace) cout << "Aces: a, ";
	if (!two) cout << "Twos: b, ";
	if (!three) cout << "Threes: c ";
	if (!four) cout << "Fours: d" ;
	if (!five) cout << "Fives: e ";
	if (!six) cout << "Sixes: f ";

	cout << endl << "What is your choice? ";
	while (flag) {
		cin >> type;
		if (type == 'a' && !ace) { aceb = false; aceF(a);}
		else if (type == 'b' && !two) { twob = false; twoF(b);}
		else if (type == 'c' && !three) { threeb = false; threeF(c); }
		else if (type == 'd' && !four) { fourb = false; fourF(d); }
		else if (type == 'e' && !five) { fiveb = false; fiveF(e); }
		else if (type == 'f' && !six) { sixb = false; sixF(f); }
		else if (type == 'g' && !threeK) { threeKb = false; threeKindF(values); }
	}
}