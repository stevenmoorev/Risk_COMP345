
#ifndef UserStrategy_hpp
#define UserStrategy_hpp

#include <stdio.h>
#include <string>
#include "Strategy.h"
#include "Player.h"

using namespace std;
//delete previous one
//this class is useless 
class UserStrategy : public Strategy {
public:
	UserStrategy() {};
	~UserStrategy() {};
	std::string const getStrategyName() { return "User"; }
	//void AlgorithmInterface() { cout << "Inside AggressiveStrategy::AlgorithmInterface()\n"; }


	//void setStrategy();
	//aggressive player focusses on attack
	void reinforce(Player* p1);

	void attack(Player* p1);

	void fortify(Player* p1);



	int compareThrownDicesAtt(vector<int> attDicesRolled, vector<int> defDicesRolled);
	int compareThrownDicesDef(vector<int> attDicesRolled, vector<int> defDicesRolled);
};
#endif