//
//  AggressiveStrategy.hpp
//  RISK
//
//  Created by Steven Moore on 2018-11-18.
//  Copyright © 2018 Steven Moore. All rights reserved.
//

#ifndef BenevolentStrategy_hpp
#define BenevolentStrategy_hpp

#include <stdio.h>
#include <string>
#include "Strategy.h"
#include "Player.h"

using namespace std;

class BenevolentStrategy : public Strategy{
public:
    BenevolentStrategy();
    ~BenevolentStrategy();
    //std::string const getStrategy() {return "Benevolent";}
	//void AlgorithmInterface() { cout << "Inside BenevolentStrategy::AlgorithmInterface()\n"; }
 
	//interfaces
    void reinforce(Player* p1);
    
    void attack(Player* p1);
    
    void fortify(Player* p1);
};
#endif /* BenevolentStrategy_hpp */
