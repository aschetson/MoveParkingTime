#ifndef DATAITEM_H
#define DATAITEM_H

#include <QDateTime>

/**
 * @brief Representation of log record
 */
struct DataItem
{
    QDateTime dateTime;
    QString id;
    uint16_t speed;
};

std::ostream& operator<< (std::ostream& os, const DataItem& dataItem);

#endif // DATAITEM_H
