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
    ScoreCard scoreC;

    REQUIRE(scoreC.score == 0);
}
TEST_CASE("Testing Aces", "[aceF]") {
    int a[5] = {1,1,1,2,3};
    ScoreCard scoreC;
    int counter = 0;

    for (int i = 0; i < 5; i++) {
		if (a[i] == 1) {
			counter++;
		}
    }
    
    REQUIRE(scoreC.aceF(counter) == 3);
}

TEST_CASE("Testing Twos", "[twoF]") {
    int a[5] = {1,1,2,2,3};
    ScoreCard scoreC;
        int counter = 0;

    for (int i = 0; i < 5; i++) {
		if (a[i] == 2) {
			counter++;
		}
    }
    REQUIRE(scoreC.twoF(counter) == 4);
}

TEST_CASE("Testing Threes", "[threeF]") {
    int a[5] = {3,1,3,2,3};
    ScoreCard scoreC;
    int counter = 0;

    for (int i = 0; i < 5; i++) {
		if (a[i] == 3) {
			counter++;
		}
    }
    REQUIRE(scoreC.threeF(counter) == 9);
}

TEST_CASE("Testing Fours", "[fourF]") {
    int a[5] = {1,4,1,4,4};
    ScoreCard scoreC;
        int counter = 0;

    for (int i = 0; i < 5; i++) {
		if (a[i] == 4) {
			counter++;
		}
    }
    REQUIRE(scoreC.fourF(counter) == 12);
}

TEST_CASE("Testing Fives", "[fiveF]") {
    int a[5] = {5,5,1,5,3};
    ScoreCard scoreC;
        int counter = 0;

    for (int i = 0; i < 5; i++) {
		if (a[i] == 5) {
			counter++;
		}
    }
    REQUIRE(scoreC.fiveF(counter) == 15);
}

TEST_CASE("Testing Sixes", "[sixF]") {
    int a[5] = {1,6,1,6,3};
    int counter = 0;

    for (int i = 0; i < 5; i++) {
		if (a[i] == 6) {
			counter++;
		}
    }
    ScoreCard scoreC;
    REQUIRE(scoreC.sixF(counter) == 12);
}

TEST_CASE("Full House gives 25 points", "[fullHouseF]"){
    ScoreCard scoreC;
    REQUIRE(scoreC.fullHouseF() == 25);
}

TEST_CASE("Small Straight gives 30 points", "[smallF]"){
    ScoreCard scoreC;
    REQUIRE(scoreC.smallF() == 30);
}

TEST_CASE("Large Straight gives 40 points", "[largeF]"){
     ScoreCard scoreC;

    REQUIRE(scoreC.largeF() == 40);
}

TEST_CASE("Yahtzee gives 50 points", "[yahtzeeF]"){
     ScoreCard scoreC;
    REQUIRE(scoreC.yahtzeeF() == 50);
}

TEST_CASE("Three of a kind checks sum", "[threeKindF]"){
     ScoreCard scoreC;
    int a[5] = {1,1,1,3,4};
    int sum = 0;
    for(int i = 0; i < 5; i++) sum += a[i];

    REQUIRE(sum == 10);
    REQUIRE(scoreC.threeKindF(a) == 10 );
}

TEST_CASE("Four of a kind checks sum", "[fourKindF]"){
    ScoreCard scoreC;
    int a[5] = {1,1,1,1,4};
    int sum = 0;
    for(int i = 0; i < 5; i++) sum += a[i];

    REQUIRE(sum == 8);
    REQUIRE(scoreC.fourKindF(a) == 8);
}

TEST_CASE("Chance gives a sum of all numbers", "[chanceF]"){
    int a[5] = {1,1,1,1,1};
    int sum = 0;
    for(int i = 0; i < 5; i++) sum += a[i];

    ScoreCard scoreC;
    REQUIRE(sum == 5);
    REQUIRE(scoreC.chanceF(a) == 5);
}