#include "Player.h"

Player::Player() {
	name = "";
	unavailable_armies = 0;
	hand = new Hand();
	dices = new Dice();
}

Player::~Player(void) {
	//delete dices;
	//delete hand;
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

Player::Player(int a) {
    name = "";
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

void Player::removeCountry(Country* oldCountry) {
	for (int i = 0; i < countries.size(); i++) {
		if (countries[i]->getCountryName() == oldCountry->getCountryName()) {
			countries.erase(countries.begin()+i);
		}
	}
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

