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

using namespace std;

class BenevolentStrategy : public Strategy{
public:
    BenevolentStrategy();
    ~BenevolentStrategy();
    std::string getStrategy() {return "Benevolent";}
    
    //aggressive player focusses on attack
    void attack(Player* p1, Player* p2);
};
#endif /* BenevolentStrategy_hpp */
