#include "deck.h"
#include <algorithm>
#include "random.h"
#include "constants.h"

Deck::Deck ( int suits ) : m_suits( suits ){
    for ( int suit = 1; suit <= m_suits; ++suit ){
        for ( int rank = 1; rank <= TOTAL_RANKS; ++rank )
            m_deck.push_back(Card(suit, rank));
    }
    std::shuffle( m_deck.begin(), m_deck.end(), Random::engine() );
}

Card Deck::draw(){
    Card temp = m_deck.back();
    m_deck.pop_back();
    return temp;
}