TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS_DEBUG += -pg
QMAKE_LFLAGS_DEBUG += -pg

QMAKE_CXXFLAGS += -Wall -Wextra -Wconversion

INCLUDEPATH += TinyXml2
INCLUDEPATH += SFML-2.4.2-MinGW-32/include

LIBS += -LC:/Projects/GameMapEditor/SFML-2.4.2-MinGW-32/lib
LIBS += -lsfml-graphics-d -lsfml-window-d -lsfml-system-d -lsfml-audio-d

SOURCES += main.cpp \
    MapEditor/Window.cpp \
    MapEditor/PointTester.cpp \
    MapEditor/Platform.cpp \
    MapEditor/MainWindow.cpp \
    MapEditor/Model.cpp \
    MapEditor/CoordinateTranslation.cpp \
    MapEditor/WorldView.cpp \
    MapEditor/PanelView.cpp \
    MapEditor/Button.cpp \
    MapEditor/MovableButton.cpp \
    MapEditor/VertexButton.cpp \
    MapEditor/PlatformDelegate.cpp \
    MapEditor/ClickableConvex.cpp \
    MapEditor/Properted.cpp \
    MapEditor/PlatformPropertiesDelegate.cpp \
    MapEditor/ModelSubscriber.cpp \
    MapEditor/Index.cpp \
    MapEditor/ModelSaver.cpp \
    TinyXml2/tinyxml2.cpp \
    MapEditor/Delegate.cpp \
    MapEditor/TextBox.cpp \
    MapEditor/ToolbarView.cpp \
    MapEditor/ModelLoader.cpp

HEADERS += \
    MapEditor/Window.h \
    MapEditor/PointTester.h \
    MapEditor/Platform.h \
    MapEditor/MainWindow.h \
    MapEditor/Model.h \
    MapEditor/CoordinateTranslation.h \
    MapEditor/WorldView.h \
    MapEditor/PanelView.h \
    MapEditor/Button.h \
    MapEditor/MovableButton.h \
    MapEditor/VertexButton.h \
    MapEditor/PlatformDelegate.h \
    MapEditor/ClickableConvex.h \
    MapEditor/Properted.h \
    MapEditor/PlatformPropertiesDelegate.h \
    MapEditor/ModelSubscriber.h \
    MapEditor/Index.h \
    MapEditor/ModelSaver.h \
    TinyXml2/tinyxml2.h \
    MapEditor/Delegate.h \
    MapEditor/TextBox.h \
    MapEditor/ToolbarView.h \
    MapEditor/ModelLoader.h
