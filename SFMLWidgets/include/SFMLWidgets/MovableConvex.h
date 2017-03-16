#ifndef MOVABLECONVEX_H
#define MOVABLECONVEX_H

#include "SFML/Graphics/ConvexShape.hpp"

#include "SFMLWidgets/Movable.h"

namespace sfml_widgets
{
    class MovableConvex;
}

/// @brief Movable convex shape. Can be moved by mouse.
class sfml_widgets::MovableConvex : public sfml_widgets::Movable,
                                    public sf::ConvexShape
{
public:
    /// @brief Constructor.
    /// @details Place the widget on given view and registry in in view's window.
    /// @param view View where the widget will be placed.
    MovableConvex(sfml_widgets::View* view);

private:
    /// @brief Test if cursor is on the widget grab it, otherwise don't do
    /// anything.
    bool testForGrab(const sf::Vector2f& cursorPos);

    /// @brief Move the widget taking into account _dx and _dy.
    void move(const sf::Vector2f &cursorPos);

    /// @brief Call window draw method to paint the widget.
    void paint(sfml_widgets::Window &window);
};

#endif // MOVABLECONVEX_H
