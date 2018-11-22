#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include "Player.h"
#include "Map.h"
#include "MapLoader.h"
#include "ObserverPhase.h"
#include <string>
#include "SubjectPhase.h"
using namespace std;

class Game : public SubjectPhase {
public:
	Game();
	Game(Map* gameMap);
	void setup();
	void setNumberOfPlayers();
	void chooseMap();
	void assignCountries();
	void placeInitialArmies();
	void assignOneRound();
	void reinforcementPhase(int playerNumber);
	void attackPhase(int playerNumber);
	void fortificationPhase(int playerNumber);
	void addDemoPlayers(Player* player);
	void addArmiesToCountry(int amount, Country* c);
	void giveCountriesToPlayers();
	void startGameLoop();
	void assignFirstRound();
	void checkDeath();
	int compareThrownDicesAtt(vector<int> attDicesRolled, vector<int> defDicesRolled);
	int compareThrownDicesDef(vector<int> attDicesRolled, vector<int> defDicesRolled);
	void setBonus(int b);
	int getBonus() const;

	string getPhaseName() { return phaseName; };
	Player* getCurrentPlayer() { return currentPlayer; };
	vector<Player*> getPlayers() { return players; };
	Map* getWorldMap() { return worldMap; };

	//attach observer? 
  
private:
	string phaseName;
	Player* currentPlayer;
	vector<Player*> players;
	bool gameOver; 
	Map* worldMap;
	int bonus = 5;
};

#endif

