#ifndef CMDARGUMENTSPARSER_H
#define CMDARGUMENTSPARSER_H

#include <memory>

#include <QCommandLineParser>

#include "idatareader.h"
#include "iresultwriter.h"

/**
 * @brief Command line arguments parser (creates data reader and result writer)
 */
class CmdArgumentsParser
{
    QCommandLineParser m_parser;

    static const QString IN;
    static const QString IN_TYPE;
    static const QString OUT;
    static const QString FORCE;
    static const QString F;

public:
    explicit CmdArgumentsParser(const QStringList& args);

    std::unique_ptr<IDataReader> createReader();
    std::unique_ptr<IResultWriter> createWriter();
};

#endif // CMDARGUMENTSPARSER_H
