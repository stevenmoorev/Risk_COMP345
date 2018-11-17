#pragma once

#include "Continent.h"
#include "Country.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <assert.h>
#include "Map.h"
#include <algorithm>    // std::find_if
#include <vector>
#include <list>

class MapLoader
{
public:
	~MapLoader();
	MapLoader();
	Map* MapLoad(string const & path);
	Map* getMap();

private:
	Map* map;
};