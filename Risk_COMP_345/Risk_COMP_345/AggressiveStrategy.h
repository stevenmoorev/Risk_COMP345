//
//  AggressiveStrategy.hpp
//  RISK
//
//  Created by Steven Moore on 2018-11-18.
//  Copyright © 2018 Steven Moore. All rights reserved.
//

#ifndef AggressiveStrategy_hpp
#define AggressiveStrategy_hpp

#include <stdio.h>
#include <string>
#include "Strategy.h"

using namespace std;

class AggressiveStrategy : public Strategy{
public:
    AggressiveStrategy();
    ~AggressiveStrategy();
    std::string getStrategy() {return "Aggressive";}
    
    //aggressive player focusses on attack
    void attack(Player* p1, Player* p2);
};
#endif /* AggressiveStrategy_hpp */
