README
Included are:
debug
.cpp
.h
driver file

The user enters into the driver, where after setting up some time and a blank scoreboard, the user is asked if they want to play or read the instructions. This is a while loop; it only gets out once they decide to play, as after reading the instructions or typing in the wrong number will bring them back to the question again.

Once they choose to play the game, the game class will exucute; within this class are functions that exucute in order to simulate the game, including the scorecard class. Within the chooseScore function, after reading out the score that the dice roller function has picked out, the program will display a list of avalable scores to choose from, with some left out if already choosen from. Once the user has chosen out a score, this program repeats, until 13 rounds are done, and the game ends. 

***HOW TO PLAY***
First, the game will ask you if you wish to play: pressing 1 will start the game, while pressing 2 will read out the laconic intructions.
The dice will be rolled randomly once you begin, then once they finish rolling you'll be shown the score. From there you'll be able to see what score you can keep; once you have done that the game will move on to the next score, and so on until the game is done.

***HOW TO MODIFY***
Most of the most important functions are located within the chooseScore class; thus, if you would want to modify the game to perhaps look for more scores, change what some scores mean, or whatever else you wish to do, that's the place to go first. After that, you'll want to check out the game class, since that's what calls it, and then the driver, since that's where the user interacts with the whole thing. Most of the class definitions are placed in yahtzee.h and yahtzee.cpp for the sake of promoting merge conflicts which were necessary for this project. Under normal circumstances, each class would typically be worked on in parallel through one header and cpp file per class. Evidence of merge conflict below:


[Link to merge conflict evidence](https://falconbgsu-my.sharepoint.com/:i:/g/personal/xgschwi_bgsu_edu/Ef5NJqH8vPBAtjjCLZEVxFcBTnP-qbI3Hw0zlKiycduG0w?e=p3pdcu)

