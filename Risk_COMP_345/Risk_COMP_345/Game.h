#include <string>
#include <vector>
#include "Player.h"
#include "Map.h"
#include "MapLoader.h"
#include <string>
using namespace std;

class Game 
{
public:
	Game();
	Game(Map* gameMap);
	void setup();
	void setNumberOfPlayers();
	void chooseMap();
	//bool isMapValid();
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
	int compareThrownDicesAtt(vector<int> attDicesRolled, vector<int> defDicesRolled);
	int compareThrownDicesDef(vector<int> attDicesRolled, vector<int> defDicesRolled);
	void setBonus(int b);
	int getBonus() const;
private:
	vector<Player*> players;
	bool gameOver; 
	Map* worldMap;
	int bonus = 5;
};