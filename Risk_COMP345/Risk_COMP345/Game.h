#include <string>
#include <vector>
#include "Player.h"
#include "Map.h"

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
	void attackPhase(int playerNumber);
	void fortificationPhase(int playerNumber);
private:
	vector<Player*> players;
	bool gameOver; 
	Map* worldMap;
};