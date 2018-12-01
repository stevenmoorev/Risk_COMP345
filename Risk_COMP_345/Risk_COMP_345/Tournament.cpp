#include <iostream>
#include <filesystem>
#include "Game.h"
#include "Tournament.h"

Tournament::Tournament() {
	cout << "This is a tournament." << endl;
	ChooseNumberOfMaps(); //map num chosen. 
	ChooseBestOf(); //num of games per map chosen
	ChooseNumberOfPlayers(); //num of players chosen 
	ChooseMaxTurn(); // number of turns per game chosen
	//first create the players
	initializePlayers(getNumOfPlayers());
	//load the mapnames, then we can just pick the first X maps where X is the number of maps picked by the player.
	loadMapNames(); //mapnames are now in a vector

	//for each map
	for (int i = 0; i < getMapNum(); i++) {
		string* map = getCurrentMap();
		//for each game
		for (int g = 0; g < getBestOf(); g++) {
			//make a game with the current map
			//assign strategies
			//play for getMaxTurn() turns
			//give points to whoever won or to anyoen alive during a draw using player.incrementScore method I created.
		}
		incrementMap();
	}
	displayResults();
}

void Tournament::displayResults() {//THIS METHOD IS JUST A COUT METHOD.
	cout << "TOURNAMENT IS OVER. HERE ARE THE RESULTS:" << endl;
	//TODO: DISPLAY RESULTS
}

void Tournament::setCurrentMap(int x) {
	currentMap = x;
}

string* Tournament::getCurrentMap() {
	return mapNames[currentMap];
}

void Tournament::AddMap(string* map) {
	mapNames.push_back(map);
}

void Tournament::loadMapNames() {
	for (auto & p : filesystem::directory_iterator("Maps")) {
		auto filename = p.path().filename();
		if (p.path().extension() == ".map")
			AddMap(&filename.string());
	}
}

void Tournament::initializePlayers(int x) {
	for (int i = 0; i < getNumOfPlayers(); i++) {
		players[i] = new Player();
	}
}

void Tournament::ChooseNumberOfMaps() {
	cout << "Please chose 2 or 3 maps." << endl;
	string mapNum;
	cin >> mapNum;
	if (mapNum == "2") {
		setMapNum(2);
		cout << "You have chosen 2 maps." << endl;
	}
	else {
		setMapNum(3);
		cout << "You have chosen 3 maps." << endl;
	}
}

void Tournament::setMapNum(int x) {
	mapNum = x;
}

void Tournament::setBestOf(int x) {
	bestOf = x;
}

void Tournament::setNumOfPlayers(int x) {
	numOfPlayers = x;
}

void Tournament::ChooseBestOf() {
	cout << "Now you must chose the number of games to be played on each map. Please chose a number from 1 to 5" << endl;
	int num;
	cin >> num;
	setMapNum(num);
	cout << "Every map will be decided in a best of " << getMapNum() << "!" << endl;
}

void Tournament::ChooseNumberOfPlayers() {
	cout << "You must now chose a number of players to play eachother.  This is a tournament that will be played by AI players only." << endl;
	cout << endl;
	cout << "Please chose a number between, and including, 2 and 4" << endl;
	int num;
	cin >> num;
	setNumOfPlayers(num);
	cout << "You have chosen " << getNumOfPlayers() << " players to play this. Their behaviour will be decided at random." << endl;
}

void Tournament::setMaxTurn(int x) {
	maxTurn = x;
}

void Tournament::ChooseMaxTurn() {
	cout << "You will now choose the maximum number of turns to be played on each map. After this number of turns, every player alive will be awarded a point." << endl;
	cout << "Please chose a number between, and including, 3 and 50." << endl;
	int num;
	cin >> num;
	setMaxTurn(num);
	cout << "You have chosen " << getMaxTurn() << " number of turns to be played in each match on each map.";
}