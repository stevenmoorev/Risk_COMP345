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
	string phaseName = _subject->getPhaseName;
	Player* player = _subject->getCurrentPlayer();

	cout << "==========" << endl;
	cout << phaseName << endl;
	cout << "==========" << endl;
	cout << "Player Name: " << player->getName() << endl;
	cout << "Player owned countries: " << player->getCountries.size() << endl;
};
