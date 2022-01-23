TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
        cmdargumentsparser.cpp \
        main.cpp \
        result.cpp \
        solution.cpp

include(timeRegistrator/timeRegistrator.pri)
include(dataReader/dataReader.pri)
include(resultWriter/resultWriter.pri)

HEADERS += \
    cmdargumentsparser.h \
    result.h \
    solution.h
