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

#endif