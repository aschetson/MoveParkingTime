#ifndef IDATAREADER_H
#define IDATAREADER_H

#include <stdexcept>

#include "dataitem.h"

class InvalidData : public std::runtime_error
{
public:
    InvalidData(const std::string& data, uint line)
        : std::runtime_error("Data was not recognized: "
                             + data
                             + ". At line "
                             + std::to_string(line))
    {
    }
};

/**
 * @brief Data reader interface
 */
class IDataReader
{
public:
    /**
     * @brief Check if data is over
     * @return true if data is over
     */
    virtual bool atEnd() = 0;

    /**
     * @brief Read one data item
     * @return readed data item
     * @throw InvalidData if format was not recognized
     */
    virtual DataItem readNext() = 0;
    virtual ~IDataReader() = default;

};

#endif // IDATAREADER_H
