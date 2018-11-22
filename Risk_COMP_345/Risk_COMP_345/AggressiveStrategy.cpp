//
//  AggressiveStrategy.cpp
//  RISK
//
//  Created by Steven Moore on 2018-11-18.
//  Copyright © 2018 Steven Moore. All rights reserved.
//

#include "AggressiveStrategy.h"
#include "Player.h"

AggressiveStrategy::AggressiveStrategy(){
    
}

AggressiveStrategy::~AggressiveStrategy(){
    
}

//aggressive player reinforces to strongest country
void AggressiveStrategy::reinforce(Player *p1){
    
	cout << "====STRATEGY====" << endl;
	//reinforce strongest country
    int indexLargest = 0;
    for(int i = 0; i < p1->getCountries().size() - 1; i++){
        //p1->getCountries()[i]->getNumberOfArmies();
        //one with most armies
        if(p1->getCountries()[i]->getNumberOfArmies() > p1->getCountries()[indexLargest]->getNumberOfArmies())
            indexLargest = i;
    }
    cout << "Reinforce to country " << p1->getCountries()[indexLargest]->getCountryName() << endl;

	//how many armies?
	int bonus = (int)p1->getCountries().size() / 3;
	cout << bonus << " armies added to " << p1->getCountries()[indexLargest]->getCountryName() << endl;
	for (int i = 0; i < bonus; i++) {
		p1->getCountries()[indexLargest]->addArmy();
	}
}

void AggressiveStrategy::attack(Player *p1) {
	cout << "====STRATEGY====" << endl;
	int armyCount = 0;
	Country* countryWithMostArmy = NULL;
	Country* weakNeighbor = NULL;
do {
	vector <Country*> allCountries = p1->getCountries();
	for (int i = 0; i < allCountries.size(); i++) {
		if (armyCount < allCountries[i]->getNumberOfArmies())
		{
			armyCount = allCountries[i]->getNumberOfArmies();
			countryWithMostArmy = allCountries[i];
		}
	}
	cout << "Aggresive NPC chose " << countryWithMostArmy->getCountryName() << " which has " << armyCount << " army units" << endl;
	//Find weakest NEIGHBOR
	vector <Country*> allNeighbors = countryWithMostArmy->getNeighbors();
	int weakestNeighborArmy = allNeighbors[0]->getNumberOfArmies();
	for (int i = 0; i < allNeighbors.size(); i++)
	{
		if (weakestNeighborArmy > allNeighbors[i]->getNumberOfArmies())
		{
			weakestNeighborArmy = allNeighbors[i]->getNumberOfArmies();
			weakNeighbor = allNeighbors[i];
		}
	}
	//ATTACK
	//Roll correct number of dices to attack selected neighbor country
	Player* neighborPlayer = weakNeighbor->getOwner();
	vector<int> attDicesRolled;
	vector<int> defDicesRolled;
	int attNumDices;
	int defNumDices;
	if (armyCount == 2)
	{
		attNumDices = 1;
		cout << "\n ATTACKER - Your country has only 2 armies. You will throw 1 dice only" << endl;
		attDicesRolled = p1->rollDice(attNumDices);
	}
	if (armyCount == 3)
	{
		cout << "\n ATTACKER - The country has 3 armies. Choose to throw 1 or 2 dices" << endl;
		attNumDices = 2;
		attDicesRolled = p1->rollDice(attNumDices);
	}
	if (armyCount > 3)
	{
		cout << "\n ATTACKER - The country has a lot armies. Choose to throw 1, 2 or 3 dices" << endl;
		attNumDices = 3;
		attDicesRolled = p1->rollDice(attNumDices);
	}
	if (weakestNeighborArmy == 1) {
		defNumDices = 1;
		cout << "\n DEFENDER - You will roll 1 dice" << endl;
		defDicesRolled = neighborPlayer->rollDice(defNumDices);
	}
	if (weakestNeighborArmy >= 2) {
		do {
			cout << "\n DEFENDER - please select 1 or 2 dices" << endl;
			cin >> defNumDices;
		} while (defNumDices < 1 || defNumDices > 2);
		defDicesRolled = neighborPlayer->rollDice(defNumDices);
	}
	cout << endl;
	cout << "ATTACKER DICES: ";
	for (int i = 0; i < attDicesRolled.size(); i++) { cout << attDicesRolled[i] << ", "; }
	cout << endl;
	cout << "DEFFENDER DICES: ";
	for (int i = 0; i < defDicesRolled.size(); i++) { cout << defDicesRolled[i] << ", "; }
	cout << endl;
	//Remove defender armies and attacker armies
	int defendersEliminated = compareThrownDicesDef(attDicesRolled, defDicesRolled);
	weakNeighbor->removeArmy(defendersEliminated);
	cout << "Attacker has eliminated " << defendersEliminated << "  defenders" << endl;
	int attackersEliminated = compareThrownDicesAtt(attDicesRolled, defDicesRolled);
	countryWithMostArmy->removeArmy(attackersEliminated);
	cout << "Defender has eliminated " << attackersEliminated << "  attackers" << endl;
} while (armyCount > 1);
}

void AggressiveStrategy::fortify(Player *p1){
	cout << "====STRATEGY====" << endl;
	//aggregate forces in one country
    int indexLargest = 0;
    for(int i = 0; i < p1->getCountries().size() - 1; i++){
        //p1->getCountries()[i]->getNumberOfArmies();
        //one with most armies
        if(p1->getCountries()[i]->getNumberOfArmies() > p1->getCountries()[indexLargest]->getNumberOfArmies())
            indexLargest = i;
    }
    cout << "Fortify to country " << p1->getCountries()[indexLargest]->getCountryName() << endl;
    //look through all of the countries and find second largest country (cannot be the largest)
    int indexSecondLargest = 0;
    for(int i = 0; i < p1->getCountries().size() - 1; i++){
        //p1->getCountries()[i]->getNumberOfArmies();
        //one with most armies
        if(p1->getCountries()[i]->getNumberOfArmies() > p1->getCountries()[indexSecondLargest]->getNumberOfArmies() && i != indexLargest)
            indexSecondLargest = i;
    }
    cout << "Move from country " << p1->getCountries()[indexSecondLargest]->getCountryName() << endl;

	int difference = (int)(p1->getCountries()[indexLargest]->getNumberOfArmies() - p1->getCountries()[indexSecondLargest]->getNumberOfArmies()) ;
	cout << difference << " armies moved" << endl;
	for (int i = 0; i < difference; i++) {
		p1->getCountries()[indexSecondLargest]->removeArmy(1);
		p1->getCountries()[indexLargest]->addArmy();
	}
}


int AggressiveStrategy::compareThrownDicesDef(vector<int> attDicesRolled, vector<int> defDicesRolled) {
	int defendersEliminated = 0;
	int attackersEliminated = 0;
	int LastIndexOfAttDices = attDicesRolled.size();
	int LastIndexOfDefDices = defDicesRolled.size();
	LastIndexOfAttDices--;
	LastIndexOfDefDices--;
	for (int i = 0; i < defDicesRolled.size(); i++) {
		if (LastIndexOfAttDices >= 0 && LastIndexOfDefDices >= 0) {
			if (attDicesRolled[LastIndexOfAttDices] > defDicesRolled[LastIndexOfDefDices]) {
				defendersEliminated++;
			}
			LastIndexOfAttDices--;
			LastIndexOfDefDices--;
		}
	}
	return defendersEliminated;
}

int AggressiveStrategy::compareThrownDicesAtt(vector<int> attDicesRolled, vector<int> defDicesRolled) {
	int defendersEliminated = 0;
	int attackersEliminated = 0;
	int LastIndexOfAttDices = attDicesRolled.size();
	int LastIndexOfDefDices = defDicesRolled.size();
	LastIndexOfAttDices--;
	LastIndexOfDefDices--;
	for (int i = 0; i < defDicesRolled.size(); i++) {
		if (LastIndexOfAttDices >= 0 && LastIndexOfDefDices >= 0) {
			if (defDicesRolled[LastIndexOfDefDices] >= attDicesRolled[LastIndexOfAttDices]) {
				attackersEliminated++;
			}
			LastIndexOfAttDices--;
			LastIndexOfDefDices--;
		}
	}
	return attackersEliminated;
}
