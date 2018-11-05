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
	//bool isMapValid();
	void assignCountries();
	void placeInitialArmies();
	void assignOneRound();
	void reinforcementPhase(int playerNumber);
	void attackPhase(int playerNumber);
	void fortificationPhase(int playerNumber);
	void addDemoPlayers(Player* player);
	void addArmiesToCountry(int amount, Country* c);
	int compareThrownDicesAtt(vector<int> attDicesRolled, vector<int> defDicesRolled);
	int compareThrownDicesDef(vector<int> attDicesRolled, vector<int> defDicesRolled);
private:
	vector<Player*> players;
	bool gameOver; 
	Map* worldMap;
};