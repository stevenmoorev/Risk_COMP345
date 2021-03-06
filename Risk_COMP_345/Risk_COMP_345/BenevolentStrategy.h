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
#include "SubjectPhase.h"
using namespace std;


class BenevolentStrategy : public Strategy, SubjectPhase{
public:
    BenevolentStrategy();
    ~BenevolentStrategy();
    std::string const getStrategyName() {return "Benevolent";}
	//void AlgorithmInterface() { cout << "Inside BenevolentStrategy::AlgorithmInterface()\n"; }
 
	//interfaces
    void reinforce(Player* p1) override;
    
    void attack(Player* p1) override;
    
    void fortify(Player* p1) override;
};
#endif /* BenevolentStrategy_hpp */
