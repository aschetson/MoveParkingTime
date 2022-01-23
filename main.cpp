#include <iostream>

#include <QCoreApplication>

#include "cmdargumentsparser.h"
#include "solution.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    try
    {
        CmdArgumentsParser parser{app.arguments()};
        Solution solution{parser.createReader(), parser.createWriter()};
        solution.process();
    }
    catch (std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }


    return 0;
}
