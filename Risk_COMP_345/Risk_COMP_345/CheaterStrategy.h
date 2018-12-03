#ifndef CheaterStrategy_hpp
#define CheaterStrategy_hpp

#include <stdio.h>
#include <string>
#include "Strategy.h"
#include "Player.h"

using namespace std;

class CheaterStrategy : public Strategy {
public:
	CheaterStrategy();
	~CheaterStrategy();
	std::string const getStrategyName() { return "Random"; }
	void reinforce(Player* p1) override;

	void attack(Player* p1) override;

	void fortify(Player* p1) override;
};
#endif /* RandomStrategy_hpp */