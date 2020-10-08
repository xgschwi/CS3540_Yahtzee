// Written by Xavier Gschwind, Nicholas McBride, and Cameron Taylor

#include "yahtzee.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
using namespace std;

int finalScore = 0;

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

Dice::~Dice() {
	for (int i = 0; i < 5; i++) delete dice[i]; // Delete dynamic allocation
	delete dice;
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
}

void ScoreCard::chooseScores(int* values) {
	bool ace = false, two = false, three = false, four = false, five = false, six = false, flag = true;
	bool twoK = false, threeK = false, fourK = false, fullH = false, small = false, large = false, yahtzee = false, chance = false;

	string type;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	int numOfOptions = 0;			//Allow a counter to be set in place if none of the options are avaliable

	cout << "Your Roll Was: ";

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
	}

	for (int j = 0; j < 5; j++)
	{
		sort(values, values + 5);
		cout << values[j] << " ";
	}


	cout << endl;
	if ((a >= 3 || b >= 3 || c >= 3 || d >= 3 || e >= 3|| f >= 3) && threeKb)		//three of a kind
	{
		threeK = true;
	}
	if ((a >= 4 || b >= 4 || c >= 4 || d >= 4 || e >= 4 || f >= 4) && fourKb)		//four of a kind
	{
		fourK = true;
	}
	if (((a == 3 || b == 3 || c == 3 || d == 3 || e == 3 || f== 3) && (a == 2 || b == 2 || c == 2 || d == 2 || e == 2 || f == 2)) && fullHb)		//Full house
	{
		fullH = true;
	}
	if ((((a && b && c && d) > 0) || ((b && c && d && e) > 0) || ((c && d && e && f) > 0)) && smallb)		//Small Straight
	{
		small = true;
	}
	if (((a && b && c && d && e) || (b && c && d && e && f)) && largeb)		//Large Straight
	{
		large = true;
	}
	if ((a == 5 || b == 5 || c == 5 || d == 5 || e == 5 || f == 5) && yahtzeeb)		//Yahtzee
	{
		yahtzee = true;
	}
	if (chanceb)		//Chance
	{
		chance = true;
	}
	cout << "Here are all of the available scoring categories: \n";
	if (ace)		{ numOfOptions++; cout << "1.  Aces: \n"; }
	if (two)		{ numOfOptions++; cout << "2.  Twos: \n"; }
	if (three)		{ numOfOptions++; cout << "3.  Threes: \n"; }
	if (four)		{ numOfOptions++; cout << "4.  Fours: \n"; }
	if (five)		{ numOfOptions++; cout << "5.  Fives: \n"; }
	if (six)		{ numOfOptions++; cout << "6.  Sixes: \n"; }
	if (threeK)		{ numOfOptions++; cout << "7.  Three of a Kind: \n"; }
	if (fourK)		{ numOfOptions++; cout << "8.  Four of a Kind: \n"; }
	if (fullH)		{ numOfOptions++; cout << "9.  Full House: \n"; }
	if (small)		{ numOfOptions++; cout << "10. Small Straight: \n"; }
	if (large)		{ numOfOptions++; cout << "11. Large Straight: \n"; }
	if (yahtzee)	{ numOfOptions++; cout << "12. Yahtzee: \n"; }
	if (chance)		{ numOfOptions++; cout << "13. Chance: \n"; }

	while (flag) {
		if (numOfOptions == 0)
		{
			int skip;
			cout << "Looks like you're out of options! Please press 0 to go to the next round. \n\n";
			flag = false;
			cin >> skip;
		}
		else {
			cout << endl << "What is your choice? ";
			cin >> type;
			if (type == "1" && ace) { aceb = false; ace = false;  score += aceF(a); flag = false; }
			else if (type == "2" && two) { twob = false; two = false; score += twoF(b); flag = false; }
			else if (type == "3" && three) { threeb = false; three = false; score += threeF(c); flag = false; }
			else if (type == "4" && four) { fourb = false; four = false; score += fourF(d); flag = false; }
			else if (type == "5" && five) { fiveb = false; five = false; score += fiveF(e); flag = false; }
			else if (type == "6" && six) { sixb = false; six = false; score += sixF(f); flag = false; }
			else if (type == "7" && threeK) { threeKb = false; threeK = false; score += threeKindF(values); flag = false; }
			else if (type == "8" && fourK) { fourKb = false; fourK = false; score += fourKindF(values); flag = false; }
			else if (type == "9" && fullH) { fullHb = false; fullH = false; score += fullHouseF(); flag = false; }
			else if (type == "10" && small) { smallb = false; small = false; score += smallF(); flag = false; }
			else if (type == "11" && large) { largeb = false; large = false; score += largeF(); flag = false; }
			else if (type == "12" && yahtzee) { yahtzeeb = false; yahtzee = false; score += yahtzeeF(); flag = false; }
			else if (type == "13" && chance) { chanceb = false; chance = false; chanceb = false;  score += chanceF(values); flag = false; }

			else cout << "Invalid input please try again. ";
		}
	}
	cout << "Your current Score is: " << score << endl;
	finalScore = score;
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

int Game::play() {
	int* v;		//gets the arrays from the scores
	int turns = 0;
	ScoreCard scoreCard;
	cout << "\nWelcome to the game! Let's play a friendly, custom game of Yahtzee! Let's start you off with some rolls...";
	while (turns != 13)
	{
		cout << "\n\nRound: " << turns + 1 << "/13" << endl;
		v = rollDice();							//returns array into pointer
		scoreCard.chooseScores(v);
		turns++;
	}
	return 0;				//since this is the last class, nothing else would need to be returned
}

int Game::getFinalScore()		//no params, returns the final score
{
	cout << finalScore << endl;
	return finalScore;
}
