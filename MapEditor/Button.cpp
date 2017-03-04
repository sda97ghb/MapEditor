#include "MapEditor/Button.h"
#include "MapEditor/PointTester.h"

void Button::testForClick(const sf::Vector2f& pos)
{
    if (PointTester::test(pos, *this))
        _callback();
}

void Button::setCallback(const std::function<void ()>& callback)
{
    _callback = callback;
}
