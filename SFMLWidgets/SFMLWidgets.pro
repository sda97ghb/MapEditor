TEMPLATE = lib

CONFIG += console staticlib c++11
CONFIG -= app_bundle
CONFIG -= qt

#QMAKE_CXXFLAGS_DEBUG += -pg
#QMAKE_LFLAGS_DEBUG += -pg

QMAKE_CXXFLAGS += -Wall -Wextra -Wconversion

INCLUDEPATH += include

INCLUDEPATH += ../SFML-2.4.2-MinGW-32/include

LIBS += -LC:/Projects/GameMapEditor/SFML-2.4.2-MinGW-32/lib
LIBS += -lsfml-graphics-d -lsfml-window-d -lsfml-system-d -lsfml-audio-d

HEADERS += \
    include/SFMLWidgets/Button.h \
    include/SFMLWidgets/Clickable.h \
    include/SFMLWidgets/ClickableConvex.h \
    include/SFMLWidgets/ClickableRectangle.h \
    include/SFMLWidgets/EventProcessor.h \
    include/SFMLWidgets/Movable.h \
    include/SFMLWidgets/MovableConvex.h \
    include/SFMLWidgets/MovableRectangle.h \
    include/SFMLWidgets/PointTester.h \
    include/SFMLWidgets/RectangleWidget.h \
    include/SFMLWidgets/TextWidget.h \
    include/SFMLWidgets/View.h \
    include/SFMLWidgets/Widget.h \
    include/SFMLWidgets/Window.h

SOURCES += \
    src/Button.cpp \
    src/Clickable.cpp \
    src/ClickableConvex.cpp \
    src/ClickableRectangle.cpp \
    src/EventProcessor.cpp \
    src/Movable.cpp \
    src/MovableConvex.cpp \
    src/MovableRectangle.cpp \
    src/PointTester.cpp \
    src/RectangleWidget.cpp \
    src/TextWidget.cpp \
    src/View.cpp \
    src/Widget.cpp \
    src/Window.cpp
