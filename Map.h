#pragma once
#include <stdio.h>
#include <vector>

class Map
{
public:
    Map();
    ~Map();
    void AddContinentToMap(Continent* newContinent);
    void RemoveContinentFromMap(Continent* continent);
    int GetContinentCount() const;
    std::vector<Continent*> GetMapContinents() const;
    std::vector<Country*> GetAllCountries() const;
    int GetCountryCount() const
    
    //probably should have some kind of display method?
    
private:
    std::vector<Continent*> mapContinents;
};

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
    void SetMap(Map* map);
    int GetNumberOfArmiesPerTurn() const;
    void SetNumberOfArmiesPerTurn(int numOfArmiesPerTurn);
    void Allert(); //continent state changed
    std::vector<Country*> GetCountries() const;
    
private:
    std::string continentName;
    int numberOfArmiesPerTurn;
    std::vector<Country*> continentCountries;
    Map* map;
};

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
    
private:
    string countryName;
    int numberOfArmies;
    vector<Country*> neighbors;
    Player* owner;
    Continent* continent;
};


