#pragma once
#include "ObserverPhase.h"
#include "Game.h"

class View : public ObserverPhase {
public:
	View();
	View(Game* s);
	~View();
	void Update();
	void display();
private:
	Game *_subject;
};
