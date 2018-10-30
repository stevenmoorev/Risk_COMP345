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

Player::Player(string n, vector<Country*> c) {
	name = n;
	unavailable_armies = 0;
	hand = new Hand();
	dices = new Dice();
	countries = c;
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