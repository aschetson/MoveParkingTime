#ifndef PARKINGSTATE_H
#define PARKINGSTATE_H

#include "state.h"

/**
 * @brief Class that defines parking state
 */
class ParkingState : public State
{
public:
    /**
     * @copydoc State::addData
     */
    void addData(bool moving, const QTime& currentTime) override;
    /**
     * @copydoc State::State
     */
    ParkingState(const QTime &startTime, TimeRegistrator& registrator);

    /**
     * @copydoc State::flush
     */
    void flush(const QTime& time) override;
};

#endif // PARKINGSTATE_H
