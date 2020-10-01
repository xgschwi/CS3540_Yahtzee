#ifndef YAHTZEE
#define YAHTZEE

class Die {

private:
	int val; // Face value of die
public:
	Die();
	int rollDie();
};

class Dice{
private:
	int values[5]; // Holds the face values of all the die
	Die **dice; // pointer to die objects
public:
	Dice();
	int *rollDice();
};

class ScoreCard {
private:
	int score;

	bool aceb;
	bool twob;
	bool threeb;
	bool fourb;
	bool fiveb;
	bool sixb;

	bool threeKb;
	bool fourKb;
	bool fullHb;
	bool smallb;
	bool largeb;
	bool yahtzeeb;
	bool chanceb;
public:
	ScoreCard();
	~ScoreCard();

	void availableScores(int* vals);
	void chooseScoreType(char command, int* vals);

	int aceF(int num);
	int twoF(int num);
	int threeF(int num);
	int fourF(int num);
	int fiveF(int num);
	int sixF(int num);

	int threeKindF(int* vals);
	int fourKindF(int* vals);
	int fullHouseF();
	int smallF();
	int largeF();
	int yahtzeeF();
	int chanceF(int* vals);

};
#endif