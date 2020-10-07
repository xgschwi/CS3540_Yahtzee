#include "yahtzee.h"
#include <string>
#include <vector>
using namespace std;

class HighScores :public ScoreCard
{
private:
	string scoreboardName[5];
	int scoreboardScore[5] = { 0,0,0,0,0 };
	int i;
	int scoreCounter;
public:
	int ScoreBoard(int finalScore);
	HighScores();
	~HighScores();
};
