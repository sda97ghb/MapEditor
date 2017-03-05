#ifndef WORLDVIEW_H
#define WORLDVIEW_H

#include "SFML/Graphics/View.hpp"

#include "MapEditor/Model.h"
#include "MapEditor/PlatformDelegate.h"
#include "MapEditor/VertexButton.h"

class MainWindow;

class WorldView : public sf::View, public ModelSubscriber
{
public:
    WorldView(MainWindow* window);

    void paint();

    void mousePressedEvent(const sf::Event::MouseButtonEvent& event);
    void mouseReleasedEvent(const sf::Event::MouseButtonEvent& event);
    void mouseMovedEvent(const sf::Event::MouseMoveEvent& event);

    void elementChanged(Index index);
    void elementSelected(Index index);

    void updateDelegate(Index index);

private:
    MainWindow* _window;

    PlatformDelegate _platformDeligate;
};

#endif // WORLDVIEW_H
