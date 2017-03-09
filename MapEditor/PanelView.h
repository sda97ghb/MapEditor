#ifndef PANELVIEW_H
#define PANELVIEW_H

#include "SFML/Graphics/View.hpp"
#include "SFML/Window/Event.hpp"

#include "MapEditor/Delegate.h"
#include "MapEditor/ModelSubscriber.h"
#include "MapEditor/Window.h"

class PanelView : public sf::View, public ModelSubscriber
{
public:
    PanelView(Window* window);

    void paint();

    void mouseReleasedEvent(const sf::Event::MouseButtonEvent& event);

    void elementChanged(Index index);
    void elementSelected(Index index);

private:
    void updateDelegate(Index index);

    Window* _window;

    Delegate* _delegate;
};

#endif // PANELVIEW_H
