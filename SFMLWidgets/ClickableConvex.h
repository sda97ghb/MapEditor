#ifndef CLICKABLECONVEX_H
#define CLICKABLECONVEX_H

#include "SFML/Graphics/ConvexShape.hpp"

#include "SFMLWidgets/Clickable.h"

namespace sfml_widgets
{
    class ClickableConvex;
    class Window;
}

class sfml_widgets::ClickableConvex : public sfml_widgets::Clickable,
                                      public sf::ConvexShape
{
public:
    ClickableConvex(sfml_widgets::View* view);
    void testForClick(const sf::Vector2f& cursorPos);
    void paint(sfml_widgets::Window& window);
};

#endif // CLICKABLECONVEX_H
