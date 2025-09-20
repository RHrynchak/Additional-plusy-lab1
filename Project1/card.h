#pragma once
#include <string>
#include <compare>

class Card {
public:
    /*
    enum class Suit {
      Hearts,
      Diamonds,
      Clubs,
      Spades
    };
    */
    enum class Rank {
        Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
        Jack, Queen, King
    };

    Card() = default;
    Card(int suit, Rank rank);

    int getSuit() const { return suit; }
    Rank getRank() const { return rank; }

    std::string to_string() const;

    std::strong_ordering operator<=>(const Card& other) const noexcept { return rank <=> other.rank;}
    bool operator==(const Card& other) const noexcept = default;

private:
    int suit;
    Rank rank;
};