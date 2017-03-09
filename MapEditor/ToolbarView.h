#ifndef TOOLBARVIEW_H
#define TOOLBARVIEW_H

#include "SFML/Graphics/View.hpp"
#include "SFML/Window/Event.hpp"

#include "MapEditor/Button.h"
#include "MapEditor/Window.h"

class ToolbarView : public sf::View
{
public:
    ToolbarView(Window* window);

    void paint();

    void mouseReleasedEvent(const sf::Event::MouseButtonEvent& event);

private:
    Window* _window;
    Button _addPlatformButton;
};

#endif // TOOLBARVIEW_H
