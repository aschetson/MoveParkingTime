#include "movingstate.h"

#include "timeregistrator.h"
#include "parkingstate.h"
#include "utils.h"

void MovingState::addData(bool moving, const QTime& currentTime)
{
    if (!moving)
    {
        m_registrator.addTimeMoved(currentTime - m_startTime);
        m_registrator.setState(std::make_unique<ParkingState>(currentTime, m_registrator));
    }
}

MovingState::MovingState(const QTime &startTime, TimeRegistrator& registrator)
    : State(startTime, registrator)
{

}

void MovingState::flush(const QTime& time)
{
    m_registrator.addTimeMoved(time - m_startTime);
}
