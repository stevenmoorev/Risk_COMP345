//
//  Cards.h
//  LotR Risk
//
//  Created by Steven Moore on 2018-09-19.
//  Copyright © 2018 Steven Moore. All rights reserved.
//

//#include "Cards.cpp"

#include <vector>
//#include "Map.h";

using namespace std;

class Card;
class Hand;
class Map;
    
    class Deck
    {
    public:
		Map* map;
        Deck();
        ~Deck();
		Deck* initializeDeck();
        void addCardToDeck(Card* card);
        //void removeCardFromDeck(Card* card);
        //void initializeDeck(Map* map);
        Card* draw();
        //void discard(Card* card);
		
        
    private:
		std::vector<Card*> deck;
        //std::vector<Card*> discardDeck;
        
        //declare operators
        
    };
    
    class Card
    {
    public:
        Card();
        ~Card();
        
        void setType(int randomType);
        char getType( ) const;
        void setDeck(Deck* deck);
        void setHand(Hand* hand);
		void setDrawn(bool isDrawn);
        bool getDrawn() const;
		
        
	private:
		char type;
		bool isDrawn = false;
		Deck* deck;
		Hand* hand;
    
        //one of the countries from the map
        //vector<Country*> country;
    };
    
    
    
    class Hand{
        
    public:
        Hand();
        ~Hand();
        
        
        //if 3 same or 3 different or more than 5 cards
        //depends on the cards
        //gets 5,... 10,... 15, ... reinforcements
        void exchange(Card *card1, Card *card2, Card *card3);
        
       
        
        
        void addCardToHand(Card *card1);
        
        vector<Card*> getCards() const;
        
        //in the beginning of the turn,
        //count how many cards,
        //if returns a number greater than 5, must exchange
       // int countCards() const;
		
		void setBonus(int bonus);
		int getBonus() const;

        
        
    private:
        std::vector<Card*> hand;
		int bonus = 5;
        
    };
    
 



