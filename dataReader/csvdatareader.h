#ifndef CSVDATAREADER_H
#define CSVDATAREADER_H

#include "idatareader.h"

#include <QFile>

class CsvDataReader : public IDataReader
{
    enum Column
    {
        Date,
        Id,
        Speed,
        Size
    };

    uint m_line = 0;
    QFile m_file;
    static const QString DATE_FORMAT;

public:
    /**
     * @brief Constructor
     * @param fileName CSV file name
     * @throw std::runtime_error if file was not open
     */
    explicit CsvDataReader(const QString &fileName);

    /**
     * @copydoc IDataReader::readNext
     */
    DataItem readNext() override;

    /**
     * @copydoc IDataReader::atEnd
     */
    bool atEnd() override;
};

#endif // CSVDATAREADER_H
