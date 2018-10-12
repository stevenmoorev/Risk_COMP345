#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Dice {
private:
	int diceNumberCount[6] = { 0,0,0,0,0,0 };
	void saveResult(int result);

public:
    int rollDice();
	vector<int> throwDice(int numOfDice);
	void printdiceNumberCount();

};

#endif DICE_H