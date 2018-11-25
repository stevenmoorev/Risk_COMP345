//
//  BenevolentStrategy.cpp
//  RISK
//
//  Created by Steven Moore on 2018-11-18.
//  Copyright © 2018 Steven Moore. All rights reserved.
//

#include <iostream>
#include "BenevolentStrategy.h"

using namespace std;

BenevolentStrategy::BenevolentStrategy(){
    
}

BenevolentStrategy::~BenevolentStrategy(){
    
}

string BenevolentStrategy::reinforce(Player *p1){
	cout << "====STRATEGY====" << endl;
	//reinforce weak countries
    //look at all countries to see
    //which ones are weak?
	vector<int> arr = vector<int>();
    for(int i =0; i < p1->getCountries().size() - 1 ; i++){
        //this will look how many armies each country has
        //put in the array
		arr.push_back(p1->getCountries()[i]->getNumberOfArmies());
    }
    //return position of the minimum in the array
    
    int index = 0;
    
    for(int i = 0; i < p1->getCountries().size() - 1; i++){
        if(arr[i] < arr[index] )
            index = i;
    }
	cout << "reinforce on country " << p1->getCountries()[index]->getCountryName() << endl;
	return p1->getCountries()[index]->getCountryName();
	//how many armies?
	//int bonus = (int)p1->getCountries().size() / 3;
	//cout << bonus << " armies added to " << p1->getCountries()[index]->getCountryName() << endl;
	//for (int i = 0; i < bonus; i++) {
	//	p1->getCountries()[index]->addArmy();
	//}
}


void BenevolentStrategy::attack(Player *p1){
	cout << "====STRATEGY====" << endl;
	cout << " Don't attack" << endl;
	//never attack
}


void BenevolentStrategy::fortify(Player *p1){
	cout << "====STRATEGY====" << endl;
	//move armies to weaker countries
    int indexLargest = 0;
    int indexSmallest = 0;
    
    for(int i = 0; i < p1->getCountries().size() - 1; i++){
        //p1->getCountries()[i]->getNumberOfArmies();
        //one with most armies
        if(p1->getCountries()[i]->getNumberOfArmies() > p1->getCountries()[indexLargest]->getNumberOfArmies())
            indexLargest = i;
    }
    
    for(int i = 0; i < p1->getCountries().size() - 1; i++){
        //p1->getCountries()[i]->getNumberOfArmies();
        //one with most armies
        if(p1->getCountries()[i]->getNumberOfArmies() > p1->getCountries()[indexSmallest]->getNumberOfArmies())
            indexSmallest = i;
    }
    
    cout << "Move armies from " << p1->getCountries()[indexLargest]->getCountryName() << " to " << p1->getCountries()[indexSmallest]->getCountryName() << endl;
    
	int difference = (int)(p1->getCountries()[indexLargest]->getNumberOfArmies() - p1->getCountries()[indexSmallest]->getNumberOfArmies())/2;
	cout << difference << " armies moved" <<endl ;
	for (int i = 0; i < difference; i++) {
		p1->getCountries()[indexLargest]->removeArmy(1);
		p1->getCountries()[indexSmallest]->addArmy();
	}
}
