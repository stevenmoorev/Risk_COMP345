//
//  AggressiveStrategy.cpp
//  RISK
//
//  Created by Steven Moore on 2018-11-18.
//  Copyright © 2018 Steven Moore. All rights reserved.
//

#include "AggressiveStrategy.h"

AggressiveStrategy::AggressiveStrategy(){
    
}

AggressiveStrategy::~AggressiveStrategy(){
    
}

//aggressive player reinforces to strongest country
void AggressiveStrategy::reinforce(Player *p1){
    //reinforce strongest country
    int indexLargest = 0;
    for(int i = 0; i < p1->getCountries().size() - 1; i++){
        //p1->getCountries()[i]->getNumberOfArmies();
        //one with most armies
        if(p1->getCountries()[i]->getNumberOfArmies() > p1->getCountries()[indexLargest]->getNumberOfArmies())
            indexLargest = i;
    }
    cout << "Reinforce to country " << p1->getCountries()[indexLargest]->getCountryName() << endl;
}

void AggressiveStrategy::attack(Player *p1){
    //attack with strongest country until you cannot anymore
    int indexLargest = 0;
    for(int i = 0; i < p1->getCountries().size() - 1; i++){
        //p1->getCountries()[i]->getNumberOfArmies();
        //one with most armies
        if(p1->getCountries()[i]->getNumberOfArmies() > p1->getCountries()[indexLargest]->getNumberOfArmies())
            indexLargest = i;
    }
    cout << "Attack with country " << p1->getCountries()[indexLargest]->getCountryName() << endl;
    
    //see if any of the neighbours belongs to someone else and attack it
    for(int i = 0; i < p1->getCountries()[indexLargest]->getNeighbors().size(); i++){
        if(p1->getCountries()[indexLargest]->getNeighbors()[i]->getOwner() != p1){
            cout << "You should attack country " << p1->getCountries()[indexLargest]->getNeighbors()[i]->getCountryName() << endl;
        }
    }
}

void AggressiveStrategy::fortify(Player *p1){
    //aggregate forces in one country
    int indexLargest = 0;
    for(int i = 0; i < p1->getCountries().size() - 1; i++){
        //p1->getCountries()[i]->getNumberOfArmies();
        //one with most armies
        if(p1->getCountries()[i]->getNumberOfArmies() > p1->getCountries()[indexLargest]->getNumberOfArmies())
            indexLargest = i;
    }
    cout << "Fortify to country " << p1->getCountries()[indexLargest]->getCountryName() << endl;
    //look through all of the countries and find second largest country (cannot be the largest)
    int indexSecondLargest = 0;
    for(int i = 0; i < p1->getCountries().size() - 1; i++){
        //p1->getCountries()[i]->getNumberOfArmies();
        //one with most armies
        if(p1->getCountries()[i]->getNumberOfArmies() > p1->getCountries()[indexSecondLargest]->getNumberOfArmies() && i != indexLargest)
            indexSecondLargest = i;
    }
    cout << "Move from country " << p1->getCountries()[indexSecondLargest]->getCountryName() << endl;
}
