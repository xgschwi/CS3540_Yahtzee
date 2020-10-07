#include "HighScores.h"
#include "string"
#include <iostream>
using namespace std;

int HighScores::ScoreBoard(int finalScore)
{
	string name;
	cout << "Please enter a 4 character name to be added to the scoreboard: ";
	cin >> name;
	cout << "LEADERBOARD\n";
		if (name.size() != 4)
		{
			cout << "\nInvalid name size.\n";
			HighScores::ScoreBoard(finalScore);
		}
		else
		{
			do
			{
				scoreboardName[i] = name;
				scoreboardScore[i] = finalScore;
				if (i > 0)
				{
					for (int j = 0; j < i; j++)
					{
						if (scoreboardScore[j] < scoreboardScore[i])
						{
							swap(scoreboardScore[i], scoreboardScore[j]);
							swap(scoreboardName[i], scoreboardName[j]);
							//i--;
						}
					}
				}
				cout << endl;
				i++;
				if (scoreboardScore[i] == 0)
					break;
			} while (i < 5);
			for (int k = 0; k < 5; k++)
			{
				cout << k + 1 << " ";
				cout << scoreboardName[k] << " ";
				cout << scoreboardScore[k] << endl;
			}
			cout << "\n\n\n";
		}
	scoreCounter++;
	return 0;
}

HighScores::HighScores()
{
	i = 0;
	scoreCounter = 0;
	//scoreboardName[5] = { "N/A", "N/A", "N/A", "N/A", "N/A" };
	for (int counter = 0; counter < 5; counter++)
	{
		scoreboardName[counter] = "N/A";
	}
}

HighScores::~HighScores()
{
}

