#include <string>
#include <vector>
#include "Player.h"
#include "Map.h"

using namespace std;

class Game 
{
public:
	Game();
	void setup();
	void setNumberOfPlayers();
	bool isMapValid();
	void assignCountries();
private:
	vector<Player*> players;
	bool gameOver; 
	Map* worldMap;
};