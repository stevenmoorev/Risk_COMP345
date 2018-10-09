#include <assert.h>
#include "MapLoader.h"
#include <fstream>
#include <sstream>
#include "Continent.h"
#include "Country.h"
#include "Map.h"
using namespace std;
using std::cin;
using std::cout;
using std::getline;
std::string STRING;
std::ifstream in;


Map Load() {
	string junk;
	string continentName;
	string countryName;
	string score;
	int x,y;
	const char flag = '\n';
	//input of map file location
	in.open("C://Users/pcabr/Downloads/Aden/Aden.map");
	//skipping unecessary map info
	for (int a = 0; a < 8; a = a + 1) {
		getline(in, junk, '\n');
	}
	
	//vector to continents
	vector<Continent*> continents;
	while (in.peek() != flag)
	{
		getline(in, continentName, '=');
		continents.push_back(new Continent(continentName, 5));
		getline(in,score, '\n');
		cout << continentName + "\n";
		cout << score + "\n";	
	}
	cout << continents.size();
	cout << "\n";
	
	vector<Country*> countries;
	vector<Country*> neighbors;
	int c = 0;
	int o = 0;
	//skip 2 unecessary 
	getline(in, junk, '\n');
	getline(in, junk, '\n');
	while (!in.eof())
	{
		if (in.peek() != flag && in.peek() != -1)
		{
			getline(in, countryName, ',');
			//Country country;
			//country.setCountryName(countryName);
			//cout << country.getCountryName();

			auto it = std::find(neighbors.begin(), neighbors.end(), new Country(countryName));
			//if the country is not already created in the neighbor vector
			if (it == neighbors.end())
			{
				countries.push_back(new Country(countryName));
				//countries[c]
				cout << countries[c]->getCountryName();
				cout << "\n";
				in >> x;
				//country.setX(x);
				countries[c]->setX(x);
				in.get();
				in >> y;
				countries[c]->setY(y);
				//country.setY(y);
				//cout << country.getY();
				in.get();
				cout << "\n";
				//country.SetContinent(continent);
				//find continent that country belongs to in the continents vector
				//country.SetContinent(desired continent)

				//vector<Country*> Country.SetContient(Continent);
				getline(in, continentName, ',');
				//Map map;
				for (unsigned int i = 0; i < continents.size(); i++)
				{
					if (continentName == continents[i]->GetName())
					{
						cout << "\n";
						cout << "Continent name ";
						cout << continents[i]->GetName();
						cout << "Continent SIZE + object ID: ";
						cout << continents[i];
						//continents[i]->SetMap(&map);
						cout << "\n";
						//	country.SetContinent((continents[i]));
						continents[i]->AddCountry(countries[c]);
						cout << "Country memory address:" << countries[c];
						//cout << "Country memory address:" << &country;
						//cout << country.BelongsToAContinent();
						// country count =1 ????????
						cout << continents[i]->ContainsCountry(countries[c]);
						//	cout << continents[i]->ContainsCountry(&country);
						cout << continents[i]->GetCountryCount() + " HERE \n";
					}
				}
				//********************************setting neighbors, BUT SEEMS TO BE NOT WORKING PERFECTLY
				getline(in, countryName, flag);
				std::istringstream string(countryName);
				std::string neighbor;
				while (std::getline(string, neighbor, ',')) {
					cout << "neigbor: ";
					cout << neighbor;
					cout << "\n";
					neighbors.push_back(new Country(neighbor));
					//Country country1;
					neighbors[o]->setCountryName(neighbor);
					countries[c]->addNeighbor(neighbors[o]);
					o = o + 1;
					//country.addNeighbor(&country1);
					//}
					//if(continentName == continent.getName()){   country.setContinent(continent)     }
				}
				cout << "\n";
				c = c + 1;
			}

			else {
				auto index = std::distance(neighbors.begin(), it);
				cout << neighbors[index]->getCountryName();
				cout << "\n";
				in >> x;
				//country.setX(x);
				neighbors[index]->setX(x);
				in.get();
				in >> y;
				neighbors[index]->setY(y);
				//country.setY(y);
				//cout << country.getY();
				in.get();
				cout << "\n";
				//country.SetContinent(continent);
				//find continent that country belongs to in the continents vector
				//country.SetContinent(desired continent)

				//vector<Country*> Country.SetContient(Continent);
				getline(in, continentName, ',');
				//Map map;
				for (unsigned int i = 0; i < continents.size(); i++)
				{
					if (continentName == continents[i]->GetName())
					{
						cout << "\n";
						cout << "Continent name ";
						cout << continents[i]->GetName();
						cout << "Continent SIZE + object ID: ";
						cout << continents[i];
						//continents[i]->SetMap(&map);
						cout << "\n";
						//	country.SetContinent((continents[i]));
						continents[i]->AddCountry(neighbors[index]);
						cout << "Country memory address:" << countries[c];
						//cout << "Country memory address:" << &country;
						//cout << country.BelongsToAContinent();
						// country count =1 ????????
						cout << continents[i]->ContainsCountry(neighbors[index]);
						//	cout << continents[i]->ContainsCountry(&country);
						cout << continents[i]->GetCountryCount() + " HERE \n";
					}
				}
				//********************************setting neighbors, BUT SEEMS TO BE NOT WORKING PERFECTLY
				getline(in, countryName, flag);
				std::istringstream string(countryName);
				std::string neighbor;
				while (std::getline(string, neighbor, ',')) {
					cout << "neigbor: ";
					cout << neighbor;
					cout << "\n";
					neighbors.push_back(new Country(neighbor));
					//Country country1;
					neighbors[o]->setCountryName(neighbor);
					neighbors[index]->addNeighbor(neighbors[o]);
					o = o + 1;
					//country.addNeighbor(&country1);
					//}
					//if(continentName == continent.getName()){   country.setContinent(continent)     }
				}
				cout << "\n";
			}
			}
		 else 
		{
			in.get();
		}
			
	}

	Map map;
	for (unsigned int i = 0; i < continents.size(); i++)
	{
		{	
			//cout << continents[i]->GetCountryCount() + "\n";
			map.AddContinentToMap(continents[i]);
			//cout << "FLAG1";
			//cout << "\n";
		}
	}
	cout << map.GetContinentCount();
	cout << "\n";
	//vector<Country*>Map2= map.GetAllCountries();
	//****************************************trying to verify how many countries are part of each continent which currently gives 1 
	for (unsigned int x = 0; x < map.GetMapContinents().size(); x++) {
		cout << map.GetMapContinents()[x]->GetCountryCount();
		cout << "\n";
		cout << "FLAG2 + \n";
	}
	cout << continents[1]->ContainsCountry(countries[7]);
	cout << continents[7]->ContainsCountry(countries[40]);
	cout << countries[0]->isNeighborOf(neighbors[4]);
	//vector<Country*> GetCountries() const;
	system("pause");
	return map;
}
int main(){
	Load();
}