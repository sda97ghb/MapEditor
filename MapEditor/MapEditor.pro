TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS_DEBUG += -std=c++14
QMAKE_LFLAGS_DEBUG += -std=c++14

#QMAKE_CXXFLAGS_DEBUG += -pg
#QMAKE_LFLAGS_DEBUG += -pg

QMAKE_CXXFLAGS += -Wall -Wextra -Wconversion

DEPENDPATH += .
INCLUDEPATH += ..

DEPENDPATH += ../SFMLWidgets/include
INCLUDEPATH += ../SFMLWidgets/include
LIBS += -LC:/Projects/Builds/build-GameMapEditor-Desktop_Qt_5_7_0_MinGW_32bit-Debug/SFMLWidgets/debug
LIBS += -lSFMLWidgets

INCLUDEPATH += ../SFML-2.4.2-MinGW-32/include
LIBS += -LC:/Projects/GameMapEditor/SFML-2.4.2-MinGW-32/lib
LIBS += -lsfml-graphics-d -lsfml-window-d -lsfml-system-d -lsfml-audio-d

HEADERS += \
    Index.h \
    Model.h \
    MainWindow.h \
    WorldViewConstructor.h \
    ModelSubscriber.h \
    Platform.h

SOURCES += main.cpp \
    Index.cpp \
    MainWindow.cpp \
    Model.cpp \
    WorldViewConstructor.cpp \
    ModelSubscriber.cpp \
    Platform.cpp
