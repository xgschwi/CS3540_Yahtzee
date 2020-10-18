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