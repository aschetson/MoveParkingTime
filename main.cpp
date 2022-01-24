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
        auto reader = parser.createReader();
        auto writer = parser.createWriter();
        Solution solution{std::move(reader), std::move(writer)};
        solution.process();
    }
    catch (std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }


    return 0;
}
