#ifndef MOVABLERECTANGLE_H
#define MOVABLERECTANGLE_H

#include "SFML/Graphics/RectangleShape.hpp"

#include "SFMLWidgets/Movable.h"

namespace sfml_widgets
{
    class MovableRectangle;
}

/// @brief Movable rectangle widget. Can be moved using the mouse.
class sfml_widgets::MovableRectangle : public sfml_widgets::Movable,
                                       public sf::RectangleShape
{
public:
    /// @brief Constructor.
    /// @details Place the widget on given view and registry it in view's window.
    /// @param view View where button will be placed.
    MovableRectangle(sfml_widgets::View* view);

private:
    /// @brief Test if cursor is on the widget grab it, otherwise don't do
    /// anything.
    void grab(const sf::Vector2f& cursorPos);

    /// @brief Move the widget taking into account _dx and _dy.
    void move(const sf::Vector2f &cursorPos);

    /// @brief Call window draw method to paint the widget.
    void paint(sfml_widgets::Window &window);
};

#endif // MOVABLERECTANGLE_H
