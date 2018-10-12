#pragma once
#include <stdio.h>
#include <vector>
#include "Country.h"
class Continent;
class Map 
{
public:
	Map();
	~Map();
	void AddContinentToMap(Continent* newContinent);
	void RemoveContinentFromMap(Continent* continent);
	int GetContinentCount() const;
	int GetCountryCount() const;
	std::vector<Continent*> GetMapContinents() const;
	std::vector<Country*> GetAllCountries() const;

	//probably should have some kind of display method?

private:
	std::vector<Continent*> mapContinents;
};