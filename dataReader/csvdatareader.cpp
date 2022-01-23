#include "csvdatareader.h"

const QString CsvDataReader::DATE_FORMAT{"yyyy-MM-dd HH:mm:ss"};

CsvDataReader::CsvDataReader(const QString &fileName)
    : m_file(fileName)
{
    if (!m_file.open(QFile::ReadOnly))
    {
        throw std::runtime_error(m_file.errorString().toStdString()
                                 + " File name: '" + fileName.toStdString() + "'");
    }
}

DataItem CsvDataReader::readNext()
{
    ++m_line;
    auto lst = m_file.readLine().split(',');

    if (lst.size() < Size)
    {
        throw InvalidData(lst.join(',').toStdString(), m_line);
    }

    QString date = lst[Date];
    date = date.remove("\"");
    auto dt = QDateTime::fromString(date, DATE_FORMAT);

    if (!dt.isValid())
    {
        throw InvalidData(date.toStdString(), m_line);
    }

    return
    {
        dt,
        lst[Id],
        static_cast<uint16_t>(lst[Speed].toUInt())
    };

}

bool CsvDataReader::atEnd()
{
    return m_file.atEnd();
}
