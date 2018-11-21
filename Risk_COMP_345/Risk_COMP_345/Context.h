include <iostream>
include "Strategy.h"
include "Player.h"

class Context
{
private:
	Strategy * strategy;

public:
	void SetStrategy(Strategy *obj) { strategy = obj; }
	Strategy *GetStrategy(){return strategy;}

	//these functions are actually interfaces
	void reinforce(Player* p1) { strategy->reinforce(Player* p1); }
	void attack(Player* p1) { strategy->attack(Player* p1); }
	void fortify(Player* p1) { strategy->fortify(Player* p1); }
};