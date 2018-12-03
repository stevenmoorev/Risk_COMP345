#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Player.h"
#include "Map.h"
#include "Dice.h"
using namespace std;
/*
int main() {
	string input;
	cout << "Map being created with the following countries:" << endl;
	Country* c1 = new Country("Canada");
	Country* c2 = new Country("USA");
	Country* c3 = new Country("Mexico");

	cout << c1->getCountryName() << ", " << c2->getCountryName() << ", " << c3->getCountryName() << endl;
	cout << "Canada is linked to USA, which is linked to Canada and Mexico, which is linked to USA." << endl;
	//the linking is canada - usa - mexico
	//canada to usa
	c1->addNeighbor(c2);
	c2->addNeighbor(c1);
	//usa to mexico
	c2->addNeighbor(c3);
	c3->addNeighbor(c2);
	//put them in north america
	Continent* con = new Continent("NorthAmerica");
	cout << "These countries are in NorthAmerica" << endl;
	con->AddCountry(c1);
	con->AddCountry(c2);
	con->AddCountry(c3);
	//put NA in map
	Map* driverMap = new Map();
	driverMap->AddContinentToMap(con);
	Game* myGame = new Game(driverMap);
	
	Player* p1 = new Player("Godzilla");
	Player* p2 = new Player("Superman");
	myGame->addDemoPlayers(p1);
	myGame->addDemoPlayers(p2);
	//Godzilla has canada, superman has USA and mexico
	p1->addCountry(c1);
	c1->setOwner(p1);
	p2->addCountry(c2);
	c2->setOwner(p2);
	p2->addCountry(c3);
	c3->setOwner(p2);
	cout << "We have two Players. Player 1 is Godzilla, and Player 2 is Superman." << endl;
	cout << "Godzilla owns Canada, and Superman owns USA and Mexico." << endl;
	//now we test the attacking phase:
	cout << "We will now add 1 army to each country" << endl;
	//add armies
	myGame->addArmiesToCountry(3, c1);
	myGame->addArmiesToCountry(5, c2);
	myGame->addArmiesToCountry(5, c3);

	myGame->attackPhase(0);
	
	//try to attack mexico from canada, invalid
	//attack usa from canada, valid.
	//chose invalid number fo dice
	//chose valid number of dice
	//make sure the dice values are working with the rules.

	//making sure you can attack more than once a turn is a game loop issue and will be tested in the main game loop
}

*/