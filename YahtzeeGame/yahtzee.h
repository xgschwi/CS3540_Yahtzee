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
	
public:
	ScoreCard();
	~ScoreCard();

	void availableScores(int* arr);
	void chooseScoreType(char command);

	int ace(int num);
	int two(int num);
	int three(int num);
	int four(int num);
	int five(int num);
	int six(int num);

	int threeKind(int* vals);
	int fourKind(int* vals);
	int fullHouse();
	int small();
	int large();
	int yahtzee();
	int chance(int* vals);

};
#endif