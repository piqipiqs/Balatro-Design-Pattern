#ifndef BLINDRULE_H
#define BLINDRULE_H

class BlindRule {
public:
    explicit BlindRule(int target);

    int getTarget() const;
    bool isDefeated(int score) const;

private:
    int target;
};

#endif
