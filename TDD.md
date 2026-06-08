## **Technical Design Document**

## **Overview**

This project is a C++ terminal-based poker roguelike inspired by Balatro. The project is designed to:

- evaluate poker hands,

- calculate scores using chips and multipliers,

- apply joker effects,

- manage player actions such as `PLAY` and `DISCARD`,

- progress through a series of blinds across multiple antes.

The architecture is modular, meaning each system has its own responsibility and can be extended independently without rewriting the whole project.

## **High-Level Architecture**

The project is divided into several main systems.

| **System** | **Responsibility** |
|---|---|
| `GameManager` | Controls the overall run flow |
| `BlindState` | Defines each blind's identity and progression |
| `BlindSession` | Manages the play loop for a single blind |
| `Deck` | Stores and manages cards |
| `HandState` | Stores cards currently held by the player |
| `HandPlayer` | Orchestrates hand scoring |
| `ScoringRule` | Detects poker hand type and retrieves base score |
| `HandScoreTable` | Stores base chips and multiplier per hand type |
| `JokerManager` | Applies joker effects |
| `ScoreEvent` | Stores mutable score data passed through jokers |
| `RewardCommand` | Encapsulates skip reward behavior and timing |
| `RunSessionState` | Single source of truth for all run state |

## **Runtime Flow**

The game session follows this sequence:

```
main() → Setup Jokers → GameManager::run() → Start Blind Loop → Prompt Play or Skip → Reset Runtime State → Shuffle Deck → Inject Bonus Cards → Draw Initial Hand → Player Selects Cards → Evaluate Hand → Calculate Base Score → Apply Joker Effects → Accumulate Blind Score → Check Win Condition → Award Money → Advance Blind
```

## **System Flow**

The runtime system is split into three major stages:

1. Session Setup

2. Blind Loop

3. Action Branches

## **1. Session Setup**

This stage prepares the game before the player starts playing.

```
Flow: main() → Register Jokers → GameManager::run() → Initialize RunSessionState → Set Starting Blind to SmallBlindState
```

## **Main Responsibilities**

## **`addJoker()`**

Registers all active joker effects into `JokerManager`. Examples:

- `PairJoker`

- `FlatChipJoker`

- `FlushJoker`

- `HeartJoker`

- `FaceCardJoker`

## **`RunSessionState` Initialization**

Sets up the initial run state:

- `ante = 1`,

- `money = 0`,

- `currentBlind = SmallBlindState(1)`,

- `pendingCommands = {}`,

- `bonusCards = {}`.

## **2. Blind Loop**

This stage repeats for each blind until the run ends.

```
Flow: Blind Loop → Display Blind Info → Prompt Play or Skip → Execute Pending Commands → Reset BlindRuntimeState → Run BlindSession → Award Money or Game Over → Advance to Next Blind
```

## **Main Functions**

## **`promptPlayOrSkip()`**

Asks the player whether to play or skip the current blind.

## **`executePendingCommands(timing)`**

Iterates `session.persistent.pendingCommands` and executes all commands matching the given `RewardTiming`:

- `RewardTiming::Start`: executed immediately when the skip reward is created,

- `RewardTiming::NextBlind`: executed at the start of the next blind,

- `RewardTiming::NextAnte`: executed at the start of the next ante.

## **`runBlindSession()`**

Constructs a `BlindSession` and runs the play loop for the current blind. Returns `true` if the blind is defeated.

## **`awardMoney()`**

Adds money to `session.persistent.money` after a blind is cleared. Calculated as:

```
Total Money = baseReward + remainingHands
```

## **3. Action Branches**

The game flow changes depending on the player's action.

## **PLAY Branch**

Used when the player wants to score a hand.

```
Flow: Selected Cards → Evaluate Poker Hand → Calculate Base Score → Add Card Chip Values → Apply Jokers → Update Blind Score → Reduce Remaining Hands → Check Win Condition
```

## **Main Responsibilities**

## **`scoreHand()`**

Passes the hand through the `PokerHandChecker` chain to determine:

- poker hand type,

- base chips,

- multiplier.

## **`cardChipValue()`**

Adds each scoring card's chip value to the total:

- 2 to 9: face value,

- 10, J, Q, K: 10 chips,

- Ace: 11 chips.

## **`notifyAll()`**

Passes the `ScoreEvent` to all registered jokers for modification.

## **`isDefeated()`**

Checks whether the accumulated blind score has reached the target.

## **DISCARD Branch**

Used when the player wants to replace cards.

```
Flow: Discard Selected Cards → Refill Hand from Deck → Reduce Remaining Discards
```

## **SKIP Branch**

Used when the player wants to skip a skippable blind.

```
Flow: Create Skip Reward Command → Execute Start Commands Immediately → Store other Commands → Advance to Next BlindState
```

## **Card System**

## **`Card`**

Represents a single playing card. Each card contains:

## **Rank**

```
Two → Ace (integer values 2–14)
```

## **Suit**

```
Spades
Hearts
Clubs
Diamonds
```

Cards are used throughout:

- deck management,

- hand evaluation,

- scoring systems,

- joker systems.

## **`Deck`**

The `Deck` class manages all cards available during a blind.

## **Main Responsibilities**

- create all 52 cards,

- shuffle cards on initialization,

- draw cards into the player's hand,

- inject bonus cards at random positions,

- track remaining card count.

## **Main Functions**

| **Function** | **Purpose** |
|---|---|
| `initialize()` | Creates all 52 cards |
| `shuffle()` | Randomizes card order using `std::mt19937` |
| `draw(n)` | Removes and returns `n` cards from the top |
| `injectCard(card)` | Inserts a card at a random position |
| `remaining()` | Returns the remaining card count |

The deck uses:

- `std::shuffle`

- `std::mt19937`

for randomization. Each `BlindSession` owns its own `Deck` instance, so the deck resets each blind. Bonus cards from `session.persistent.bonusCards` are injected before the first draw.

## **Hand System**

## **`HandState`**

Stores the player's current hand of up to 8 cards. Example: `[7♥] [K♣] [2♦] [A♠] [10♠]`

## **Main Functions**

| **Function** | **Purpose** |
|---|---|
| `refill(deck)` | Draws cards from deck until hand reaches 8 |
| `getSelectedHand(indices)` | Returns a `Hand` from selected indices |
| `removeCards(indices)` | Removes cards by index (sorted descending to avoid shifting) |
| `size()` | Returns current hand size |

## **`Hand`**

Stores only the cards selected for scoring. Example:

```
Player selected: [K♣] [A♠]
```

This separation is important because:

- the player may hold up to 8 cards,

- but only up to 5 selected cards are scored.

## **Blind System**

## **`BlindState`**

Defines the interface for a blind's identity, target score, reward, skip eligibility, and state transition.

## **Main Responsibilities**

Each blind is responsible for:

- defining its name,

- computing its target score,

- defining its reward money,

- defining its skip reward,

- transitioning to the next blind state.

## **Blind Progression**

```
SmallBlindState → BigBlindState → BossBlindState → SmallBlindState (ante + 1)
```

## **Blind Types**

| **Blind** | **Score Multiplier** | **Reward Money** | **Can Skip** |
|---|---|---|---|
| `SmallBlindState` | x1.0 | $3 | Yes |
| `BigBlindState` | x1.5 | $4 | Yes |
| `BossBlindState` | x2.0 | $5 | No |

`BossBlindState` has special behavior:

- increments `ante`,

- restarts the blind cycle with a new `SmallBlindState`.

## **Skip Rewards**

| **Blind** | **Skip Reward** |
|---|---|
| `SmallBlindState` | `BonusHandCommand` |
| `BigBlindState` | `FreePlayingCardCommand` |
| `BossBlindState` | Cannot be skipped |

## **`BlindRule`**

A value object holding the target score for the current blind. Provides:

- `getTarget()`: returns the target score,

- `isDefeated(score)`: returns true when score meets or exceeds the target.

## **Poker Hand Evaluation System**

## **`ScoringRule`**

This system determines: "What poker hand did the player make?" Examples:

- Pair

- Straight

- Flush

- Full House

## **How Evaluation Works**

`ScoringRule` constructs and owns the full `PokerHandChecker` chain. It checks each hand type one by one in priority order. The first checker that matches becomes the final hand type.

## **Example**

```
Check Flush Five → not matched
Check Flush House → not matched
Check Five of a Kind → not matched
Check Royal Flush → not matched
Check Full House → matched
STOP
Result = Full House
```

## **`PokerHandChecker`**

Each checker is responsible for detecting one specific poker hand. Examples:

- `FlushChecker`

- `StraightChecker`

- `PairChecker`

Each checker returns a `ScoreResult` containing:

- `handRank`,

- base `chips` and `mult` (filled in by `ScoringRule`),

- `scoringCards` (only the cards that contributed to the hand).

## **Evaluation Priority**

Hands are checked from strongest to weakest.

`1. FlushFive`

`2. FlushHouse`

`3. FiveOfAKind`

`4. RoyalFlush`

`5. StraightFlush`

`6. FourOfAKind`

`7. FullHouse`

`8. Flush`

`9. Straight`

`10. ThreeOfAKind`

`11. TwoPair`

`12. Pair`

`13. HighCard`

## **`HighCardChecker`**

Acts as the fallback checker. If no other hand matches:

- `HighCard` is returned,

- this guarantees every non-empty hand always produces a valid result.

## **Scoring System**

## **`HandPlayer`**

Combines poker hand evaluation and scoring. Produces the final integer score.

## **Scoring Steps**

```
Evaluate Hand → Retrieve Base Chips and Mult → Add Card Chip Values → Build ScoreEvent → Apply Jokers → Return chips x mult
```

## **`ScoreResult`**

Output of `ScoringRule::scoreHand()`. Contains:

| **Field** | **Description** |
|---|---|
| `handRank` | Detected poker hand type |
| `chips` | Base chip value |
| `mult` | Base multiplier |
| `scoringCards` | Cards that contributed to the hand |

## **`HandScoreTable`**

Stores base score values for each poker hand type. Supports runtime upgrades via `upgradeChips()` and `upgradeMultiplier()`. Example:

| **Hand Type** | **Chips** | **Mult** |
|---|---|---|
| High Card | 5 | 1 |
| Pair | 10 | 2 |
| Two Pair | 20 | 2 |
| Three of a Kind | 30 | 3 |
| Straight | 30 | 4 |
| Flush | 35 | 4 |
| Full House | 40 | 4 |
| Four of a Kind | 60 | 7 |
| Straight Flush | 100 | 8 |
| Royal Flush | 100 | 8 |
| Five of a Kind | 120 | 12 |
| Flush House | 140 | 14 |
| Flush Five | 160 | 16 |

## **Formula**

Final Score = chips x mult

Example:

```
(35 base chips + 42 card chips) x 4 mult = 308 score
```

## **Joker System**

## **`ScoreEvent`**

Stores mutable runtime score data. Jokers modify this object directly. Contains:

- scoring cards,

- hand rank,

- chips,

- multiplier.

## **`JokerManager`**

Responsible for:

- storing all active jokers,

- notifying jokers in registration order.

## **Joker Flow**

```
Base Score Calculated → Build ScoreEvent → JokerManager Notifies Jokers → Jokers Modify ScoreEvent → Final Score Computed
```

## **`JokerCard`**

Represents a score modifier. Each joker can:

- check conditions against the `ScoreEvent`,

- modify chips,

- modify multiplier.

## **Built-In Jokers**

## **`FlatChipJoker`**

Condition:

- always active.

Effect:

```
+50 chips
```

## **`PairJoker`**

Condition:

- activates only when the hand type is `Pair`.

Effect:

```
+4 mult
```

## **`FaceCardJoker`**

Condition:

- activates per J, Q, or K in the scoring hand.

Effect:

```
+2 mult per face card
```

## **`HeartJoker`**

Condition:

- activates per Heart card in the scoring hand.

Effect:

```
+30 chips per Heart
```

## **`FlushJoker`**

Condition:

- activates only when the hand type is `Flush`.

Effect:

```
x1.5 mult
```

## **Reward System**

## **`RewardCommand`**

Encapsulates a skip reward action with deferred or immediate execution. Each command defines:

- its effect via `execute()`,

- its timing via `getTiming()`,

- an optional player choice via `resolveChoice()`.

## **`RewardTiming`**

| **Timing** | **When Executed** |
|---|---|
| `Start` | Immediately when the skip reward is created |
| `NextBlind` | At the start of the next blind |
| `NextAnte` | At the start of the next ante |

## **Reward Flow**

```
Player Skips Blind → BlindState Creates RewardCommand → Start Commands Execute Immediately → Other Commands Stored → Next Blind Starts → NextBlind Commands Execute → Next Ante Starts → NextAnte Commands Execute
```

## **Built-In Commands**

## **`BonusHandCommand`**

Timing: `NextBlind`

Effect:

```
session.runtime.remainingHands += 1
```

## **`FreePlayingCardCommand`**

Timing: `Start`

- `resolveChoice()`: generates 3 random cards, prompts player to pick one,

- `execute()`: pushes the chosen card into `session.persistent.bonusCards`,

- bonus cards are injected into the deck at the start of each `BlindSession`.

## **State Management**

## **`RunSessionState`**

Single source of truth for all run state. Split into two structs to make resets explicit.

## **`RunPersistentState`**

Survives the entire run.

| **Field** | **Description** |
|---|---|
| `ante` | Current ante number |
| `money` | Player's current money |
| `currentBlind` | Active blind state |
| `pendingCommands` | Queued skip reward commands |
| `bonusCards` | Cards permanently added to the deck |

## **`BlindRuntimeState`**

Resets before every blind.

| **Field** | **Default** |
|---|---|
| `blindScore` | 0 |
| `remainingHands` | 4 |
| `remainingDiscards` | 3 |

## **Extension Guide**

This section explains how to safely extend the system.

## **Adding a New Joker**

## **Step 1 — Create a New Joker Class**

Create a class that inherits from `JokerCard`.

Example:

```
class MyNewJoker : public JokerCard
```

## **Step 2 — Implement Required Functions**

Every joker must implement:

```
onScoreCalculated(ScoreEvent& event)
```

## **Step 3 — Register the Joker**

Add the joker inside `main.cpp`:

```
gm.addJoker(std::make_unique<MyNewJoker>());
```

No existing code needs to change.

## **Adding a New Hand Checker**

## **Step 1 — Create a New Checker Class**

Create a class that inherits from `PokerHandChecker`.

## **Step 2 — Implement Required Functions**

```
ScoreResult check(const Hand& hand) override;
```

Return a `ScoreResult` on match, or delegate to `nextChecker`.

## **Step 3 — Add to Score Table**

Add a corresponding entry to `HandRank` and `HandScoreTable::initialize()`.

## **Step 4 — Insert into the Chain**

Insert the checker at the correct priority position in `ScoringRule`'s constructor.

## **Adding a New Blind Type**

## **Step 1 — Create a New Blind Class**

Create a class that inherits from `BlindState` and implement all pure virtual functions:

```
getName()
getTargetScore()
getRewardMoney()
nextState()
createSkipReward()
canSkip()
```

## **Step 2 — Wire into Progression**

Update the appropriate `nextState()` in the adjacent blind to install the new blind.

## **Adding a New Reward Command**

## **Step 1 — Create a New Command Class**

Create a class that inherits from `RewardCommand`.

## **Step 2 — Implement Required Functions**

```
execute(RunSessionState& session)
getTiming()
getDescription()
```

Optionally override `resolveChoice()` for interactive rewards.

## **Step 3 — Return from a Blind**

Return the new command from the relevant `BlindState::createSkipReward()`.
