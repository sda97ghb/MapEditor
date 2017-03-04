#ifndef WORLDVIEW_H
#define WORLDVIEW_H

#include "SFML/Graphics/View.hpp"

#include "MapEditor/VertexButton.h"

class MainWindow;

class WorldView : public sf::View
{
public:
    WorldView(MainWindow* window);

    void paint();

    void mousePressedEvent(const sf::Event::MouseButtonEvent& event);
    void mouseReleasedEvent(const sf::Event::MouseButtonEvent& event);
    void mouseMovedEvent(const sf::Event::MouseMoveEvent& event);

private:
    MainWindow* _window;
    VertexButton _button[8];
    uint32_t _numOfButtons;
};

#endif // WORLDVIEW_H
