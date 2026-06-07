#ifndef RUNSESSIONSTATE_H
#define RUNSESSIONSTATE_H

#include <vector>
#include <memory>
#include "Card.h"
#include "blind/BlindState.h"
#include "command/RewardCommand.h"

// --- Persistent State ---
// Survives across all blinds in a run
struct RunPersistentState {
    int ante = 1;
    int money = 0;
    std::unique_ptr<BlindState> currentBlind;
    std::vector<std::unique_ptr<RewardCommand>> pendingCommands;
    std::vector<Card> bonusCards; // Persists across all blinds
};

// --- Runtime State ---
// Resets every time a new blind starts
struct BlindRuntimeState {
    int blindScore = 0;
    int remainingHands = 4;
    int remainingDiscards = 3;
};

// --- Combined Session State ---
// Single source of truth for the current run
struct RunSessionState {
    RunPersistentState persistent;
    BlindRuntimeState runtime;
};

#endif