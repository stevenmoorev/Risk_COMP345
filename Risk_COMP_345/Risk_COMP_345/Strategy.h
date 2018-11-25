//
//  Strategy.hpp
//  RISK
//
//  Created by Steven Moore on 2018-11-18.
//  Copyright © 2018 Steven Moore. All rights reserved.
//

#ifndef Strategy_h
#define Strategy_h

#include <stdio.h>
#include <string>
#include <utility>
#include "Player.h"
using namespace std;

class Strategy {
private:
    string strategy;
    
public:
    Strategy();
    ~Strategy();
	virtual std::string const getStrategyName() = 0;
	//virtual void AlgorithmInterface() = 0;

	//interfaces = 0
    virtual string reinforce(Player* p1) = 0;
    virtual void attack(Player* p1) = 0;
    virtual pair <string, int> fortify(Player* p1) = 0;
    
};

#endif 
