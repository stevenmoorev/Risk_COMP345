#ifndef SubjectPhase_H
#define SubjectPhase_H
#pragma once
#include "ObserverPhase.h"
#include "Player.h"
#include <list>
using namespace std;

//Needs to have a forward reference due to 
//circular reference between Observer and Subject
class ObserverPhase;

class SubjectPhase {
public:
	virtual void Attach(ObserverPhase* o);
	virtual void Detach(ObserverPhase* o);
	virtual void Notify();
	SubjectPhase();
	~SubjectPhase();
private:
	list<ObserverPhase*> *_ObserverPhase;
};
#endif
