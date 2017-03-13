#ifndef CLICKABLECONVEX_H
#define CLICKABLECONVEX_H

#include "SFML/Graphics/ConvexShape.hpp"

#include "SFMLWidgets/Clickable.h"

namespace sfml_widgets
{
    class ClickableConvex;
    class Window;
}

/// @brief Clickable convex button. Just a polygon with on click action callback.
class sfml_widgets::ClickableConvex : public sfml_widgets::Clickable,
                                      public sf::ConvexShape
{
public:
    /// @brief Constructor.
    /// @details Place button on given view and registry it in view's window.
    /// @param view View where button will be placed.
    ClickableConvex(sfml_widgets::View* view);

private:
    /// @brief Test if cursor is on the button make click, otherwise don't do
    /// anything.
    void testForClick(const sf::Vector2f& cursorPos);

    /// @brief Call window draw method to paint the button.
    void paint(sfml_widgets::Window& window);
};

#endif // CLICKABLECONVEX_H
