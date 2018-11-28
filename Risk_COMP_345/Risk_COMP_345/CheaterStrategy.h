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
	std::string const getStrategy() { return "Random"; }
	void reinforce(Player* p1);

	void attack(Player* p1);

	void fortify(Player* p1);
};
#endif /* RandomStrategy_hpp */