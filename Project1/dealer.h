#pragma once

#include "deck.h"

class Dealer{
public:
    explicit Dealer( int suits = 4 );
    Card operator() ();
private:
    int m_suits;
    Deck deck;
};