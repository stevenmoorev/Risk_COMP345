#include "Tournament.h"

int main() {
	cout << "Please choose tournament (1) or normal game(2)" << endl;
	int i;
	cin >> i;
	if (i == 1) {
		Tournament* t = new Tournament();
		delete t;
		return 0;
	}
	else if (i == 2) {
		Game* g = new Game();
		delete g;
		return 0;
	}
	return 0;
}