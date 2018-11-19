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
#include "Strategy.h"

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
    Strategy* strategy;
	bool isNPC;

public:
	Player();
	~Player();
    Player(int);
	Player(string);
	Player(string, vector<Country*>);
	Player(string, int);

	string getName();
	int getArmies();
	void removeAnArmy();
	vector<Country*> getCountries();
	void addCountry(Country* newCountry);
	vector<int> rollDice(int);
	void rollDice(); // for a1 demo
	void showCards(); // for a1 demo
	Country* getCountry(string n);
    void setHand();
	Hand* getHand();
    void setDice();
	Dice* getDice();
	bool getIsNPC() { return isNPC; };
	void setIsNPC() { isNPC = true; };
    void setCountries();
    void setName();
    void setArmies(int armies);
	void removeCountry(Country* oldCountry);
    Strategy* getStrategy(){return strategy;};
    void setStrategy(Strategy* st){strategy = st;};
};

#endif
