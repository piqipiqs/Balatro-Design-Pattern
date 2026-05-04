#include <iostream>
#include "Card.h"
#include "Hand.h"
#include "checker/PokerHandChecker.h"
#include "checker/FlushFiveChecker.h"
#include "checker/FlushHouseChecker.h"
#include "checker/FiveOfAKindChecker.h"
#include "checker/RoyalFlushChecker.h"
#include "checker/StraightFlushChecker.h"
#include "checker/FourOfAKindChecker.h"
#include "checker/FullHouseChecker.h"
#include "checker/FlushChecker.h"
#include "checker/StraightChecker.h"
#include "checker/ThreeOfAKindChecker.h"
#include "checker/TwoPairChecker.h"
#include "checker/PairChecker.h"
#include "checker/HighCardChecker.h"

int main() {
    // Build chain: strongest -> weakest
    FlushFiveChecker flushFive;
    FlushHouseChecker flushHouse;
    FiveOfAKindChecker fiveOfAKind;
    RoyalFlushChecker royalFlush;
    StraightFlushChecker straightFlush;
    FourOfAKindChecker fourOfAKind;
    FullHouseChecker fullHouse;
    FlushChecker flush;
    StraightChecker straight;
    ThreeOfAKindChecker threeOfAKind;
    TwoPairChecker twoPair;
    PairChecker pair;
    HighCardChecker highCard;

    flushFive.setNext(&flushHouse);
    flushHouse.setNext(&fiveOfAKind);
    fiveOfAKind.setNext(&royalFlush);
    royalFlush.setNext(&straightFlush);
    straightFlush.setNext(&fourOfAKind);
    fourOfAKind.setNext(&fullHouse);
    fullHouse.setNext(&flush);
    flush.setNext(&straight);
    straight.setNext(&threeOfAKind);
    threeOfAKind.setNext(&twoPair);
    twoPair.setNext(&pair);
    pair.setNext(&highCard);

    // Test 1: Flush Five (5x Kings, same suit)
    std::cout << "=== Test 1: Flush Five ===\n";
    Hand h1;
    h1.cards = {
        {Rank::KING, Suit::HEARTS},
        {Rank::KING, Suit::HEARTS},
        {Rank::KING, Suit::HEARTS},
        {Rank::KING, Suit::HEARTS},
        {Rank::KING, Suit::HEARTS}
    };
    flushFive.check(h1);

    // Test 2: Flush House (3x Aces + 2x Kings, same suit)
    std::cout << "\n=== Test 2: Flush House ===\n";
    Hand h2;
    h2.cards = {
        {Rank::ACE,  Suit::SPADES},
        {Rank::ACE,  Suit::SPADES},
        {Rank::ACE,  Suit::SPADES},
        {Rank::KING, Suit::SPADES},
        {Rank::KING, Suit::SPADES}
    };
    flushFive.check(h2);

    // Test 3: Royal Flush (10-J-Q-K-A, same suit)
    std::cout << "\n=== Test 3: Royal Flush ===\n";
    Hand h3;
    h3.cards = {
        {Rank::TEN,   Suit::HEARTS},
        {Rank::JACK,  Suit::HEARTS},
        {Rank::QUEEN, Suit::HEARTS},
        {Rank::KING,  Suit::HEARTS},
        {Rank::ACE,   Suit::HEARTS}
    };
    flushFive.check(h3);

    // Test 4: Straight Flush (5-6-7-8-9, same suit)
    std::cout << "\n=== Test 4: Straight Flush ===\n";
    Hand h4;
    h4.cards = {
        {Rank::FIVE, Suit::CLUBS},
        {Rank::SIX,  Suit::CLUBS},
        {Rank::SEVEN,Suit::CLUBS},
        {Rank::EIGHT,Suit::CLUBS},
        {Rank::NINE, Suit::CLUBS}
    };
    flushFive.check(h4);

    // Test 5: Flush (mixed ranks, same suit)
    std::cout << "\n=== Test 5: Flush ===\n";
    Hand h5;
    h5.cards = {
        {Rank::TWO,   Suit::DIAMONDS},
        {Rank::FIVE,  Suit::DIAMONDS},
        {Rank::SEVEN, Suit::DIAMONDS},
        {Rank::NINE,  Suit::DIAMONDS},
        {Rank::KING,  Suit::DIAMONDS}
    };
    flushFive.check(h5);

    return 0;
}
