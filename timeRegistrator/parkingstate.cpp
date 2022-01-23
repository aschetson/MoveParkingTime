#include "parkingstate.h"

#include "timeregistrator.h"
#include "movingstate.h"
#include "utils.h"

void ParkingState::addData(bool moving, const QTime& currentTime)
{
    if (moving)
    {
        auto delta = currentTime - m_startTime;

        if (delta > m_registrator.PARKING_TIME_MIN_VAL)
        {
            m_registrator.addTimeParked(delta);
            m_registrator.setState(std::make_unique<MovingState>(currentTime, m_registrator));
        }
        else
        {
            m_registrator.setState(std::make_unique<MovingState>(m_startTime, m_registrator));
        }
    }
}

ParkingState::ParkingState(const QTime &startTime, TimeRegistrator &registrator)
    : State(startTime, registrator)
{
}

void ParkingState::flush(const QTime& time)
{
    m_registrator.addTimeParked(time - m_startTime);
}
