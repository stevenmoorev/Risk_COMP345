#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include "Game.h"
using namespace std;

class Tournament {
public:
	Tournament();
	Game* getGame() { return game; };
	void ChooseNumberOfMaps();
	void setMapNum(int x);
	int getMapNum() { return mapNum; };
	void ChooseBestOf();
	void setBestOf(int x);
	int getBestOf() { return bestOf; };
	void setNumOfPlayers(int x);
	int getNumOfPlayers() { return numOfPlayers; };
	void ChooseNumberOfPlayers();
	void setMaxTurn(int x);
	int getMaxTurn() { return maxTurn; };
	void ChooseMaxTurn();
	void initializePlayers(int x);
	void loadMapNames();
	void AddMap(string s);
	string getCurrentMap();
	void setCurrentMap(int x);
	void incrementMap() { currentMap++; };
	void displayResults();
private:
	Game* game;
	int mapNum;
	int bestOf;
	int numOfPlayers;
	int maxTurn;
	vector<Player*> players;
	vector<string> mapNames;
	int currentMap;
};

#endif