#ifndef DELEGATE_H
#define DELEGATE_H

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Window;

class Delegate
{
public:
    virtual ~Delegate() = default;
    virtual void paint(sf::RenderWindow& window) = 0;
    virtual void testForClick(const sf::Vector2f& cursorPos) = 0;
};

#endif // DELEGATE_H
