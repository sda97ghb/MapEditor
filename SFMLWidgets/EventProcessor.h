#ifndef EVENTPROCESSOR_H
#define EVENTPROCESSOR_H

#include <list>

#include "SFML/Window/Mouse.hpp"

namespace sfml_widgets
{
    class Clickable;
    class EventProcessor;
    class Movable;
}

class sfml_widgets::EventProcessor
{
public:
    void mouseButtonPressedEvent(const sf::Mouse::Button& button,
                                 const sf::Vector2f& cursorPos);
    void mouseButtonReleasedEvent(const sf::Mouse::Button& button,
                                  const sf::Vector2f& cursorPos);
    void mouseMovedEvent(const sf::Vector2f& cursorPos);

    void registryClickable(sfml_widgets::Clickable* clickable);
    void registryMovable(sfml_widgets::Movable* movable);

private:
    std::list<sfml_widgets::Clickable*> _clickables;
    std::list<sfml_widgets::Movable*> _movables;
};

#endif // EVENTPROCESSOR_H
