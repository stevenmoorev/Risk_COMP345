//
//  StrategyPatternDriver.cpp
//  RISK
//
//  Created by Steven Moore on 2018-11-18.
//  Copyright © 2018 Steven Moore. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include "Game.h"
#include "AggressiveStrategy.h"
#include "BenevolentStrategy.h"

using namespace std;

//int main() {
//    Game* g = new Game();
//    g->setup();
//    
//    //Strategy* st = new Strategy();
//    AggressiveStrategy* as = new AggressiveStrategy();
//    BenevolentStrategy* bs = new BenevolentStrategy();
//    
//    g->getPlayers()[0]->setStrategy(as);
//    g->getPlayers()[1]->setStrategy(bs);
//    
//    g->startGameLoop();
//    
//    //have to be able to change the strategy
//}
