#ifndef BUTTON_H
#define BUTTON_H

#include <functional>

#include "SFML/Graphics/RectangleShape.hpp"

class Button : public sf::RectangleShape
{
public:
    void testForClick(const sf::Vector2f& pos);

    void setCallback(const std::function<void ()>& callback);

protected:
    std::function<void()> _callback;
};

#endif // BUTTON_H
