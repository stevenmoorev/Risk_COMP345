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

void BenevolentStrategy::reinforce(Player *p1){
    //reinforce weak countries
    //look at all countries to see
    //which ones are weak?
    int array[p1->getCountries().size()];
    for(int i =0; i < p1->getCountries().size() - 1 ; i++){
        //this will look how many armies each country has
        //put in the array
        array[i] = p1->getCountries()[i]->getNumberOfArmies();
    }
    //return position of the minimum in the array
    
    int index = 0;
    
    for(int i = 0; i < p1->getCountries().size() - 1; i++){
        if(array[i] < array[index] )
            index = i;
    }
    cout << "reinforce on country " << p1->getCountries()[index] << endl;
}


void BenevolentStrategy::attack(Player *p1){
    //never attack
}


void BenevolentStrategy::fortify(Player *p1){
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
    
    
}
