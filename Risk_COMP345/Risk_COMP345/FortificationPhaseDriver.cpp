//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include "Game.h"
//#include "Player.h";
//#include "Map.h"
//#include "Dice.h"
//using namespace std;
//
//int main() {
//	cout << "Map being created with the following countries:" << endl;
//	Country* c1 = new Country("Canada");
//	Country* c2 = new Country("USA");
//	Country* c3 = new Country("Mexico");
//
//	//the linking is canada - usa - mexico
//	//canada to usa
//	c1->addNeighbor(c2);
//	c2->addNeighbor(c1);
//	//usa to mexico
//	c2->addNeighbor(c3);
//	c3->addNeighbor(c2);
//	//put them in north america
//	Continent* con = new Continent("NorthAmerica");
//	con->AddCountry(c1);
//	con->AddCountry(c2);
//	con->AddCountry(c3);
//	//put NA in map
//	Map* driverMap = new Map();
//	driverMap->AddContinentToMap(con);
//
//	
//	Player* p1 = new Player("Godzilla");
//	Player* p2 = new Player("Superman");
//	//Godzilla has canada, superman has USA and mexico
//	p1->addCountry(c1);
//	p2->addCountry(c2);
//	p2->addCountry(c3);
//
//	//now we test the fortification phase:
//	Game* game = new Game();
//	game->addDemoPlayers(p1);
//	game->fortificationPhase(1);
//	game->fortificationPhase(2);
//}