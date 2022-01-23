#ifndef MOVINGSTATE_H
#define MOVINGSTATE_H

#include "state.h"

/**
 * @brief Class that defines moving state
 */
class MovingState : public State
{
public:
    /**
     * @copydoc State::addData
     */
    void addData(bool moving, const QTime& currentTime) override;

    /**
     * @copydoc State::State
     */
    MovingState(const QTime& startTime, TimeRegistrator& registrator);

    /**
     * @copydoc State::flush
     */
    void flush(const QTime& time) override;
};

#endif // MOVINGSTATE_H
