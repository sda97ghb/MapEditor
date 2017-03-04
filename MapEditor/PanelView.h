#ifndef PANELVIEW_H
#define PANELVIEW_H

#include <list>

#include "SFML/Graphics/View.hpp"
#include "SFML/Window/Event.hpp"

#include "MapEditor/Button.h"
#include "MapEditor/Window.h"

class PanelView : public sf::View
{
public:
    PanelView(Window* window);

    void paint();

    void mouseReleasedEvent(const sf::Event::MouseButtonEvent& event);

    std::list<Button> _buttons;

    Window* _window;
};

#endif // PANELVIEW_H
