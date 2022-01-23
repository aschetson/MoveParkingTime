#ifndef RESULT_H
#define RESULT_H

#include <QTime>

struct Result
{
    std::string id;
    QTime parked;
    QTime moved;
};

std::ostream& operator<< (std::ostream& os, const Result& res);

#endif // RESULT_H
