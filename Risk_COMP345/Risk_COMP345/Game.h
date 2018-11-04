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
    void chooseMap();
    //bool isMapValid();
	void setNumberOfPlayers();
	void assignCountries();
	void placeInitialArmies();
	void assignOneRound();
   
private:
	vector<Player*> players;
	bool gameOver; 
	Map* worldMap;
};

class Reinforcement
{
public:
    int getA(Player* p); //number of armies to put on map
    void placeArmies(); //put armies until there are no more
};
