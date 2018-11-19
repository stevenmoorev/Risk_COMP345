#include "GameStatView.h"
#include "Game.h"
#include <iostream>
using namespace std;

GameStatView::GameStatView() {
};

GameStatView::GameStatView(Game* s) {
	//Upon instantiation, attaches itself to a ClockTimer
	_subject = s;
	_subject->Attach(this);
};
GameStatView::~GameStatView() {
	//Upon destruction, detaches itself from its ClockTimer      
	_subject->Detach(this);
};
void GameStatView::Update() {
	display();
};
void GameStatView::display() {
	vector<Player*> players = _subject->getPlayers();
	int numOfCountries = _subject->getWorldMap()->GetAllCountries().size();
	cout << "====================Game Statistics===================" << endl;
	cout << "Number of Players in the game:" << players.size() << endl;
	for (int i = 0; i < players.size(); i++) {
		cout << "Player "<< i+1 << "has " << players[i]->getCountries().size() << " countries. This is equal to " << (double)players[i]->getCountries().size() / (double) numOfCountries * 100 << " percent of the world map." << endl;
	}
	cout << "=====================================================" << endl;
};