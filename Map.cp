#include "Map.h"

using namespace std;
Map::Map()
{
}

Map::~Map()
{
	for (vector<Continent*>::iterator it = mapContinents.begin(); it != mapContinents.end(); it++)
	{
		delete *it;
		*it = NULL;
	}
	mapContinents.clear();
}

void Map::AddContinentToMap(Continent *newContinent)
{
	vector<Continent*>::iterator it = find(mapContinents.begin(), mapContinents.end(), newContinent);
	if (it == mapContinents.end())
	{
		mapContinents.push_back(newContinent);
		newContinent->SetMap(this);
	}
}

void Map::RemoveContinentFromMap(Continent *continent)
{
	vector<Continent*>::iterator it = find(mapContinents.begin(), mapContinents.end(), continent);
	if (it != mapContinents.end())
	{
		mapContinents.erase(it);
		continent->SetMap(NULL);
	}
}

int Map::GetContinentCount() const
{
	return mapContinents.size();
}

vector<Continent*> Map::GetMapContinents() const
{
	return mapContinents;
}

vector<Country*> Map::GetAllCountries() const
{
	vector<Country*> allC;
	for (int i = 0; i < mapContinents.size(); i++)
	{
		for (int j = 0; j < mapContinents[i]->GetCountries().size(); j++)
		{
			allC.push_back(mapContinents[i]->GetCountries()[j]);
		}
	}
	return allC;
}

int Map::GetCountryCount() const
{
    int count = 0;
    for (int i = 0; i < mapContinents.size(); i++)
    {
        for (int j = 0; j < mapContinents[i]->GetCountries().size(); j++)
        {
            count++;
        }
    }
    return count;
    
}

Continent::Continent(string name, int armiesPerTurn) : continentName(name), numberOfArmiesPerTurn(armiesPerTurn), map(NULL)
{
}

Continent::~Continent()
{
    for (vector<Country*>::iterator it = continentCountries.begin(); it != continentCountries.end(); it++)
    {
        delete *it;
        *it = NULL;
    }
    
    continentCountries.clear();
}

string Continent::GetName() const
{
    return continentName;
}

void Continent::SetName(string name)
{
    continentName = name;
    
    Allert();
}

void Continent::AddCountry(Country *newCountry)
{
    assert(newCountry != NULL);
    
    if (!ContainsCountry(newCountry) && !newCountry->BelongsToAContinent())
    {
        continentCountries.push_back(newCountry);
        newCountry->SetContinent(this);
        
        Allert();
    }
}

int Continent::GetCountryCount() const
{
    return continentCountries.size();
}

bool Continent::ContainsCountry(Country *country)
{
    vector<Country*>::iterator it = find(continentCountries.begin(), continentCountries.end(), country);
    
    return it != continentCountries.end();
}

void Continent::SetMap(Map *newMap)
{
    if (map == NULL)
    {
        map = newMap;
    }
}

int Continent::GetNumberOfArmiesPerTurn() const
{
    return numberOfArmiesPerTurn;
}

void Continent::SetNumberOfArmiesPerTurn(int armiesPerTurn)
{
    numberOfArmiesPerTurn = armiesPerTurn;
    
    Allert();
}

vector<Country*> Continent::GetCountries() const
{
    return continentCountries;
}

void Continent::Allert()
{
    if (map != NULL)
    {
        //here we will notify the map to update its changes?
    }
}


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
