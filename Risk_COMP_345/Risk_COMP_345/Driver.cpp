#include "Game.h"
#include "AggressiveStrategy.h"
#include "BenevolentStrategy.h"
#include "Strategy.h"
int main() {
	//Game *g = new Game();
	//g->setup();

	//this is the context
	Player *p1 = new Player();
	Player *p2 = new Player();

	//(1) different players can be assigned different strategies that lead to different 
	// behavior for the reinforcement, attack, and fortification phases using the strategy pattern; 
	
	AggressiveStrategy *as = new AggressiveStrategy();
	BenevolentStrategy *bs = new BenevolentStrategy();
	
	p1->setStrategy(as);
	p1->getStrategy()->reinforce(p1);
	p1->getStrategy()->fortify(p1);
	p1->getStrategy()->attack(p1);
	
	
	p2->setStrategy(bs);
	p2->getStrategy()->reinforce(p1);
	p2->getStrategy()->fortify(p1);
	p2->getStrategy()->attack(p1);


	//(2) the strategy adopted by a player can be changed dynamically during play, 




	//(3) the human player makes decisions according to user
	//interaction, and computer players make decisions automatically, 
	//which are both implemented using the strategy
	//pattern.



}