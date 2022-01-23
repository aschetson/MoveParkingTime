#ifndef UTILS_H
#define UTILS_H

#include <QTime>

uint32_t toSeconds(const QTime &time);
QTime operator+ (const QTime& left, const QTime& right);
QTime operator- (const QTime& left, const QTime& right);
float toHours(const QTime& time);

#endif // UTILS_H
