#include "SFMLWidgets/ClickableRectangle.h"
#include "SFMLWidgets/PointTester.h"
#include "SFMLWidgets/Window.h"

sfml_widgets::ClickableRectangle::ClickableRectangle(sfml_widgets::View* view) :
    sfml_widgets::Clickable(view)
{
}

void sfml_widgets::ClickableRectangle::testForClick(const sf::Vector2f& cursorPos)
{
    if (sfml_widgets::PointTester::test(cursorPos, *this))
        _onClickCallback();
}

void sfml_widgets::ClickableRectangle::paint(sfml_widgets::Window& window)
{
    window.draw(*this);
}
