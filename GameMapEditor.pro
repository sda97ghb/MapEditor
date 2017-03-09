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

HEADERS += \
#    MapEditor/Button.h \
#    MapEditor/ClickableConvex.h \
#    MapEditor/CoordinateTranslation.h \
#    MapEditor/Delegate.h \
#    MapEditor/Index.h \
#    MapEditor/MainWindow.h \
#    MapEditor/Model.h \
#    MapEditor/ModelLoader.h \
#    MapEditor/ModelSaver.h \
#    MapEditor/ModelSubscriber.h \
#    MapEditor/MovableButton.h \
#    MapEditor/PanelView.h \
#    MapEditor/Platform.h \
#    MapEditor/PlatformDelegate.h \
#    MapEditor/PlatformPropertiesDelegate.h \
#    MapEditor/PointTester.h \
#    MapEditor/Properted.h \
#    MapEditor/TextBox.h \
#    MapEditor/ToolbarView.h \
#    MapEditor/VertexButton.h \
#    MapEditor/Window.h \
#    MapEditor/WorldView.h \
    SFMLWidgets/Button.h \
    SFMLWidgets/Clickable.h \
    SFMLWidgets/ClickableConvex.h \
    SFMLWidgets/ClickableRectangle.h \
    SFMLWidgets/EventProcessor.h \
    SFMLWidgets/Movable.h \
    SFMLWidgets/PointTester.h \
    SFMLWidgets/View.h \
    SFMLWidgets/Widget.h \
    SFMLWidgets/Window.h \
    TinyXml2/tinyxml2.h \
    SFMLWidgets/MovableRectangle.h

SOURCES += main.cpp \
#    MapEditor/Button.cpp \
#    MapEditor/ClickableConvex.cpp \
#    MapEditor/CoordinateTranslation.cpp \
#    MapEditor/Delegate.cpp \
#    MapEditor/Index.cpp \
#    MapEditor/MainWindow.cpp \
#    MapEditor/Model.cpp \
#    MapEditor/ModelLoader.cpp \
#    MapEditor/ModelSaver.cpp \
#    MapEditor/ModelSubscriber.cpp \
#    MapEditor/MovableButton.cpp \
#    MapEditor/PanelView.cpp \
#    MapEditor/Platform.cpp \
#    MapEditor/PlatformDelegate.cpp \
#    MapEditor/PlatformPropertiesDelegate.cpp \
#    MapEditor/PointTester.cpp \
#    MapEditor/Properted.cpp \
#    MapEditor/TextBox.cpp \
#    MapEditor/ToolbarView.cpp \
#    MapEditor/VertexButton.cpp \
#    MapEditor/Window.cpp \
#    MapEditor/WorldView.cpp \
    SFMLWidgets/Button.cpp \
    SFMLWidgets/Clickable.cpp \
    SFMLWidgets/ClickableConvex.cpp \
    SFMLWidgets/ClickableRectangle.cpp \
    SFMLWidgets/EventProcessor.cpp \
    SFMLWidgets/Movable.cpp \
    SFMLWidgets/PointTester.cpp \
    SFMLWidgets/View.cpp \
    SFMLWidgets/Widget.cpp \
    SFMLWidgets/Window.cpp \
    TinyXml2/tinyxml2.cpp \
    SFMLWidgets/MovableRectangle.cpp

