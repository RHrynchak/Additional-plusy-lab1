#include "dealer.h"

Dealer::Dealer ( int suits ) : m_suits( suits ), deck ( suits ) {
}

Card Dealer::operator() (){
    if ( deck.empty() )
        deck = Deck{ m_suits };
    return deck.draw();
}