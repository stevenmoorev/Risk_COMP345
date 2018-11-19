//
//  Strategy.hpp
//  RISK
//
//  Created by Steven Moore on 2018-11-18.
//  Copyright © 2018 Steven Moore. All rights reserved.
//

#ifndef Strategy_hpp
#define Strategy_hpp

#include <stdio.h>
#include <string>
//#include "Game.h"
using namespace std;

class Strategy {
private:
    string strategy;
    
public:
    Strategy();
    ~Strategy();
    string getStrategy(){return strategy;};
    void setStrategy(string st){strategy = st;};
    void reinforce();
    void attack();
    void fortify();
    //reinforcement phase
    //void reinforcementStrategy();
    //attack phase
    //void attackStrategy();
    //fortification phase
    //void fortificationStrategy();
};

#endif /* Strategy_hpp */
