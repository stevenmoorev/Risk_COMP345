#include "MapLoader.h"
using namespace std;
using std::cin;
using std::cout;
using std::getline;
using std::find_if;
std::string STRING;
std::ifstream in;
//graph implementation
class Graph
{
	int V;    // No. of vertices 

	// Pointer to an array containing 
	// adjacency lists 
	list<int> *adj;

	// A recursive function used by DFS 

public:
	Graph(int V);   // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, int w);
	void DFSUtil(int v, bool visited[]);
	// DFS traversal of the vertices 
	// reachable from v 
	bool DFS(int v);
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list. 
}

void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and 
	// print it 
	visited[v] = true;
	//cout << v << " ";

	// Recur for all the vertices adjacent 
	// to this vertex 
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i) {
		if (!visited[*i])
			DFSUtil(*i, visited);
	}
}

// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
bool Graph::DFS(int v)
{
	bool connected = true;
	// Mark all the vertices as not visited 
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function 
	// to print DFS traversal 
	DFSUtil(v, visited);
	//trying to get a boolean for a not connected graph
	for (unsigned int a = 0; a < sizeof(visited) / sizeof(visited[0]); a = a + 1) {
		if (visited[a] == false) {
			connected = false;
		}
	}
	return connected;
}


Map MapLoader(string const &path) {
	string junk;
	string continentName;
	string countryName;
	string score;
	int x, y;
	const char flag = '\n';
	//input of map file location
	in.open(path);
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
		getline(in, score, '\n');
		//cout << continentName + "\n";
		//cout << score + "\n";
	}
	//cout << continents.size();

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
			auto it = find_if(neighbors.begin(), neighbors.end(), [&](Country* n) {return n->getCountryName() == countryName;});
			//auto it = find_if(neighbors.begin(), neighbors.end(), [&](Country& n) -> bool {return n.getCountryName() == countryName;});
			//if the country is not already created in the neighbor vector, create a new country for it
			if (it == neighbors.end())
			{
				countries.push_back(new Country(countryName));
				//countries[c]
				//cout << countries[c]->getCountryName() <<endl;
				in >> x;
				//country.setX(x);
				countries[c]->setX(x);
				in.get();
				in >> y;
				countries[c]->setY(y);
				//country.setY(y);
				//cout << country.getY()<<endl;
				in.get();
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
						//cout << "Continent name ";
						//cout << continents[i]->GetName();
						//cout << "Continent SIZE + object ID:   " << continents[i] <<endl;
						//continents[i]->SetMap(&map);
						//	country.SetContinent((continents[i]));
						continents[i]->AddCountry(countries[c]);
						//cout << "Country memory address:" << countries[c] << endl;
						//cout << "Country memory address:" << &country;
						//cout << country.BelongsToAContinent();
						// country count =1 ????????
						//cout << "#of countries "<< continents[i]->ContainsCountry(countries[c]);
						//	cout << continents[i]->ContainsCountry(&country);
						//cout << continents[i]->GetCountryCount() << endl;
					}
				}
				//setting neighbors
				getline(in, countryName, flag);
				std::istringstream string(countryName);
				std::string neighbor;
				while (std::getline(string, neighbor, ',')) {
					//cout << "neigbor: ";
					//cout << neighbor << endl;
					//auto io = std::find(neighbors.begin(), neighbors.end(), new Country(neighbor)); 
					auto it1 = find_if(neighbors.begin(), neighbors.end(), [&](Country* n) {return n->getCountryName() == neighbor;});
					auto it9 = find_if(countries.begin(), countries.end(), [&](Country* n) {return n->getCountryName() == neighbor;});
					if (it1 != neighbors.end()) {
						auto index1 = std::distance(neighbors.begin(), it1);
						countries[c]->addNeighbor(neighbors[index1]);
						//c = c + 1;
					}
					else if (it9 != countries.end()) {
						auto index9 = std::distance(countries.begin(), it9);
						neighbors[c]->addNeighbor(countries[index9]);
					}
					else {
						neighbors.push_back(new Country(neighbor));
						//Country country1;
						neighbors[o]->setCountryName(neighbor);
						countries[c]->addNeighbor(neighbors[o]);
						o = o + 1;
					}
					//country.addNeighbor(&country1);
					//}
					//if(continentName == continent.getName()){   country.setContinent(continent)     }
				}

				c = c + 1;
			}
			//the country object was already created as an neighbor; hence use it from the neighbors stack
			else {
				int index5 = std::distance(neighbors.begin(), it);
				//cout << neighbors[index5]->getCountryName();
				in >> x;
				//country.setX(x);
				neighbors[index5]->setX(x);
				in.get();
				in >> y;
				neighbors[index5]->setY(y);
				//country.setY(y);
				//cout << country.getY();
				in.get();
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
						//cout << "Continent name ";
						//cout << continents[i]->GetName();
						//cout << "Continent SIZE + object ID:  ";
						//cout << continents[i] << endl;
						//continents[i]->SetMap(&map);
						//	country.SetContinent((continents[i]));
						continents[i]->AddCountry(neighbors[index5]);
						//cout << "Country memory address:" << neighbors[index5];
						//cout << "Country memory address:" << &country;
						//cout << country.BelongsToAContinent();
						// country count =1 ????????
						//cout << continents[i]->ContainsCountry(neighbors[index5]);
						//	cout << continents[i]->ContainsCountry(&country);
						//cout << "# of countries" << continents[i]->GetCountryCount() << endl;

					}
				}
				//setting neighbors
				getline(in, countryName, flag);
				std::istringstream string(countryName);
				std::string neighbor;
				while (std::getline(string, neighbor, ',')) {
					//cout << "neigbor: ";
					//cout << neighbor << endl;
					//auto ii = std::find(neighbors.begin(), neighbors.end(), new Country(neighbor));
					auto it2 = find_if(neighbors.begin(), neighbors.end(), [&](Country* n) {return n->getCountryName() == neighbor;});
					auto it3 = find_if(countries.begin(), countries.end(), [&](Country* n) {return n->getCountryName() == neighbor;});
					if (it2 != neighbors.end()) {
						auto index2 = std::distance(neighbors.begin(), it2);
						neighbors[index5]->addNeighbor(neighbors[index2]);
					}
					else if (it3 != countries.end()) {
						auto index3 = std::distance(countries.begin(), it3);
						neighbors[index5]->addNeighbor(countries[index3]);
					}
					else {
						neighbors.push_back(new Country(neighbor));
						//Country country1;
						neighbors[o]->setCountryName(neighbor);
						neighbors[index5]->addNeighbor(neighbors[o]);
						o = o + 1;
					}
				}
				//cout << "\n";
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
	//cout << "# of continents in map: "<< map.GetContinentCount();
	//cout << "\n";
	//vector<Country*>Map2= map.GetAllCountries();
	//verify how many countries are part of each continent which currently gives 1 
	bool countryPerContinent = true;
	for (unsigned int x = 0; x < map.GetMapContinents().size(); x++) {
		//cout <<" # of countries per continent: " << map.GetMapContinents()[x]->GetCountryCount() << endl;
		if (map.GetMapContinents()[x]->GetCountryCount() <= 0) {
			bool countryPerContinent = false;
		};
	}
	//*cout << continents[1]->ContainsCountry(countries[7]);
	//cout << continents[7]->ContainsCountry(countries[40]);

	//THIS SHOULD BE TRUE
	//cout <<"neighbors? :"<<  countries[0]->isNeighborOf(neighbors[4]) << endl;
	//cout << "neighbors? :" << neighbors[4]->isNeighborOf(countries[0]) << endl;
	//cout << neighbors[4]->getCountryName ()<< endl;
	//cout << countries[0]->getCountryName ()<< endl;
	//cout << map.GetCountryCount();

	//graph construction
	Graph countriesConnection(map.GetCountryCount());
	for (unsigned int x = 0; x < map.GetAllCountries().size(); x++) {

		vector<Country*> v = map.GetAllCountries();

		auto it69 = find_if(v.begin(), v.end(), [&](Country* n) {return n->getCountryName() == v[x]->getCountryName();});
		auto index69 = std::distance(v.begin(), it69);

		vector<Country*> y = v[index69]->getNeighbors();		//g.addEdge(index69, 1);

		for (unsigned int w = 0; w < y.size(); w++) {
			//cout << y[w]->getCountryName() << endl;
			countriesConnection.addEdge(index69, w);
			countriesConnection.addEdge(w, index69);
		}
	}
	if (countryPerContinent == true && countriesConnection.DFS(0)) {
		cout << "Map Created" << endl;
		return map;
	}
	else {
		cout << "The provided map doesn't fit the game requirements" << endl;
	}
}
int main() {
	string path1 = "C:/Users/pcabr/Downloads/countries-unconnected.map";
	MapLoader(path1);
}
