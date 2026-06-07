#include "CardUtils.h"

const char* rankToString(Rank rank) {
    switch (rank) {
        case Rank::TWO:   return "2";
        case Rank::THREE: return "3";
        case Rank::FOUR:  return "4";
        case Rank::FIVE:  return "5";
        case Rank::SIX:   return "6";
        case Rank::SEVEN: return "7";
        case Rank::EIGHT: return "8";
        case Rank::NINE:  return "9";
        case Rank::TEN:   return "10";
        case Rank::JACK:  return "Jack";
        case Rank::QUEEN: return "Queen";
        case Rank::KING:  return "King";
        case Rank::ACE:   return "Ace";
        default:          return "?";
    }
}

const char* suitToString(Suit suit) {
    switch (suit) {
        case Suit::SPADES:   return "Spades";
        case Suit::HEARTS:   return "Hearts";
        case Suit::CLUBS:    return "Clubs";
        case Suit::DIAMONDS: return "Diamonds";
        default:             return "?";
    }
}
