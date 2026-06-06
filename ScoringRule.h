#ifndef SCORINGRULE_H
#define SCORINGRULE_H

#include "Hand.h"
#include "ScoreResult.h"
#include "HandScoreTable.h"
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

class ScoringRule {
public:
    ScoringRule();
    ScoreResult scoreHand(const Hand& hand);

private:
    HandScoreTable scoreTable;

    FlushFiveChecker flushFive;
    FlushHouseChecker flushHouse;
    FiveOfAKindChecker fiveKind;
    RoyalFlushChecker royalFlush;
    StraightFlushChecker straightFlush;
    FourOfAKindChecker fourKind;
    FullHouseChecker fullHouse;
    FlushChecker flush;
    StraightChecker straight;
    ThreeOfAKindChecker threeKind;
    TwoPairChecker twoPair;
    PairChecker pair;
    HighCardChecker highCard;
};

#endif
