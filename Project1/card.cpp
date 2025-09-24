#include "card.h"
#include <iostream>
#include <format>

Card::Card(int suit, int rank) : suit(suit), rank(rank) {}

std::string Card::to_string() const {
    return "S" + std::to_string(suit) + "-R" + std::to_string(rank);
}

