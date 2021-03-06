#ifndef GameStatView_H
#define GameStatView_H
#include "ObserverPhase.h"
#include "Game.h"

class GameStatView : public ObserverPhase {
public:
	GameStatView();
	GameStatView(Game* s);
	~GameStatView();
	void Update();
	void display();
private:
	Game* _subject;
}; 
#endif