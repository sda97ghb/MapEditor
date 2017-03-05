#include "MapEditor/ClickableConvex.h"
#include "MapEditor/PointTester.h"

void ClickableConvex::testForClick(const sf::Vector2f& cursorPos)
{
    if (!PointTester::test(cursorPos, *this))
        return;

    _onClickCallback();
}

void ClickableConvex::setOnClickCallback(const std::function<void()>& callback)
{
    _onClickCallback = callback;
}
