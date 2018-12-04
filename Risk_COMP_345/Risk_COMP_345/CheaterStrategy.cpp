#include "CheaterStrategy.h"
#include "Player.h"

CheaterStrategy::CheaterStrategy() {

}

CheaterStrategy::~CheaterStrategy() {

}

//double all your country armies
void CheaterStrategy::reinforce(Player *p1) {
	Notify();
	cout << "==== CHEATER REINFORCE ====" << endl;
	cout << "Player "<< p1->getName()<< "is reinforcing all his countries..."<< endl;
	cout << "All his countries have now doubled their army size!" << endl;
	vector<Country*> countries = p1->getCountries();
	for (int i = 0; i < countries.size(); i++) 
	{
		int armyNumber = countries[i]->getNumberOfArmies();
		for (int y = 0; y < armyNumber; y ++) 
		{
			countries[i]->addArmy();
		}
	}
}
//start by getting each country in the player's ownership. A
//for each of those countries, loop through all its neighbors. B
//for each of those neighbors, IF is not owned by this player, jsut give it to the AI. C
void CheaterStrategy::attack(Player *p1) {
	Notify();
	cout << "==== CHEATER ATTACK ====" << endl;
	cout << "ALL OF NEIGHBOR COUTNRIES NOW BELONG TO PLAYER "<< p1->getName() << "!!! HAHAHAHA!" << endl;
	vector<Country*> countries = p1->getCountries();
	for (int i = 0; i < countries.size(); i++) //A
	{
		vector<Country*> neighbors = countries[i]->getNeighbors();
		for (int y = 0; y < neighbors.size(); y++) //B
		{
			if (neighbors[y]->getOwner()->getName() != p1->getName()) 
			{
				neighbors[y]->setOwner(p1); //C
				p1->addCountry(neighbors[y]); //C
			}
		}
	}
}
//start by getting each country in players ownership. A
//for each country, check if it has any enemy neighbors. B
//if it does, double armies
void CheaterStrategy::fortify(Player *p1) {
	Notify();
	cout << "==== CHEATER FORTIFY ====" << endl;
	cout << "Must fortify countries..... checking to see if any have neighbors..." << endl;
	vector<Country*> countries = p1->getCountries();
	for (int i = 0; i < countries.size(); i++) //A
	{
		bool hasEnemyNeighbor = false;
		vector<Country*> neighbors = countries[i]->getNeighbors();
		for (int y = 0; y < neighbors.size(); y++) 
		{
			if (neighbors[y]->getOwner()->getName() != p1->getName()) //B
			{
				hasEnemyNeighbor = true;
			}
		}
		if (hasEnemyNeighbor) //C
		{
			int numberOfArmies = countries[i]->getNumberOfArmies();
			for (int j = 0; j < numberOfArmies; j++) 
			{
				countries[i]->addArmy();
			}
		}
	}
	cout << "THEIR ARMIES HAVE BEEN DOUBLED MUAHAHAHAHA" << endl;
}