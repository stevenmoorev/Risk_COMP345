#include "Continent.h"
#include "Country.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <assert.h>
#include <algorithm>    // std::find_if
#include <vector>
#include <list>
#include "Map.h"

class MapLoader
{
public:
	MapLoader();
	~MapLoader();
	void Load();
    MapLoader(string const &path);
    void setMap(Map* map);
    Map* getMap();
    
private:
    Map* map;
};
