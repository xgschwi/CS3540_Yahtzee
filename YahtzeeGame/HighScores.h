// Written by Xavier Gschwind, Nicholas McBride, and Cameron Taylor

#include "yahtzee.h"
#include <string>
#include <vector>
using namespace std;

class HighScores :public ScoreCard
{
private:
	string scoreboardName[5]; // For leaderboard
	int scoreboardScore[5] = { 0,0,0,0,0 };
	int i;
	int scoreCounter;
public:
	int ScoreBoard(int finalScore);
	HighScores();
	~HighScores();
};
