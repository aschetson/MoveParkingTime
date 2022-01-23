#ifndef STATE_H
#define STATE_H

#include <memory>

#include <QTime>

class TimeRegistrator;

/**
 * @brief Class that defines vehicle state
 */
class State
{
protected:
    /// State setting time
    QTime m_startTime;
    /// Moving/parking time registration object
    TimeRegistrator& m_registrator;

public:
    /**
     * @brief Adding new data to system and state changing
     * @param moving State flag (moving / stopped)
     * @param currentTime Time of the passed state
     */
    virtual void addData(bool moving, const QTime& currentTime) = 0;

    /**
     * @brief State Constructor
     * @param startTime State setting time
     * @param registrator Moving/parking time registration object
     */
    State(const QTime &startTime, TimeRegistrator& registrator);

    /**
     * @brief Change state setting time
     * @param startTime New state setting time
     */
    void setStartTime(const QTime &startTime);

    /**
     * @brief Save all data until passed time
     */
    virtual void flush(const QTime& time) = 0;

    virtual ~State() = default;
};

#endif // STATE_H
