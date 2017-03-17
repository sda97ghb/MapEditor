TEMPLATE = lib

CONFIG += console staticlib c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += include

HEADERS += \
    include/TinyXml2/tinyxml2.h

SOURCES += \
    src/tinyxml2.cpp
