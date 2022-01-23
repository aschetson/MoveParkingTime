#include "cmdargumentsparser.h"

#include "csvdatareader.h"
#include "fileresultwriter.h"

const QString CmdArgumentsParser::IN{"in"};
const QString CmdArgumentsParser::IN_TYPE{"in-type"};
const QString CmdArgumentsParser::OUT{"out"};
const QString CmdArgumentsParser::FORCE{"force"};
const QString CmdArgumentsParser::F{"f"};

CmdArgumentsParser::CmdArgumentsParser(const QStringList& args)
{
    m_parser.setApplicationDescription("Application for parking and moving time calculation");

    QCommandLineOption inOption(IN, "Read data from <source>", "source", "log.csv");
    QCommandLineOption inTypeOption(IN_TYPE, "Source type <type>", "type", "csv-file");
    QCommandLineOption outOption(OUT, "Save results into <dest>", "dest", "out.txt");
    QCommandLineOption overwriteOption{{FORCE, F}, "Overwrite existing files."};

    m_parser.addOption(inOption);
    m_parser.addOption(outOption);
    m_parser.addOption(overwriteOption);
    m_parser.addOption(inTypeOption);
    m_parser.addHelpOption();

    m_parser.process(args);

    if (m_parser.isSet("?"))
    {
        m_parser.showHelp();
    }
}

std::unique_ptr<IDataReader> CmdArgumentsParser::createReader()
{
    auto type = m_parser.value(IN_TYPE);

    if (type.compare("csv-file", Qt::CaseInsensitive) == 0)
    {
        return std::make_unique<CsvDataReader>(m_parser.value(IN));
    }

    throw std::runtime_error("Source type " + type.toStdString() + " not supported");
}

std::unique_ptr<IResultWriter> CmdArgumentsParser::createWriter()
{
    bool overwrite = m_parser.isSet(FORCE) || m_parser.isSet(F);
    auto dest = m_parser.value(OUT);

    if (!overwrite && QFile::exists(dest))
    {
        throw std::runtime_error("File "
                                 + dest.toStdString()
                                 + " exists. If you want to overwrite this file"
                                   " use --force option");
    }

    return std::make_unique<FileResultWriter>(dest);
}
