#pragma once
#include <stdio.h>
#include <vector>
#include <string>
class Country;
class Map;
class Continent
{
public:
	Continent(std::string continentName, int numberOfArmiesPerTurn = 0);
	~Continent();
	std::string GetName() const;
	void SetName(std::string continentNname);
	void AddCountry(Country* newCountry);
	int GetCountryCount() const;
	bool ContainsCountry(Country* country); //is the country in this continent?
	//void SetMap(Map* map);
	int GetNumberOfArmiesPerTurn() const;
	void SetNumberOfArmiesPerTurn(int numOfArmiesPerTurn);
	//void Allert(); //continent state changed
	std::vector<Country*> GetCountries() const;

private:
	std::string continentName;
	int numberOfArmiesPerTurn;
	std::vector<Country*> continentCountries;
	//Map* map;
};