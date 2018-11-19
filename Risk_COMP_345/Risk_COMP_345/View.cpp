#include "View.h"
#include "Game.h"
#include <iostream>
using namespace std;

View::View() {
};

View::View(Game* s) {
	//Upon instantiation, attaches itself to a ClockTimer
	_subject = s;
	_subject->Attach(this);
};
View::~View() {
	//Upon destruction, detaches itself from its ClockTimer      
	_subject->Detach(this);
};
void View::Update() {
	display();
};
void View::display() {
	string phaseName = _subject->getPhaseName();
	Player* player = _subject->getCurrentPlayer();

	cout << "====================VIEW OBSERVER====================" << endl;
	cout << phaseName << endl;
	cout << "Player Name: " << player->getName() << endl;
	cout << "Player owned countries: "<< player->getCountries().size() <<endl;
	cout << "=====================================================" << endl;
	vector<Player*> players = _subject->getPlayers();
	int numOfCountries = _subject->getWorldMap()->GetAllCountries().size();
	cout << "====================Game Statistics===================" << endl;
	cout << "Number of Players in the game:" << players.size() << endl;
	for (int i = 0; i < players.size(); i++) {
		cout << "Player " << i + 1 << "has " << players[i]->getCountries().size() << " countries. This is equal to " << (double)players[i]->getCountries().size() / (double)numOfCountries * 100 << " percent of the world map." << endl;
	}
	cout << "=====================================================" << endl;
};
