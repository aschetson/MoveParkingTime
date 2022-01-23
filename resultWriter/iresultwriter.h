#ifndef IRESULTWRITER_H
#define IRESULTWRITER_H

#include "result.h"

/**
 * @brief Result writer interface
 */
class IResultWriter
{
public:
    virtual void write(const Result& result) = 0;
    virtual ~IResultWriter() = default;
};

#endif // IRESULTWRITER_H
