//
//  Cards.cpp
//  LotR Risk
//
//  Created by Steven Moore on 2018-09-19.
//  Copyright © 2018 Steven Moore. All rights reserved.
//


//must make a card a vector

#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <time.h>
#include "Cards.h"
#include "Map.h"
//#include "Map.cpp"

using namespace std;

class Deck;
class Card;
class Hand;
class Map;
    
    Deck::Deck(){
		cout << "Creating deck" << endl;
    }
    
    Deck::~Deck()
    {
       // for (vector<Card*>::iterator it = deck.begin(); it != deck.end(); it++)
        //{
            //delete *it;
            //*it = NULL;
       // }
        deck.clear();
		cout << "Deleting deck" << endl;
    }

	void Deck::initializeDeck()
	{
		cout << "Initializing Deck" << endl;
        //Deck *deck = new Deck();
		int numOfCards = map->GetCountryCount() + 1;
        cout << "country count is" << this->map->GetCountryCount() +1 ;
		for (int i = 0; i < numOfCards; i++)
		{
            for(int j = 0; j < 3; j++){ //adds 3 cards, one i, one c, one a
                Card *c = new Card(); // new card that will be put on the deck
                c->setType(j);
                addCardToDeck(c);
            }
		}
        //return deck;
	}
    
    void Deck::addCardToDeck(Card *card){
		cout << "Adding card to deck" << endl;
        vector<Card*>::iterator it = find(deck.begin(), deck.end(), card);
        if (it == deck.end())
        {
            deck.push_back(card);
            card->setDeck(this);
        }
    }
    /*
    void Deck::removeCardFromDeck(Card *card)
    {
        vector<Card*>::iterator it = find(deck.begin(), deck.end(), card);
        if (it == deck.end())
        {
            deck.erase(it);
            card->setDeck(NULL);
        }
    }
	*/
    
    Card* Deck::draw()
	{
        srand ( time(NULL) ); // seed the random number with time
        int randCard;
        randCard = rand() % (deck.size());
		Card* c = deck.at(randCard);
        while(c->getDrawn() == true){               //only give a card that hasn't been drawn
            randCard = rand() % (deck.size());
            c = deck.at(randCard);
        }
        deck.at(randCard)->setDrawn(true);
        return c;
    }
    
	
    
	Card::Card()
    {
        cout << "Card is being created" << endl;
    }
    
    Card::~Card()
    {
        cout << "Card is being deleted" << endl;
    }
    
    
    void Card::setType(int randomType)
    {
        if(randomType == 0)
        {
			cout << "type is infantry" << endl;
            type = 'i';  //Infantry
            return;
        }if(randomType == 1)
        {
			cout << "type is cavalry" << endl;
			type = 'c'; //Cavalry
            return;
        }if(randomType == 2)
        {
			cout << "type is artillery" << endl;
			type = 'a';//Artillery
            return;
        }
    }
    
    char Card::getType( ) const
    {
        return type;
    }

	void Card::setDrawn(bool d) 
	{
		isDrawn = d;
	}

    bool Card::getDrawn() const{
        return isDrawn;
    }
    
    void Card::setHand(Hand *newHand)
    {
        if (hand == NULL)
        {
            hand = newHand;
        }
    }
    
    void Card::setDeck(Deck *newDeck)
    {
        if (deck == NULL)
        {
            deck = newDeck;
        }
        
    }
            
    Hand::Hand()
    {
                
    }
            
    Hand::~Hand()
    {
        for (vector<Card*>::iterator it = hand.begin(); it != hand.end(); it++)
        {
            delete *it;
            *it = NULL;
        }
        hand.clear();
    }
            
    void Hand::exchange(Card *c1, Card *c2, Card *c3)
    {
        if((c1->getType() != c2->getType() && c1->getType() != c3->getType() && c2->getType() != c3->getType()) || (c1->getType() == c2->getType() && c1->getType() == c3->getType() && c2->getType() == c3->getType()))
        {
            cout << "Can get bonus of " << getBonus() << endl;
            int bonus = getBonus();
            setBonus(bonus);
        }
    }
    
    void Hand::addCardToHand(Card *c1){
		vector<Card*>::iterator it = find(hand.begin(), hand.end(), c1);
        if (it == hand.end())
        {
            hand.push_back(c1);
            c1->setHand(this);
        }
    }
    
    vector<Card*> Hand::getCards() const
    {
        return hand;
    }
    
	/*
   int Hand::countCards() const
    {
        int count = 0;
        for (int i = 0; i < hand.size(); i++)
        {  
            for (int j = 0; j < hand[i]->getCards().size(); j++)
            {
                count++;
            }
        }
        return count;
    }
	*/
        
    void Hand::setBonus(int b)
    {
        if(b < 60){
            bonus = b + 5;
        }
        else {
            return;
        }
    }
    
    int Hand::getBonus() const
    {
        return bonus;
    }

