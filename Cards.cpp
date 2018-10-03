//
//  Cards.cpp
//  LotR Risk
//
//  Created by Steven Moore on 2018-09-19.
//  Copyright © 2018 Steven Moore. All rights reserved.
//


//must make a card a vector
#include "Cards.h"
#include <iostream>
#include <cstdlib>
using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

//check this

namespace Cards{
    
    Deck::Deck(){
        
    }
    
    Deck::~Deck()
    {
        for (vector<Card*>::iterator it = deck.begin(); it != deck.end(); it++)
        {
            delete *it;
            *it = NULL;
        }
        deck.clear();
    }
    
    Deck::addCardToDeck(Card *card){
        vector<Card*>::iterator it = find(deck.begin(), deck.end(), card);
        if (it == cards.end())
        {
            cards.push_back(card);
            card->setDeck(this);
        }
    }
    
    Deck::removeCardFromDeck(Card *card)
    {
        vector<Card*>::iterator it = find(deck.begin(), deck.end(), card);
        if (it == cards.end())
        {
            cards.erase(it);
            card->setDeck(NULL);
        }
    }
    
    int Deck::getCardCount() const
    {
        return deck.size();
    }
    
    vector<Card*> Deck::draw() const
    {
        vector<Card*>::iterator it = find(deck.begin(), deck.end(), card);
        if (it == cards.end())
        {
            cards.erase(it);
            card->setDeck(NULL);
        }
        vector<Card> top;
        top = deck.back();
        deck.pop_back();
        return top;
    }
    
    Deck::initializeDeck()
    {
        //for the amount of countries there are
        //initialize the deck
        int randomType = rand() % 3;
        for(int i = 0; i < Map::getNumOfCountries(); i++)
        {
            card = Card();  //explicit call to constructor 
            card->setType(randomType);
            addCardToDeck(card);
        };
    }
    
    
    Card::Card()
    {

    }
    
    Card::~Card()
    {
        if(type)
        {
            delete[] type;
        }
    }
    
    
    void Card::setType(int randomType)
    {
        if(i%3 == 0)
        {
            type = 'i';
            //Infantry 
            i++;
            return;
        }if(i%3 == 1)
        {
            type = 'c';
            //Cavalry
            i++;
            return;
        }else
        {
            type = 'a';
            //Artillery
            i++;
            return;
        }
    }
    
    char Card::getType( ) const
    {
       
        return type;
        
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
            
    void Hand::exchange(Card c1, Card c2, Card c3)
    {
        if((c1.getType() != c2.getType() && c1.getType() != c3.getType() && c2.getType() != c3.getType()) || (c1.getType() == c2.getType() && c1.getType() == c3.getType() && c2.getType() == c3.getType()))
        {
            cout >> "Can exchange cards" >> endl;
        }
    }
    
    void Hand::addCardToHand(Card c1){
        vector<Card*>::iterator it = find(hand.begin(), hand.end(), c1);
        if (it == cards.end())
        {
            hand.push_back(card);
            card->setHand(this);
        }
    }
    
    Bonus::Bonus()
    {
        
    }
    
    Bonus::~Bonus()
    {
        if(bonus)
        {
            delete[] bonus;
        }
    }
    
    void Bonus::setBonus(int b)
    {
        if(b < 60){
            bonus = b + 5;
        }
        else {
            return;
        }
    }
    
    int Bonus::getBonus()
    {
        return bonus;
    }
    
        
                             
    
            
        
            

}
