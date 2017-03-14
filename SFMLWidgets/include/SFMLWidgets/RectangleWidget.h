#ifndef RECTANGLEWIDGET_H
#define RECTANGLEWIDGET_H

#include "SFML/Graphics/RectangleShape.hpp"

#include "SFMLWidgets/Widget.h"

namespace sfml_widgets
{
    class RectangleWidget;
    class View;
}

/// @brief Just a decorative rectangle widget without any callbacks.
class sfml_widgets::RectangleWidget : public sfml_widgets::Widget,
                                      public sf::RectangleShape
{
public:
    /// @brief Constructor.
    /// @details Place the widget on given view and registry it in view's window.
    /// @param view View where button will be placed.
    RectangleWidget(sfml_widgets::View* view);

private:
    /// @brief  Call window draw method to paint the widget.
    void paint(sfml_widgets::Window& window);
};

#endif // RECTANGLEWIDGET_H
