#ifndef FILERESULTWRITER_H
#define FILERESULTWRITER_H

#include "iresultwriter.h"

#include <QFile>

class FileResultWriter : public IResultWriter
{
    QFile m_file;
    bool m_writeLastSeparator = false;
public:
    explicit FileResultWriter(const QString &fileName);
    void write(const Result &result) override;
    ~FileResultWriter();
};

#endif // FILERESULTWRITER_H
