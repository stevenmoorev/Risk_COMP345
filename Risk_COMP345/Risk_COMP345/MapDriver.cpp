#include "Map.h"
#include "Country.h"
#include "Continent.h"
#include <iostream>

using namespace std;

int main() 
{
	string i;
	Country* c1 = new Country("first");
	Country* c2 = new Country("second");
	Country* c3 = new Country("third");
	Country* c4 = new Country("fourth");
	Country* c5 = new Country("fifth");
	Country* c6 = new Country("sixth");
	Continent* con1 = new Continent("Big Continent");
	cout << "Here are the five countries we are working with: "<<endl;
	cout << c1->getCountryName()+", "+c2->getCountryName()+", "+c3->getCountryName() + ", " + c4->getCountryName() + ", " + c5->getCountryName()<<endl;
	con1->AddCountry(c1);
	c1->addNeighbor(c2);
	c1->addNeighbor(c4);
	con1->AddCountry(c5);
	c2->addNeighbor(c1);
	c2->addNeighbor(c5);
	c2->addNeighbor(c3);
	con1->AddCountry(c3);
	c3->addNeighbor(c2);
	con1->AddCountry(c4);
	c4->addNeighbor(c1);
	con1->AddCountry(c2);
	c5->addNeighbor(c2);

	cout << "Here is the number of countries in our continent called "+con1->GetName()<<endl;
	cout << con1->GetCountryCount()<<endl;
	cout << "these countries are in order added:";
	vector<Country*> countriesInCon1 = con1->GetCountries();
	for(int i = 0; i<countriesInCon1.size();i++) 
	{
		cout << countriesInCon1[i]->getCountryName()<<endl;
	}

	cout << "each country and its neighbors:" << endl;
	for (int i = 0; i < countriesInCon1.size(); i++)
	{
		cout << "country name: " << countriesInCon1[i]->getCountryName() << endl;
		cout << "neighbors:" << endl;
		for (int j = 0; j < countriesInCon1[i]->getNeighbors().size(); j++) 
		{
			cout << countriesInCon1[i]->getNeighbors()[j]->getCountryName()<<", ";
		}
		cout << endl;
	}
	cout << "map is a connected graph!" << endl;
	cout << "Move third to a new continent called Small Continent" << endl;
	Continent* con2 = new Continent("Small Continent");
	con2->AddCountry(c3);
	cout << "this should not have worked." << endl;
	cout << "continent size: " << con2->GetCountryCount() << endl;
	cout << "third's continent: " << c3->GetContinent()->GetName() << endl;
	cout << "country can only be in one continent!" << endl;
	cout << "now we can add a country called sixth to this new continent"<<endl;
	con2->AddCountry(c6);
	c5->addNeighbor(c6);
	c6->addNeighbor(c5);
	cout << "Small continent size: ";
	cout << con2->GetCountryCount() << endl;
	Map* myMap = new Map();
	myMap->AddContinentToMap(con1);
	myMap->AddContinentToMap(con2);
	cout << "continents in map:" << endl;
	for (int i = 0; i < myMap->GetMapContinents().size(); i++) 
	{
		cout << "continent " << myMap->GetMapContinents()[i]->GetName() << " is in map." << endl;
	}
	cout << "map contains the following countries:";
	for (int i = 0; i < myMap->GetAllCountries().size(); i++) 
	{
		cout << myMap->GetAllCountries()[i]->getCountryName()<<", ";
	}
	cout << "sixth's neighbors: ";
	for (int j = 0; j < c6->getNeighbors().size(); j++)
	{
		cout << c6->getNeighbors()[j]->getCountryName() << ", ";
	}
	cout << endl;
	cout << "fifth's neighbors: ";
	for (int j = 0; j < c5->getNeighbors().size(); j++)
	{
		cout << c5->getNeighbors()[j]->getCountryName() << ", ";
	}
	cout << endl;
	cout << "Input any string to end.";
	cin >> i;
	return 0;
}