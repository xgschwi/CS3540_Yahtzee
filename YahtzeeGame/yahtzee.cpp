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


	dice = new Die * [5]; // Dice can hold 5 allocated Die spaces

	for (int i = 0; i < 5; i++) dice[i] = new Die; // Initializes array of Dice with blank die
}

int* Dice::rollDice() {
	for (int i = 0; i < 5; i++) {
		this->values[i] = dice[i]->rollDie(); // Calls roll die function on each die object in dice and stores the values
	}

	return values;
}

ScoreCard::ScoreCard() {
	score = 0;
	aceb = true;
	twob = true;
	threeb = true;
	fourb = true;
	fiveb = true;
	sixb = true; // All scoring categories are available

	threeKb = true;
	fourKb = true;
	fullHb = true;
	smallb = true;
	largeb = true;
	yahtzeeb = true;
	chanceb = true;
}

ScoreCard::~ScoreCard() {
	delete this;
}

void ScoreCard::chooseScores(int* values) {
	cout << "Here are all of the available scoring categories: \n";
	bool ace, two, three, four, five, six, flag = false;
	bool twoK, threeK, fourK, fullH, small, large, yahtzee, chance = false;

	char type;
	int a, b, c, d, e, f = 0;

	for (int i = 0; i < 5; i++) {
		if (values[i] == 1) {
			if (aceb) ace = true;
			a++;

		}
		if (values[i] == 2) {
			if (twob) two = true;
			b++;
		}
		if (values[i] == 3) {
			if (threeb) three = true;
			c++;
		}

		if (values[i] == 4) {
			if (fourb) four = true;
			d++;
		}
		if (values[i] == 5) {
			if (fiveb) five = true;
			e++;
		}
		if (values[i] == 6) {
			if (sixb) six = true;
			f++;
		}

		// Other if statements for other score types
	}

	if (a == 5) yahtzee, fourK, threeK = true; // Change all to false or initialize false and change everything for values
	else if (a > 3) fourK, threeK = true;
	else if (a > 2) threeK = true;
	else if (a > 1) twoK = true;

	if (b == 5) yahtzee, fourK, threeK = true;
	else if (b > 3) fourK, threeK = true;
	else if (b > 2) threeK = true;
	else if (!twoK && b > 1) twoK = true;

	if (c == 5) yahtzee, fourK, threeK = true;
	else if (c > 3) fourK, threeK = true;
	else if (c > 2) threeK = true;
	else if (!twoK && c > 1) twoK = true;

	if (d == 5) yahtzee, fourK, threeK = true;
	else if (d > 3) fourK, threeK = true;
	else if (d > 2) threeK = true;
	else if (d > 2) threeK = true;
	else if (!twoK && d > 1) twoK = true;

	if (e == 5) yahtzee, fourK, threeK = true;
	else if (e > 3) fourK, threeK = true;
	else if (e > 2) threeK = true;
	else if (!twoK && e > 1) twoK = true;


	if (f == 5) yahtzee, fourK, threeK = true;
	else if (f > 3) fourK, threeK = true;
	else if (f > 2) threeK = true;
	else if (f > 1) twoK = true;
	else if (!twoK && f > 1) twoK = true;

	if (!threeK && !twoK) fullH = true;

	
	if (values[0] = 1 && values[1] == 2 && values[2] == 3 && values[3] == 4 && values[4] == 5) large = true;
	else if (values[1] == 2 && values[2] == 3 && values[3] == 4 && values[4] == 5 && values[5] == 6) large = true;
	else if (values[0] = 1 && values[1] == 2 && values[2] == 3 && values[3] == 4) small = true;
	else if (values[1] == 2 && values[2] == 3 && values[3] == 4 && values[4] == 5) small = true;
	else if (values[2] == 3 && values[3] == 4 && values[4] == 5 && values[5] == 6) small = true;


	if (ace) cout << "Aces: a\n";
	if (two) cout << "Twos: b\n";
	if (three) cout << "Threes: c\n";
	if (four) cout << "Fours: d\n" ;
	if (five) cout << "Fives: e\n";
	if (six) cout << "Sixes: f\n";
	if (threeK) cout << "Three of a Kind: g\n";
	if (fourK) cout << "Four of a Kind: h\n";
	if (fullH) cout << "Full House: i\n";
	if (small) cout << "Small Straight: j\n";
	if (large) cout << "Large Straight: k\n";
	if (yahtzee) cout << "Yahtzee: l\n";
	if (chance) cout << "Chance: m\n";

	cout << endl << "What is your choice? ";
	while (flag) {
		cin >> type;
		if (type == 'a' && ace) { aceb = false; score += aceF(a); flag = false; }
		else if (type == 'b' && two) { twob = false; score += twoF(b); flag = false;}
		else if (type == 'c' && three) { threeb = false; score += threeF(c); flag = false;}
		else if (type == 'd' && four) { fourb = false; score += fourF(d); flag = false;}
		else if (type == 'e' && five) { fiveb = false; score += fiveF(e); flag = false;}
		else if (type == 'f' && six) { sixb = false; score += sixF(f); flag = false;}
		else if (type == 'g' && threeK) { threeKb = false; score += threeKindF(values); flag = false;}
		else if (type == 'h' && fourK) { fourKb = false; score += fourKindF(values); flag = false; }
		else if (type == 'i' && fullH) { fullHb = false; score += fullHouseF(); flag = false;}
		else if (type == 'j' && small) { smallb = false; score += smallF(); flag = false;}
		else if (type == 'k' && large) { largeb = false; score += largeF(); flag = false;}
		else if (type == 'l' && yahtzee) { yahtzeeb = false; score += yahtzeeF(); flag = false;}
		else if (type == 'm' && chance) { chanceb = false; score += chanceF(values); flag = false;}
		else cout << "Invalid input please try again: ";
	}
}

int ScoreCard::aceF(int num) {
	int temp = 0;
	temp += num;
	return temp;
}

int ScoreCard::twoF(int num) {
	int temp = 0;
	temp += (num * 2);
	return temp;
}

int ScoreCard::threeF(int num) {
	int temp = 0;
	temp += (num * 3);
	return temp;
}

int ScoreCard::fourF(int num) {
	int temp = 0;
	temp += (num * 4);
	return temp;
}

int ScoreCard::fiveF(int num) {
	int temp = 0;
	temp += (num * 5);
	return temp;
}

int ScoreCard::sixF(int num) {
	int temp = 0;
	temp += (num * 6);
	return temp;
}

int ScoreCard::threeKindF(int* vals) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += vals[i];
	}
	return sum;
}

int ScoreCard::fourKindF(int* vals) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += vals[i];
	}
	return sum;
}

int ScoreCard::fullHouseF() { return 25; }

int ScoreCard::smallF() { return 30; }

int ScoreCard::largeF() { return 40; }

int ScoreCard::yahtzeeF() { return 50; }

int ScoreCard::chanceF(int* vals) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += vals[i];
	}
	return sum;
}

Game::Play(){
	int *v; //gets the arrays from the scores

	cout << "Welcome to the game! Let's play a friendly, custom game of Yahtzee! Let's start you off with some rolls..."
	v=rollDice(); //returns array into pointer
	chooseScores(v);

	return 0; //since this is the last class, nothing else would need to be returned
}