#include "SubjectPhase.h"
#include "ObserverPhase.h"

SubjectPhase::SubjectPhase() {
	_ObserverPhase = new list<ObserverPhase*>;
}
SubjectPhase::~SubjectPhase() {
	delete _ObserverPhase;
}
void SubjectPhase::Attach(ObserverPhase* o) {
	_ObserverPhase->push_back(o);
};
void SubjectPhase::Detach(ObserverPhase* o) {
	_ObserverPhase->remove(o);
};
void SubjectPhase::Notify() {
	list<ObserverPhase *>::iterator i = _ObserverPhase->begin();
	for (; i != _ObserverPhase->end(); ++i)
		(*i)->Update();
};