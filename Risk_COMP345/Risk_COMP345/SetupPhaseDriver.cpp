#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Player.h";
#include "Map.h"
#include "Dice.h"
using namespace std;

int main() {
	string input;
	cout << "Map being created with the following countries:" << endl;
	Country* c1 = new Country("Canada");
	Country* c2 = new Country("USA");
	Country* c3 = new Country("Mexico");

	Country* c4 = new Country("England");
	Country* c5 = new Country("SomeThing Next To England");

	cout << c1->getCountryName() << ", " << c2->getCountryName() << ", " << c3->getCountryName() << ", " << c4->getCountryName() << ", " << c5->getCountryName() << endl;
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
	cout << "England and something next to england are linked. england is linked to Canada." << endl;
	c1->addNeighbor(c4);
	c4->addNeighbor(c1);
	c5->addNeighbor(c4);
	c4->addNeighbor(c5);
	cout << "They are in Europe" << endl;
	Continent* con2 = new Continent("Europe");
	con2->AddCountry(c4);
	con2->AddCountry(c5);
	//put NA in map
	Map* driverMap = new Map();
	driverMap->AddContinentToMap(con);
	driverMap->AddContinentToMap(con2);
	Game* myGame = new Game(driverMap);
	//4 initial armies
	Player* p1 = new Player("Godzilla", 4);
	Player* p2 = new Player("Superman", 4);
	myGame->addDemoPlayers(p1);
	myGame->addDemoPlayers(p2);

	myGame->assignCountries();

	myGame->placeInitialArmies();
	return 0;
}