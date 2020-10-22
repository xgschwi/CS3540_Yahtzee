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
    Scorecard score1;

    REQUIRE(score1.score == 0);
}

TEST_CASE("Full House gives 25 points", "[score]"){
    Dice dice;
    dice.setvalues(1,1,1,2,2);

    REQUIRE(score >= 25);
}

TEST_CASE("Small Straight gives 30 points", "[score]"){
    Dice dice;
    dice.setvalues(1,2,3,4,3);

    REQUIRE(score >= 30);
}

TEST_CASE("Large Straight gives 40 points", "[score]"){
    Dice dice;
    dice.setvalues(1,2,3,4,5);

    REQUIRE(score >= 40);
}

TEST_CASE("Yahtzee gives 50 points", "[score]"){
    Dice dice;
    dice.setvalues(1,1,1,1,1);

    REQUIRE(score >= 50);
}

TEST_CASE("Three of a kind checks sum", "[score]"){
    Dice dice;
    dice.setvalues(1,1,1,3,4);
    int sum = 0;
    int *a = dice.rollDice();
    for(int i = 0; i < 5; i++) sum += a[i];

    REQUIRE(sum == 10);
}

TEST_CASE("Four of a kind checks sum", "[score]"){
    Dice dice;
    dice.setvalues(1,1,1,1,4);
    int sum = 0;
    int *a = dice.rollDice();
    for(int i = 0; i < 5; i++) sum += a[i];

    REQUIRE(sum == 9);
}

TEST_CASE("Score resets after each game"){
    games = 1;
    Scorecard score1;

    REQUIRE(score1.score == 0);
}