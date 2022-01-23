#include "dataitem.h"

#include <sstream>

std::ostream &operator<<(std::ostream &os, const DataItem& dataItem)
{
    os << "id: " << dataItem.id.toStdString() << std::endl;
    os << "dateTime: " << dataItem.dateTime.toString("yyyy-MM-dd HH:mm:ss").toStdString() << std::endl;
    os << "speed: " << dataItem.speed;
    return os;
}
