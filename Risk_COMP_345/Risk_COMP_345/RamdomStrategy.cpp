//
//  RandomStrategy.cpp
//  RISK
//
//  Created by Steven Moore on 2018-11-18.
//  Copyright © 2018 Steven Moore. All rights reserved.
//

#include "RandomStrategy.h"
#include "Player.h"

RandomStrategy::RandomStrategy(){
    
}

RandomStrategy::~RandomStrategy(){
    
}

//Random player reinforces to strongest country
string RandomStrategy::reinforce(Player *p1){
	/* initialize random seed: */
	srand(time(NULL));

	//how many armies?
	int bonus = (int)p1->getCountries().size() / 3;
	vector <Country*> allOwnedCountry = p1->getCountries();
	Country* selectedCountry = NULL;
	
	//reinforce random country selection
	//while (bonus > 0) {
		int indexOfSelectedCountry = rand() % (allOwnedCountry.size());
		selectedCountry = allOwnedCountry[indexOfSelectedCountry];
	//	std::cout << "Reinforce to country " << selectedCountry->getCountryName() << endl;
	//	selectedCountry->addArmy();
	//	std::cout << bonus << " armies added to " << selectedCountry->getCountryName() << " now has " << selectedCountry->getNumberOfArmies() << endl;
	//	bonus--;
	//}

		return selectedCountry->getCountryName();
}

void RandomStrategy::attack(Player *p1) {
	/* initialize random seed: */
	srand(time(NULL));
	
	/* generate random country selection (List of countries from 0 to .size()) */
	vector <Country*> allOwnedCountries;
	vector <Country*> neighborCountries;
	Country* selectedNeighbor = NULL;
	Country* selectedCountry = NULL;
	bool properNeighbor = false;
	bool properArmy = false;
	int tries = 0;
	//generate random country and neighbor selection
	do {
		std::cout << "Search a random country and a random neighbor..." << endl;
		//Selection of country
		allOwnedCountries = p1->getCountries();
		int indexOfSelectedCountry = rand() % (allOwnedCountries.size());
		selectedCountry = allOwnedCountries[indexOfSelectedCountry];

		//Selection of neigbor country
		neighborCountries = selectedCountry->getNeighbors();
		int indexOfFortifiedCountry = rand() % (neighborCountries.size());
		selectedNeighbor = neighborCountries[indexOfFortifiedCountry];

		//Verify if the neighbor is an oppenent and that its selected country has proper armies
		properNeighbor = selectedNeighbor->getOwner()->getName() != p1->getName() ? true : false;
		properArmy = selectedCountry->getNumberOfArmies() > 1 ? true : false;
		tries++;
	} while (!(properNeighbor && properArmy && (tries < p1->getCountries().size())));
	
	//Attack Neighbor
	Player* neighborPlayer = selectedNeighbor->getOwner();
	int countryArmyCount = 0;
	int neighborArmyCount = 0;

	countryArmyCount = selectedCountry->getNumberOfArmies();
	neighborArmyCount = selectedNeighbor->getNumberOfArmies();

	//Random Number of times to attack
	int attackTimes = rand() % countryArmyCount;
	attackTimes = (attackTimes == 0) ? (attackTimes++) : (attackTimes);
	while (attackTimes > 0)
	{
		vector<int> attDicesRolled;
		vector<int> defDicesRolled;
		int attNumDices;
		int defNumDices;
		if (countryArmyCount == 1 || countryArmyCount == 1)
		{
			attackTimes = 0;
			break;
		}
		if (countryArmyCount == 2)
		{
			attNumDices = 1;
			std::cout << "\n ATTACKER - Your country has only 2 armies. You will throw 1 dice only" << endl;
			attDicesRolled = p1->rollDice(attNumDices);
		}
		if (countryArmyCount == 3)
		{
			std::cout << "\n ATTACKER - The country has 3 armies. Choose to throw 1 or 2 dices" << endl;
			attNumDices = rand() % 2 + 1;
			attDicesRolled = p1->rollDice(attNumDices);
		}
		if (countryArmyCount > 3)
		{
			std::cout << "\n ATTACKER - The country has a lot armies. Choose to throw 1, 2 or 3 dices" << endl;
			attNumDices = rand() % 3 + 1;
			attDicesRolled = p1->rollDice(attNumDices);
		}
		if (neighborArmyCount == 1) {
			defNumDices = 1;
			std::cout << "\n DEFENDER - You will roll 1 dice" << endl;
			defDicesRolled = neighborPlayer->rollDice(defNumDices);
		}
		if (neighborArmyCount >= 2) {
			do {
				std::cout << "\n DEFENDER - please select 1 or 2 dices" << endl;
				if (!(neighborPlayer->getIsNPC())) {
					cin >> defNumDices;
				}
				else 
				{
					defNumDices = 2;
				}
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
		selectedNeighbor->removeArmy(defendersEliminated);
		cout << "Attacker has eliminated " << defendersEliminated << "  defenders" << endl;
		int attackersEliminated = compareThrownDicesAtt(attDicesRolled, defDicesRolled);
		selectedCountry->removeArmy(attackersEliminated);
		cout << "Defender has eliminated " << attackersEliminated << "  attackers" << endl;
		attackTimes--;
	} //RANDOM ATTACK TIMES ON RANDOM COUNTRY AND RANDOM NEIGHBOR DONE
}

void RandomStrategy::fortify(Player *p1){
	/* initialize random seed: */
	srand(time(NULL));

	/* generate random country selection (List of countries from 0 to .size()) */
	vector <Country*> allOwnedCountries;
	vector <Country*> neighborCountries;
	Country* selectedNeighbor = NULL;
	Country* selectedCountry = NULL;
	bool properNeighbor = false;
	bool properArmy = false;
	int tries = 0;
	//generate Random fortification 
	do {
		cout << "Search a random country and a a random neighbor..." << endl;

		//Select country
		allOwnedCountries = p1->getCountries();
		int indexOfSelectedCountry = rand() % (allOwnedCountries.size());
		selectedCountry = allOwnedCountries[indexOfSelectedCountry];

		//Select neighbor
		neighborCountries = selectedCountry->getNeighbors();
		int indexOfFortifiedCountry = rand() % (neighborCountries.size());
		selectedNeighbor = neighborCountries[indexOfFortifiedCountry];

		//Verify if the neighbor is an oppenent and that its selected country has proper armies
		properNeighbor = selectedNeighbor->getOwner()->getName() == p1->getName() ? true : false;
		properArmy = selectedCountry->getNumberOfArmies() > 1 ? true : false;
		tries++;
	} while (!(properNeighbor && properArmy && (tries < p1->getCountries().size())));

	if (tries >= p1->getCountries().size())
	{
		cout << "No valid countries to fortify";
	}
	else 
	{
		int numberOfArmiesToMove = rand() % selectedCountry->getNumberOfArmies();

		numberOfArmiesToMove = (numberOfArmiesToMove == 0) ? numberOfArmiesToMove++ : numberOfArmiesToMove;

		//removeArmy
		selectedCountry->removeArmy(numberOfArmiesToMove);
		//Add Army to neighbor
		selectedNeighbor->addMovedArmy(numberOfArmiesToMove);
	}
}


int RandomStrategy::compareThrownDicesDef(vector<int> attDicesRolled, vector<int> defDicesRolled) {
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

int RandomStrategy::compareThrownDicesAtt(vector<int> attDicesRolled, vector<int> defDicesRolled) {
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
