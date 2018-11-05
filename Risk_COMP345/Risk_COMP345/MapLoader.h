//#include "Continent.h"
//#include "Country.h"
#include "Map.h"
#include <iostream>
#include <fstream>
#include <sstream>


class MapLoader
{
public: 
	MapLoader();
	~MapLoader();
	Map Load();
};
