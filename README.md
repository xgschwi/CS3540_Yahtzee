README
Included are:
debug
.cpp
.h
driver file

The user enters into the driver, where after setting up some time and a blank scoreboard, the user is asked if they want to play or read the instructions. This is a while loop; it only gets out once they decide to play, as after reading the instructions or typing in the wrong number will bring them back to the question again.

Once they choose to play the game, the game class will execute; within this class are functions that execute in order to simulate the game, including the scorecard class. Within the chooseScore function, after reading out the score that the dice roller function has picked out, the program will display a list of available scores to choose from, with some left out if already chosen from. Once the user has chosen out a score, this program repeats, until 13 rounds are done, and the game ends. 

***HOW TO PLAY***
First, the game will ask you if you wish to play: pressing 1 will start the game while pressing 2 will read out the laconic instructions.
The dice will be rolled randomly once you begin, then once they finish rolling you'll be shown the score. From there you'll be able to see what score you can keep; once you have done that the game will move on to the next score, and so on until the game is done.

***HOW TO MODIFY***
Most of the most important functions are located within the chooseScore class; thus, if you would want to modify the game to perhaps look for more scores, change what some scores mean, or whatever else you wish to do, that's the place to go first. After that, you'll want to check out the game class, since that's what calls it, and then the driver since that's where the user interacts with the whole thing. Most of the class definitions are placed in yahtzee.h and yahtzee.cpp for the sake of promoting merge conflicts that were necessary for this project. Under normal circumstances, each class would typically be worked on in parallel through one header and cpp file per class. Evidence of merge conflict below:


***[Link to merge conflict evidence](https://falconbgsu-my.sharepoint.com/:i:/g/personal/xgschwi_bgsu_edu/Ef5NJqH8vPBAtjjCLZEVxFcBTnP-qbI3Hw0zlKiycduG0w?e=p3pdcu)***

***Notable Classes and Functions:***
yahtzee.h and .cpp contains the classes for the die, dice, scorecard, and game.

The Die class has the private variable `int val`, and public contstructor `Die()` to initialize the value of the die and the function `int rollDie()` which returns a randomly generated integer between 1 and 6.

The Dice class has the private integer array `int values[5]` which was initialized immediately with five 1s. There was also a private Die pointer to a pointer `Die **dice`. The public constructor `Dice()` allocated space for dice to hold 5 Die objects. The destructor `~Dice()` deallocates the die objects that are made so as to prevent memory leaks. The `int rollDice()` function called for every die object's `rollDie()` function in the `dice` and return an integer array of those values.

The Scorecard class had a multitude of boolean variables to track whenever a scoring category was permanently unavailable. The `int score` variable was made to store the score of the scorecard object. The constructor `ScoreCard()` initialized all boolean variables and the score. The function `void chooseScores(int* vals)` takes the array of values the `rollDice()` function yielded and then used the boolean variables and more booleans to determine what scoring categories were available. The user could choose a scoring category, and a particular scoring function then returns the new addition to the score.

The Game class has a private scorecard object, the `int play()` function to track the turns in the game and call functions to roll the dice and choose scores until 13 turns have been reached. 

In HighScores.h and .cpp:

The HighScore class was implemented to track the top scores in arrays with the names and scores and store them in a leaderboard to be displayed after the conclusion of each game.

****Building****
To start building the project using Make, the user must navigate to the project folder YahtzeeGame to use the make commands. Located inside this folder is the "Makefile" file that gives the user access to different steps of the building and running process of the Yahtzee Game. To begin to browse all the commands, the user may use a terminal window to type the commands `make` or `make help`. Both options work because help is the first make command given, and help is the exact name of the command. This command displays the `make help`, `make init`, `make all`, `make run`, `make clear`, `make do_all`, `make tests_all` commands. 

With the "init" command, we create a bin directory in which the executable of the code will be placed in. 

The "all" command uses the "init" command and complies all the cpp files into the bin directory and labels the executable "main.exe". The "init" command is used here to ensure the executable can be placed in the specified directory.

The "run" command runs the completed, compiled program "main.exe" so the user can play the Yahtzee Game. 

Running the "clear" command removes the bin directory and the main.exe file within it.

The "do_all" command does all of the above, except for the help command. The do_all command will use the "all" command to invoke the "init" command and compile the executable into the bin. Then, the "run" command is called to run the executable "main.exe". Once the user is finished with the game, the "clear" command is called to remove the bin directory and the executable file. The purpose of "do_all" is to do all the work for the user so that the user can build and run the game in one command. This is also so an executable won't be left behind that the user would have to clean up. This removes the amount of work needed if the executable and bin directory were left behind as detectable changes for version control, like git, to detect and want commits for.

The "tests_all" command will compile the tests.cpp file, which uses Catch2, to run test cases on the software. The build of the testing executable will then run and show what test cases have passed and failed with the Yahtzee Game. Then, the test build will be removed.

[Sample Building Transcript](https://falconbgsu-my.sharepoint.com/:t:/g/personal/xgschwi_bgsu_edu/EcijVrgG17pPmIIJv0lvNucBJcocFtSQQ_LBa691TZNfIw?e=Ekxd1i)

***Testing***
To test the software, Catch2 was integrated into this project. Implementing Catch2 was not too difficult because the given hpp file for Catch2 was readily available on github, and the hpp file was added into the test folder in the repository. With the hpp file in the repository, our team was able to include the hpp file, make a definition statement to use the Catch2 code, and make test cases. To make test cases, the keyword TEST_CASE can be used to define the message for the test, and, inside this, the keyword REQUIRE can be used to test a conditional statement. This conditional statement will determine what test cases pass and fail. The test cases were run on scoring functions and dice rolling functions.

***Statement of Contributions***

- **Xavier Gschwind:** Added Catch2 hpp file into repository
- **Xavier Gschwind:** Added test cases to tests.cpp
- **Xavier Gschwind:** Edited the yml file for CI/CD to use make file commands
- **Nicholas McBride:** Added test cases
- **Cameron Taylor:** Added yml file and added test and build stages for CI/CD