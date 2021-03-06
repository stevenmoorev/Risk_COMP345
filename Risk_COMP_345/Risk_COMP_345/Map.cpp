#include "Map.h"
#include "Continent.h"
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
	mapContinents.push_back(newContinent);
}

void Map::RemoveContinentFromMap(Continent *continent)
{
	vector<Continent*>::iterator it = find(mapContinents.begin(), mapContinents.end(), continent);
	if (it != mapContinents.end())
	{
		mapContinents.erase(it);
	}
}

int Map::GetContinentCount() const
{
	return mapContinents.size();
}

int Map::GetCountryCount() const
{
	vector<Country*> c = Map::GetAllCountries();
	return c.size();
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
