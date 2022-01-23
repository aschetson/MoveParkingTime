#ifndef TIMEREGISTRATOR_H
#define TIMEREGISTRATOR_H

#include <memory>

#include <QTime>

#include "state.h"

class DataOrderError : public std::runtime_error
{
    std::string m_msg;
public:
    DataOrderError(const QTime& min, const QTime& passed);
};

/**
 * @brief Parking and moving time registraing class
 */
class TimeRegistrator
{
    /// Current state
    std::unique_ptr<State> m_state = nullptr;

    /// Resulting parking time
    QTime m_timeParked{0, 0};
    /// Resulting moving time
    QTime m_timeMoved{0, 0};
    /// The last accepted time value
    QTime m_lastTime{0, 0};

    /**
     * @brief Getting initinal state
     * @param moving State flag (moving / stopped)
     * @return Initinal state
     */
    std::unique_ptr<State> initialState(bool moving);

    /**
     * @brief Check if vehicle was parked
     */
    void checkParking(const QTime& currentTime);

public:
    /// Minimun value of parking time
    const QTime PARKING_TIME_MIN_VAL{0, 2};
    /// End of the day
    const QTime DAY_END{23, 59, 59};

    /**
     * @brief Changes current state
     * @param state current state
     */
    void setState(std::unique_ptr<State> state);

    /**
     * @brief Adding new data into registration system
     * @param moving State flag (moving / stopped)
     * @param currentTime Time of the passed state
     * @throw std::runtime_error if data passed non-descending order
     */
    void addData(bool moving, const QTime& currentTime);

    /**
     * @brief Adding parking time
     * @param time Adding value
     */
    void addTimeParked(const QTime& time);

    /**
     * @brief Adding moving time
     * @param time Adding value
     */
    void addTimeMoved(const QTime& time);

    /// The last accepted time value
    QTime last() const;

    /**
     * @brief Collecting all data per day
     */
    void flush();
    void setTimeMoved(const QTime &timeMoved);
    QTime timeParked() const;
    QTime timeMoved() const;
};
#endif // TIMEREGISTRATOR_H
