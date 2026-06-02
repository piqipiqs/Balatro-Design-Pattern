#ifndef JOKER_CARD_H
#define JOKER_CARD_H

class IJokerCard {
public:
    virtual ~IJokerCard() = default;

    // Return true if the Joker acts as a wildcard
    virtual bool isWildcard() const = 0;

    // Get the represented value when used as a substitute
    // Returns -1 if not applicable
    virtual int substitutedValue() const = 0;

    // Set the joker to act as a wildcard or not
    virtual void setWildcard(bool wildcard) = 0;
};

#endif // JOKER_CARD_H
