#ifndef WIDGET_H
#define WIDGET_H

namespace sfml_widgets
{
    class Widget;
    class Window;
}

/// @brief Base abstract widget class.
class sfml_widgets::Widget
{
public:
    /// @brief Destructor.
    virtual ~Widget();

    /// @brief Call window draw method to paint the widget.
    virtual void paint(sfml_widgets::Window& window) = 0;
};

#endif // WIDGET_H
