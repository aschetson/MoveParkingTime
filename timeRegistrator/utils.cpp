#include "utils.h"

QTime operator+(const QTime &left, const QTime &right)
{
    uint32_t res = toSeconds(left) + toSeconds(right);

    if (res > 86400)
    {
        return QTime();
    }

    return QTime(res / 3600, (res / 60) % 60, res % 60);
}

QTime operator-(const QTime &left, const QTime &right)
{
    if (left < right)
    {
        return QTime();
    }

    uint32_t res = toSeconds(left) - toSeconds(right);
    return QTime(res / 3600, (res / 60) % 60, res % 60);
}

uint32_t toSeconds(const QTime &time)
{
    return time.hour() * 60 * 60 + time.minute() * 60 + time.second();
}

float toHours(const QTime &time)
{
    return static_cast<float>(toSeconds(time)) / 3600.f;
}
