#include <assert.h>
#include "Continent.h"
#include "Country.h"
#include "Map.h"
using namespace std;
Continent::Continent(string name, int armiesPerTurn) {
	name=continentName;
    armiesPerTurn= numberOfArmiesPerTurn;
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

	//Allert();
}

void Continent::AddCountry(Country *newCountry)
{
	assert(newCountry != NULL);

	if (!ContainsCountry(newCountry) && !newCountry->BelongsToAContinent())
	{
		continentCountries.push_back(newCountry);
		newCountry->SetContinent(this);

//		Allert();
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

/*void Continent::SetMap(Map *newMap)
{
	if (map == NULL)
	{
		map = newMap;
	}
}*/

int Continent::GetNumberOfArmiesPerTurn() const
{
	return numberOfArmiesPerTurn;
}

void Continent::SetNumberOfArmiesPerTurn(int armiesPerTurn)
{
	numberOfArmiesPerTurn = armiesPerTurn;

//	Allert();
}

vector<Country*> Continent::GetCountries() const
{
	return continentCountries;
}

/*void Continent::Allert()
{
	if (map != NULL)
	{
		//here we will notify the map to update its changes?
	}
}*/