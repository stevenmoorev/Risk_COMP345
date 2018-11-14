#pragma once

#include "Continent.h"
#include "Country.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <assert.h>
#include "Map.h"
#include <algorithm>   
#include <vector>
#include <list>

class MapLoader
{
public:
	~MapLoader();
	void Load();
};