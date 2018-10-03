//
//  Cards.h
//  LotR Risk
//
//  Created by Steven Moore on 2018-09-19.
//  Copyright © 2018 Steven Moore. All rights reserved.
//

#ifndef Cards_h
#define Cards_h
#include "../Map/map.h"
using std::istream;
using std::ostream;
using std::vector;
class Map;

namespace Cards{
    class Deck
    {
    public:
        Deck();
        ~Deck();
        void addCardToDeck(Card* card);
        void removeCardFromDeck(Card* card);
        void initializeDeck();
        vector<Card*> draw() const;
        void discard(Card* card);
        
        friend int Map::GetCountryCount() const;
        
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
        
    private:
        char type;
    
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
        void exchange(Card card1, Card card2, Card card3);
        
       
        
        
        void addCardToHand(Card card1);
        
        //in the beginning of the turn,
        //count how many cards,
        //if returns a number greater than 5, must exchange
        int countCards();
        
        
        
    private:
        std::vector<Card*> hand;
        
    };
    
    class Bonus{
    
    public:
        Bonus();
        ~Bonus();
        
        void setBonus(int bonus);
        int getBonus() const;
        
    private:
        int bonus;
    }
}


#endif /* Cards_h */
