//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include "Dice.h"
//using namespace std;
//
//
//int main() {
//	srand(time(0));
//
//	Dice diceObject1;
//	Dice diceObject2;
//
//	cout << "Throw 2 dice:" << endl;
//
//	for (int result : diceObject1.throwDice(2)) {
//		cout << result << endl;
//	}
//
//	cout << "\nThrow 3 dice:" << endl;
//
//	for (int result : diceObject2.throwDice(3)) {
//		cout << result << endl;
//	}
//
//	cout << "\ndiceObject1 history:" << endl;
//	diceObject1.printdiceNumberCount();
//
//	int loopCount = 1000;
//
//	while (loopCount > 0) {
//		diceObject2.throwDice(3);
//		loopCount--;
//	}
//
//	cout << "\ndiceObject2 history after 3000 dice throws:" << endl;
//	diceObject2.printdiceNumberCount();
//
//	return 0;
//}