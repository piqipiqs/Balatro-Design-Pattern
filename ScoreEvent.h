#ifndef SCOREEVENT_H
#define SCOREEVENT_H

class ScoreEvent
{
public:
    virtual ~ScoreEvent() = default;

    // Returns the score change associated with this event.
    virtual int getScoreChange() const = 0;
};

#endif // SCOREEVENT_H
