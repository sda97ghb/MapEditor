#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include "SFML/Graphics/Text.hpp"

#include "SFMLWidgets/Widget.h"

namespace sfml_widgets
{
    class TextWidget;
    class View;
}

/// @brief Just a decorative rectangle widget without any callbacks.
class sfml_widgets::TextWidget : public sfml_widgets::Widget,
                                 public sf::Text
{
public:
    /// @brief Constructor.
    /// @details Place the widget on given view and registry it in view's window.
    /// @param view View where widget will be placed.
    TextWidget(sfml_widgets::View* view);

private:
    /// @brief  Call window draw method to paint the widget.
    void paint(sfml_widgets::Window& window);

    sf::Font _font;
};

#endif // TEXTWIDGET_H
