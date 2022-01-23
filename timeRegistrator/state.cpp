#include "state.h"

void State::setStartTime(const QTime &startTime)
{
    m_startTime = startTime;
}

State::State(const QTime &startTime, TimeRegistrator& registrator)
    : m_startTime(startTime)
    , m_registrator(registrator)
{
}
