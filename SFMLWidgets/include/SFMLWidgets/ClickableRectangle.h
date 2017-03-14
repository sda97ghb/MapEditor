#ifndef CLICKABLERECTANGLE_H
#define CLICKABLERECTANGLE_H

#include "SFML/Graphics/RectangleShape.hpp"

#include "SFMLWidgets/Clickable.h"

namespace sfml_widgets
{
    class ClickableRectangle;
    class Window;
}

/// @brief Clickable rectangle button. Just a rectangle with on click action
/// callback.
class sfml_widgets::ClickableRectangle : public sfml_widgets::Clickable,
                                         public sf::RectangleShape
{
public:
    /// @brief Constructor.
    /// @details Place the button on given view and registry it in view's window.
    /// @param view View where button will be placed.
    ClickableRectangle(sfml_widgets::View* view);

private:
    /// @brief Test if cursor is on the button make click, otherwise don't do
    /// anything.
    void testForClick(const sf::Vector2f& cursorPos);

    /// @brief Call window draw method to paint the button.
    void paint(sfml_widgets::Window& window);
};

#endif // CLICKABLERECTANGLE_H
