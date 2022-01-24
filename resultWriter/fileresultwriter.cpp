#include "fileresultwriter.h"

#include <sstream>

FileResultWriter::FileResultWriter(const QString& fileName)
    : m_file(fileName)
{
    if (!m_file.open(QFile::WriteOnly))
    {
        throw std::runtime_error(m_file.errorString().toStdString()
                                 + " File name: '" + fileName.toStdString() + "'");
    }
}

void FileResultWriter::write(const Result &result)
{
    std::stringstream ss;
    ss << "-----" << std::endl;
    ss << std::fixed;
    ss.precision(1);
    ss << result << std::endl;
    bool success = m_file.write(ss.str().c_str()) == static_cast<int>(ss.str().size());

    if (!success)
    {
        throw std::runtime_error(m_file.errorString().toStdString());
    }

    m_writeLastSeparator = true;
}

FileResultWriter::~FileResultWriter()
{
    if (m_writeLastSeparator)
    {
        m_file.write("-----");
    }
}
