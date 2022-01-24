#include "timeregistrator.h"

#include "movingstate.h"
#include "parkingstate.h"
#include "utils.h"

void TimeRegistrator::flush()
{
    checkParking(DAY_END);
    m_state->flush(DAY_END);
    m_state.reset();
}

QTime TimeRegistrator::timeParked() const
{
    return m_timeParked;
}

QTime TimeRegistrator::timeMoved() const
{
    return m_timeMoved;
}

std::unique_ptr<State> TimeRegistrator::initialState(bool moving)
{
    if (moving)
    {
        return std::make_unique<MovingState>(QTime(0, 0), *this);
    }
    else
    {
        return std::make_unique<ParkingState>(QTime(0, 0), *this);
    }
}

void TimeRegistrator::checkParking(const QTime& currentTime)
{
    auto delta = currentTime - m_lastTime;

    if (delta >= PARKING_TIME_MIN_VAL)
    {
        addTimeParked(delta);
        m_state->flush(m_lastTime);
        m_state->setStartTime(currentTime);
    }
}

void TimeRegistrator::setState(std::unique_ptr<State> state)
{
    m_state = std::move(state);
}

void TimeRegistrator::addData(bool moving, const QTime &currentTime)
{
    if (currentTime < m_lastTime)
    {
        throw DataOrderError(m_lastTime, currentTime);
    }

    if (!m_state)
    {
        setState(initialState(moving));
    }

    checkParking(currentTime);

    m_state->addData(moving, currentTime);
    m_lastTime = currentTime;
}

void TimeRegistrator::addTimeParked(const QTime &time)
{
    m_timeParked = m_timeParked + time;
}

void TimeRegistrator::addTimeMoved(const QTime &time)
{
    m_timeMoved = m_timeMoved + time;
}

DataOrderError::DataOrderError(const QTime &min, const QTime &passed)
    : std::runtime_error(
          QString{"Adding data is only available in non-descending order. "
                  "Minimum allowable value: %1. "
                  "Value passed: %2"}.arg(min.toString()).arg(passed.toString()).toStdString())
{

}
