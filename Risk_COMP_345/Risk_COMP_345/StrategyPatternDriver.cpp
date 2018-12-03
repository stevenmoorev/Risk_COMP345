//
//  StrategyPatternDriver.cpp
//  RISK
//
//  Created by Steven Moore on 2018-11-18.
//  Copyright © 2018 Steven Moore. All rights reserved.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include "Game.h"
#include "AggressiveStrategy.h"
#include "BenevolentStrategy.h"
#include "UserStrategy.h"
#include "RandomStrategy.h"
#include "CheaterStrategy.h"
#include "Game.h"
#include "Strategy.h"
#include "View.h"
#include "GameStatView.h"
#include "StrategyPatternDriver.h"

using namespace std;

int main() {
//    Game* g = new Game();
//    g->setup();
//    
//    //Strategy* st = new Strategy();
//    AggressiveStrategy* as = new AggressiveStrategy();
//    BenevolentStrategy* bs = new BenevolentStrategy();
//    
//    g->getPlayers()[0]->setStrategy(as);
//    g->getPlayers()[1]->setStrategy(bs);
//    
//    g->startGameLoop();
//    
//    //have to be able to change the strategy


	////Dynamically change the strategy
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
	p1->setIsNPC();
	Player* p2 = new Player("Superman");
	p2->setIsNPC();
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

	vector <Player*> players;
	players.push_back(p1);
	players.push_back(p2);

	int playerNumber = 1;
	srand(time(NULL));
	vector <string> strat;
	//strat.push_back('U');
	strat.push_back("A");
	strat.push_back("B");
	strat.push_back("R");
	strat.push_back("C");

	for (int playerNumber = 0; playerNumber < players.size(); playerNumber++) {
		int choosenStrat = rand() % strat.size();
		string strategy = strat[choosenStrat];
		//cout << "Current strategy is " << players[playerNumber]->getStrategyName() << ". ";
		//string response;
		//cout << "Would you like to change strategies? (Y/N)" << endl;
		//cin >> response;
		//if (response == "y" || response == "Y") {
		cout << "Which strategy would you like to use? U (user), A (aggressive), B (benevolent), R (Random), C (Cheater)?" << endl;
		cout << players[playerNumber]->getName() << " computer has chosen strategy " << strategy << endl;
			if (strategy == "U") {
				UserStrategy* s = new UserStrategy();
				players[playerNumber]->setStrategy(s);
			}
			if (strategy == "A") {
				AggressiveStrategy* s = new AggressiveStrategy();
				players[playerNumber]->setStrategy(s);
			}
			if (strategy == "B") {
				BenevolentStrategy* s = new BenevolentStrategy();
				players[playerNumber]->setStrategy(s);
			}
			if (strategy == "R") {
				RandomStrategy* s = new RandomStrategy();
				players[playerNumber]->setStrategy(s);
			}
			if (strategy == "C") {
				CheaterStrategy* s = new CheaterStrategy();
				players[playerNumber]->setStrategy(s);
			}
		cout << "CHOSEN!" << endl;
		////REINFORCE
		players[playerNumber]->getStrategy()->reinforce(players[playerNumber]);

		////ATTACK
		players[playerNumber]->getStrategy()->attack(players[playerNumber]);

		//FORTIFY
		players[playerNumber]->getStrategy()->fortify(players[playerNumber]);
	}
}
