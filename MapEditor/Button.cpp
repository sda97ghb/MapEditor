#include "MapEditor/Button.h"
#include "MapEditor/PointTester.h"

void Button::setSize(const sf::Vector2f& size)
{
    sf::RectangleShape::setSize(size);
}

void Button::setSize(float width, float height)
{
    sf::RectangleShape::setSize(sf::Vector2f(width, height));
}

void Button::testForClick(const sf::Vector2f& pos)
{
    if (PointTester::test(pos, *this))
        _callback();
}

void Button::setCallback(const std::function<void ()>& callback)
{
    _callback = callback;
}
