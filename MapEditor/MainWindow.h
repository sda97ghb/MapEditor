#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MapEditor/PanelView.h"
#include "MapEditor/PointTester.h"
#include "MapEditor/Window.h"
#include "MapEditor/WorldView.h"

class Platform;

class MainWindow : public Window
{
public:
    MainWindow();

    void paint();

    void mousePressedEvent(const sf::Event::MouseButtonEvent& event);
    void mouseReleasedEvent(const sf::Event::MouseButtonEvent& event);
    void mouseMovedEvent(const sf::Event::MouseMoveEvent& event);

private:
    const float SCALE_FACTOR = 3.0f / 100.0f;

    Platform* _currentPlatform;

    WorldView _worldView;
    PanelView _panelView;
};

#endif // MAINWINDOW_H
