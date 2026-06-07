#ifndef RUNSESSIONSTATE_H
#define RUNSESSIONSTATE_H

#include <vector>
#include <memory>
#include "blind/BlindState.h"
#include "command/RewardCommand.h"

// --- Persistent State ---
// Survives across all blinds in a run
struct RunPersistentState {
    int ante = 1;
    int money = 0;
    std::unique_ptr<BlindState> currentBlind;
    std::vector<std::unique_ptr<RewardCommand>> pendingCommands;
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
// Passed to commands and blind states
struct RunSessionState {
    RunPersistentState persistent;
    BlindRuntimeState runtime;
};

#endif