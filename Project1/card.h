#pragma once
#include <string>
#include <compare>

class Card {
public:

    Card() = default;
    Card(int suit, int rank);

    int getSuit() const { return suit; }
    int getRank() const { return rank; }

    std::string to_string() const;

    std::strong_ordering operator<=>(const Card& other) const noexcept { return rank <=> other.rank;}
    bool operator==(const Card& other) const noexcept = default;

private:
    int suit;
    int rank;
};
