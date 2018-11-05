#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include "Cards.h"
#include "Country.h"
#include "Continent.h"
#include "Dice.h"




using namespace std;

// forward declaration (circular dependency)
class Country;

class Player {

private:
	string name;
	int unavailable_armies;
	vector<Country*> countries;
	Dice* dices;
	Hand* hand;

public:
	Player();
	~Player();
	Player(string);
	Player(string, vector<Country*>);
	Player(string, int);
    Player(int);

	string getName();
    void setName();
	int getArmies();
	void removeAnArmy();
	vector<Country*> getCountries();
	void addCountry(Country* newCountry);
	vector<int> rollDice(int);
	void rollDice(); // for a1 demo
	void showCards(); // for a1 demo
	Country* getCountry(string n);
};

#endif
