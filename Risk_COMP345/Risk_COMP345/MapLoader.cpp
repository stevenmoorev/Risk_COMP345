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
	//skip 2 unecessary lines
	getline(in, junk, '\n');
	getline(in, junk, '\n');
	while (!in.eof())
	{
		if (in.peek() != flag && in.peek() != -1)
		{
			getline(in, countryName, ',');
			Country country;
			country.setCountryName(countryName);
			cout << country.getCountryName();
			cout << "\n";
			in >> x;
			country.setX(x);
			in.get();
			in >> y;
			country.setY(y);
			cout << country.getY();
			in.get();
			cout << "\n";
			//country.SetContinent(continent);
			//find continent that country belongs to in the continents vector
			//country.SetContinent(desired continent)

			//vector<Country*> Country.SetContient(Continent);
			getline(in, continentName, ',');
			
			for (unsigned int i = 0; i < continents.size(); i++)
			{
				if (continentName == continents[i]->GetName())
				{
					cout << "\n";
					cout << "Continent name ";
					cout << continents[i]->GetName();
					cout << "Continent SIZE ";
					cout << continents.size();
					cout << "\n";
				//	country.SetContinent((continents[i]));
					continents[i]->AddCountry(&country);
					//cout << country.BelongsToAContinent();
					cout << continents[i]->ContainsCountry(&country);
					cout << continents[i]->GetCountryCount() + "HERE \n";
				}
			}
//********************************setting neighbors, BUT SEEMS TO BE NOT WORKING PERFECTLY
			getline(in, countryName, flag);
			std::istringstream string(countryName);
			std::string neighbor;
			while (std::getline(string, neighbor, ',')) {
				cout << neighbor;
				cout << "\n";
				Country country1;
				country1.setCountryName(neighbor);
				country.addNeighbor(&country1);
				//}
				//if(continentName == continent.getName()){   country.setContinent(continent)     }
			}
			cout << "\n";
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
			cout << continents[i]->GetCountryCount() + "\n";
			map.AddContinentToMap(continents[i]);
			//cout << "FLAG1";
			cout << "\n";
		}
	}
	cout << map.GetContinentCount();
	//vector<Country*>Map2= map.GetAllCountries();
//****************************************trying to verify how many countries are part of each continent which currently gives 1 
	for (unsigned int x = 0; x < map.GetMapContinents().size(); x++) {
		cout << map.GetMapContinents()[x]->GetCountryCount();
		cout << "\n";
		//cout << "FLAG + \n";
	}
	//vector<Country*> GetCountries() const;
	system("pause");
	return map;
}
int main(){
	Load();
}