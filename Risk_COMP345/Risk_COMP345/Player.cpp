#include "Player.h"

Player::Player() {
	name = "";
	unavailable_armies = 0;
	hand = new Hand();
	dices = new Dice();
}

Player::~Player(void) {
	delete dices;
	delete hand;
}

Player::Player(string n) {
	name = n;
	unavailable_armies = 0;
	hand = new Hand();
	dices = new Dice();
}

Player::Player(string n, int a) {
	name = n;
	unavailable_armies = a;
	hand = new Hand();
	dices = new Dice();
}

Player::Player(string n, vector<Country*> c) {
	name = n;
	unavailable_armies = 0;
	hand = new Hand();
	dices = new Dice();
	countries = c;
}

void Player::removeAnArmy() {
	if (unavailable_armies > 0) {
		unavailable_armies--;
	}
}

string Player::getName() {
	return name;
}

int Player::getArmies() {
	return unavailable_armies;
}

vector<Country*> Player::getCountries() {
	return countries;
}

void Player::addCountry(Country* newCountry) {
	countries.push_back(newCountry);
}

Country* Player::getCountry(string n) {
	for (int i = 0; i < countries.size(); i++)
	{
		if (countries[i]->getCountryName() == n)
		{
			return countries[i];
		}
	}
	return NULL;
}

vector<int> Player::rollDice(int numDice) {
	vector<int> results = dices->throwDice(numDice);
	sort(results.begin(), results.begin() + results.size());
	return results;
}


//for demo
////////////////////////////////////
////////////////////////////////// 
void Player::rollDice() {
	dices->throwDice(3);
	dices->printdiceNumberCount();
}
////////////////////////////////////
////////////////////////////////////
void Player::showCards() {
	hand->getCards();
}