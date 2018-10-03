#pragma once
#include <iostream>
#include <vector>
#include <string>
class Continent;
using std::string;
using std::vector;
#ifndef COUNTRY_H_
#define COUNTRY_H_
class Player;
class Country 
{
public:
	Country();
	Country(const string& countryName);
	Country(const string& countryName, const int& numberOfArmies);
	Country(const string& countryName, Player* p, const int& numberOfArmies);
	~Country();
	void setCountryName(const string& name);
	string getCountryName();
	void addNeighbor(Country* country);
	vector<Country*> getNeighbors();
	Country* getNeighbor(const int& index);
	bool isNeighborOf(Country* country);
	void setNumberOfArmies(const int& ammount);
	int getNumberOfArmies();
	void setOwner(Player* player);
	Player* getOwner();
	bool BelongsToAContinent();
	Continent* GetContinent() const;
	void SetContinent(Continent* continent);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();

private:
	string countryName;
	int numberOfArmies;
	vector<Country*> neighbors;
	Player* owner;
	Continent* continent;
	int xPos;
	int yPos;
};

#endif;



