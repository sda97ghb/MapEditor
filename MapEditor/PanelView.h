#ifndef PANELVIEW_H
#define PANELVIEW_H

#include <list>

#include "SFML/Graphics/View.hpp"
#include "SFML/Window/Event.hpp"

#include "MapEditor/Button.h"
#include "MapEditor/Platform.h"
#include "MapEditor/PlatformPropertiesDelegate.h"
#include "MapEditor/Window.h"

class PanelView : public sf::View
{
public:
    PanelView(Window* window);

    void paint();

    void mouseReleasedEvent(const sf::Event::MouseButtonEvent& event);

    PlatformPropertiesDelegate _platformPropertiesDelegate;

    Window* _window;
};

#endif // PANELVIEW_H
