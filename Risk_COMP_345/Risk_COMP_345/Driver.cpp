#include "Game.h"
#include "AggressiveStrategy.h"
#include "BenevolentStrategy.h"
#include "Strategy.h"
int main() {
	Game *g = new Game();
	g->startGameLoop();
}