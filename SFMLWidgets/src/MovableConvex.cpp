#include "SFMLWidgets/MovableConvex.h"
#include "SFMLWidgets/PointTester.h"
#include "SFMLWidgets/Window.h"

sfml_widgets::MovableConvex::MovableConvex(sfml_widgets::View* view) :
    sfml_widgets::Movable(view)
{}

bool sfml_widgets::MovableConvex::testForGrab(const sf::Vector2f& cursorPos)
{
    if (!sfml_widgets::PointTester::test(cursorPos, *this))
        return false;

    _dx = getPosition().x - cursorPos.x;
    _dy = getPosition().y - cursorPos.y;
    _canMove = true;
    _onGrabCallback();
    return true;
}

void sfml_widgets::MovableConvex::move(const sf::Vector2f& cursorPos)
{
    if (_canMove)
    {
        setPosition(cursorPos.x + _dx, cursorPos.y + _dy);
        _onMoveCallback();
    }
}

void sfml_widgets::MovableConvex::paint(sfml_widgets::Window& window)
{
    window.draw(*this);
}
