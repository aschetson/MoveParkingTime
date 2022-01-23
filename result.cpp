#include "result.h"
#include "utils.h"

#include <sstream>

std::ostream &operator<<(std::ostream &os, const Result &res)
{
    os << "id: " << res.id << std::endl;
    os << "время в пути: " << toHours(res.moved) << "h" << std::endl;
    os << "время стоянки: " << toHours(res.parked) << "h";
    return os;
}
