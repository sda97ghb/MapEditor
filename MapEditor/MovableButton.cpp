#include "MapEditor/MovableButton.h"
#include "MapEditor/PointTester.h"

MovableButton::MovableButton() :
    _canMove(false),
    _dx(0),
    _dy(0)
{
}

void MovableButton::grab(const sf::Vector2f& cursorPos)
{
    if (_canMove)
        return;

    if (!PointTester::test(cursorPos, *this))
        return;

    _dx = getPosition().x - cursorPos.x;
    _dy = getPosition().y - cursorPos.y;

    _canMove = true;
}

void MovableButton::release()
{
    if (!_canMove)
        return;

    _canMove = false;
}

void MovableButton::move(const sf::Vector2f& cursorPos)
{
    if (!_canMove)
        return;

    setPosition(cursorPos.x + _dx, cursorPos.y + _dy);

    _onMoveCallback();
}

void MovableButton::setOnMoveCallback(const std::function<void()>& function)
{
    _onMoveCallback = function;
}
