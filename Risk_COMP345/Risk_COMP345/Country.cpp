#include "Country.h"

Country::Country() {
	countryName = "";
	numberOfArmies = 0;
}

Country::Country(const string& countryName1) {
	countryName = countryName1;
	numberOfArmies = 0;
}

Country::Country(const string& countryName1, const int& i) {
	countryName = countryName1;
	numberOfArmies = i;
}

Country::Country(const string& countryName1, Player* p, const int& i) {
	countryName = countryName1;
	owner = p;
	numberOfArmies = i;
}

Country::~Country() {
}

void Country::setCountryName(const string& countryName1) {
	countryName = countryName1;
}

string Country::getCountryName() {
	return countryName;
}

void Country::addNeighbor(Country* country) {
	neighbors.push_back(country);
}

Country* Country::getNeighbor(const int& index) {
	return neighbors[index];
}

vector<Country*> Country::getNeighbors() {
	return neighbors;
}

bool Country::isNeighborOf(Country* country)
{
	if (neighbors.empty())
	{
		return false;
	}

	vector<Country*>::iterator it = find(neighbors.begin(), neighbors.end(), country);

	return it != neighbors.end();
}

void Country::setNumberOfArmies(const int& ammount) {
	numberOfArmies = ammount;
}

void Country::addArmy() {
	numberOfArmies++;
}

void Country::addMovedArmy(int movedArmy) {
	numberOfArmies = (numberOfArmies + movedArmy);
}

void Country::removeArmy(int removeArmy) {
	numberOfArmies = (numberOfArmies - removeArmy);
}

int Country::getNumberOfArmies() {
	return numberOfArmies;
}

void Country::setOwner(Player* player) {
	owner = player;
}

Player* Country::getOwner() {
	return owner;
}

bool Country::BelongsToAContinent()
{
	return continent != NULL;
}

Continent* Country::GetContinent() const
{
	return continent;
}

void Country::SetContinent(Continent *continent1)
{
	if (continent == NULL)
	{
		continent = continent1;
	}
}

void Country::setX(int x) 
{
	xPos = x;
}

void Country::setY(int y)
{
	yPos = y;
}

int Country::getX()
{
	return xPos;
}

int Country::getY()
{
	return yPos;
}














