#include <iostream>
#include <string> 
#include "Dice.h"
using namespace std;


int Dice::rollDice() {
	return rand() % 6 + 1;
}

vector<int> Dice::throwDice(int numOfDice) {
	vector<int> results;

	if (numOfDice < 1 || numOfDice > 3) {
		cout << "Invalid number of dice" << endl;
		return results;
	}

	while (numOfDice > 0) {
		Dice dice;
		int result = rollDice();
		this->saveResult(result);
		results.push_back(result);
		numOfDice--;
	}

	return results;
}

void Dice::saveResult(int result) {
	diceNumberCount[result - 1]++;
}

void Dice::printdiceNumberCount() {
	double sum = 0;

	for (int count : diceNumberCount)
		sum += count;

	for (int index = 0; index < 6; index++) {
		string percentage;

		if (sum == 0) {
			percentage = to_string(0);
		}
		else {
			percentage = to_string(diceNumberCount[index] / sum * 100);
		}

		cout << "Percentage of times dice rolled " + to_string(index + 1) + ": " + percentage + "%" << endl;
	}
}
