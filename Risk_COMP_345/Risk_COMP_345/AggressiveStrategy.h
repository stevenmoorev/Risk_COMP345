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
#include "SubjectPhase.h"

using namespace std;

class AggressiveStrategy : public Strategy, SubjectPhase{
public:
    AggressiveStrategy();
    ~AggressiveStrategy();
    std::string const getStrategyName() {return "Aggressive";}
	//void AlgorithmInterface() { cout << "Inside AggressiveStrategy::AlgorithmInterface()\n"; }


    //void setStrategy();
    //aggressive player focusses on attack
    void reinforce(Player* p1) override;
    
    void attack(Player* p1) override;
    
    void fortify(Player* p1) override;

	int compareThrownDicesAtt(vector<int> attDicesRolled, vector<int> defDicesRolled);
	int compareThrownDicesDef(vector<int> attDicesRolled, vector<int> defDicesRolled);
};
#endif /* AggressiveStrategy_hpp */