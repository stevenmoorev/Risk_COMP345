#include "Player.h"
#include "UserStrategy.h"

Player::Player() {
	name = "";
	unavailable_armies = 0;
	hand = new Hand();
	dices = new Dice();
	//UserStrategy* us = new UserStrategy();
	strategy = NULL;
	score = 0;
}

Player::~Player(void) {
	delete dices;
	delete hand;
	delete strategy;
}

Player::Player(string n) {
	name = n;
	unavailable_armies = 0;
	hand = new Hand();
	dices = new Dice();
	isNPC = false;
	//UserStrategy* us = new UserStrategy();
	strategy = NULL;
	score = 0;

}

Player::Player(string n, int a) {
	score = 0;
	name = n;
	unavailable_armies = a;
	hand = new Hand();
	dices = new Dice();
	isNPC = false;
	//UserStrategy* us = new UserStrategy();
	strategy = NULL;
}

Player::Player(int a) {
	score = 0;
    name = "";
    unavailable_armies = a;
    hand = new Hand();
    dices = new Dice();
	isNPC = false;
	//UserStrategy* us = new UserStrategy();
	strategy = NULL;
}


Player::Player(string n, vector<Country*> c) {
	name = n;
	score = 0;
	unavailable_armies = 0;
	hand = new Hand();
	dices = new Dice();
	countries = c;
	isNPC = false;
	//UserStrategy* us = new UserStrategy();
	strategy = NULL;
}

void Player::removeAnArmy() {
	if (unavailable_armies > 0) {
		unavailable_armies--;
	}
}

void Player::setName(string n) {
	name = n;
}

string Player::getName() {
	return name;
}

void Player::incrementScore()
{
	score++;
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

void Player::removeCountry(Country* oldCountry) {
	for (int i = 0; i < countries.size(); i++) {
		if (countries[i]->getCountryName() == oldCountry->getCountryName()) {
			countries.erase(countries.begin()+i);
		}
	}
}

void Player::reinforce(Player * p1)
{
	getStrategy()->reinforce(p1);
}

void Player::attack(Player * p1)
{
	getStrategy()->attack(p1);
}

void Player::fortify(Player * p1)
{
	getStrategy()->fortify(p1);
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

void Player::setDice(){
    Dice d;
    dices = &d;
}
Dice * Player::getDice()
{
	return dices;
}
void Player::setHand(){
    Hand h;
    hand = &h;
}
Hand * Player::getHand()
{
	return hand;
}
void Player::setName(){
    string n;
    // create our players
        cout << "PLEASE ENTER NAME OF PLAYER ";
        cout << endl;
        cin >> n;
        this->name = n;
        //Player* currentPlayer = new Player(name, armyAllocation);
        //players.push_back(currentPlayer);
    
}
void Player::setArmies(int armies){
    //int armies;
    unavailable_armies = armies;
}


