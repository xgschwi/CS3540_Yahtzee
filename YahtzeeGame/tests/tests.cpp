#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "yahtzee.h"
#include <iostream>
using namespace std;

TEST_CASE("Die can be rolled", "[die]") {
    
    Die die1;
    REQUIRE(die1.rollDie() >= 1);
    REQUIRE(die1.rollDie() <= 6);
}

TEST_CASE("Dice can be rolled", "[dice]") {
    Dice dice;
    int sum = 0;
    int *a = dice.rollDice();
    for(int i = 0; i < 5; i++) sum += a[i];

    REQUIRE(sum > 0);
}

TEST_CASE("Score starts at 0", "[score]"){
    Scorecard score;
    REQUIRE(score.Scorecard == 0);
}

TEST_CASE("Full House gives 25 points"){
    //Check 5 dice and see if 3 is one number and 2 is another
}

TEST_CASE("Small Straight gives 30 points"){
    //Check 3 dice to see if they are the same number
}

TEST_CASE("Large Straight gives 40 points"){
    //Check 4 dice to see if they are the same number
}

TEST_CASE("Yahtzee gives 50 points"){
    //Check 5 dice to see if they are the same number
}

TEST_CASE("Scoreboard puts each player in order"){
    //Test 2 final scores and see if one is above the other on scoreboard
}

TEST_CASE("Score resets after each game"){
    //Make sure that after a game is played that score is reset
}

TEST_CASE("Player can decide whether to continue playing the game or not"){
    //Test that Yes/No works
}