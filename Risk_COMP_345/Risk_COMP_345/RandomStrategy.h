//
//  RandomStrategy.hpp
//  RISK
//
//  Created by Steven Moore on 2018-11-18.
//  Copyright © 2018 Steven Moore. All rights reserved.
//

#ifndef RandomStrategy_hpp
#define RandomStrategy_hpp

#include <stdio.h>
#include <string>
#include "Strategy.h"
#include "Player.h"

using namespace std;

class RandomStrategy : public Strategy{
public:
    RandomStrategy();
    ~RandomStrategy();
    std::string const getStrategy() {return "Random";}
    string reinforce(Player* p1);
    
    void attack(Player* p1);
    
    void fortify(Player* p1);
	int compareThrownDicesAtt(vector<int> attDicesRolled, vector<int> defDicesRolled);
	int compareThrownDicesDef(vector<int> attDicesRolled, vector<int> defDicesRolled);
};
#endif /* RandomStrategy_hpp */