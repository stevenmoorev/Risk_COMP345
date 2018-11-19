#ifndef ObserverPhase_H
#define ObserverPhase_H
#include <string>
#include <vector>
#include "Player.h"
#include "Map.h"
#include "MapLoader.h"
#include <string>
using namespace std;

#pragma once
#include "Player.h"

class ObserverPhase {
public:
	~ObserverPhase();
	virtual void Update() = 0;
protected:
	ObserverPhase();
};
#endif