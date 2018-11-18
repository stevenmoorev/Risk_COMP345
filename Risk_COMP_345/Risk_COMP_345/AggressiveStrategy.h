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
#include "Player.h"

using namespace std;

class AggressiveStrategy : public Strategy{
public:
    AggressiveStrategy();
    ~AggressiveStrategy();
    //std::string getStrategy() {return "Aggressive";}
    //void setStrategy();
    //aggressive player focusses on attack
    void reinforce(Player* p1);
    
    void attack(Player* p1);
    
    void fortify(Player* p1);
};
#endif /* AggressiveStrategy_hpp */
