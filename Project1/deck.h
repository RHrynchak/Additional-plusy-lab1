#pragma once

#include <vector>
#include "card.h"

class Deck{
public:
    explicit Deck ( int suits = 4 );
    Card draw();
    bool empty() const { return m_deck.empty(); }

private:
    int m_suits;
    std::vector <Card> m_deck;
};
