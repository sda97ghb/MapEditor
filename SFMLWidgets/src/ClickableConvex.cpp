#include "SFMLWidgets/ClickableConvex.h"
#include "SFMLWidgets/PointTester.h"
#include "SFMLWidgets/Window.h"

sfml_widgets::ClickableConvex::ClickableConvex(sfml_widgets::View* view) :
    sfml_widgets::Clickable(view)
{
}

void sfml_widgets::ClickableConvex::testForClick(const sf::Vector2f& cursorPos)
{
    if (sfml_widgets::PointTester::test(cursorPos, *this))
        _onClickCallback();
}

void sfml_widgets::ClickableConvex::paint(sfml_widgets::Window& window)
{
    window.draw(*this);
}
