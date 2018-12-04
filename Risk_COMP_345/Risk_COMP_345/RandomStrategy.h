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
#include "SubjectPhase.h"
using namespace std;

class RandomStrategy : public Strategy, SubjectPhase{
public:
    RandomStrategy();
    ~RandomStrategy();
    std::string const getStrategyName() {return "Random";}
	void reinforce(Player* p1) override;
    
    void attack(Player* p1) override;
    
    void fortify(Player* p1) override;
	int compareThrownDicesAtt(vector<int> attDicesRolled, vector<int> defDicesRolled);
	int compareThrownDicesDef(vector<int> attDicesRolled, vector<int> defDicesRolled);
};
#endif /* RandomStrategy_hpp */