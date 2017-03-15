#ifndef WIDGET_H
#define WIDGET_H

namespace sfml_widgets
{
    class View;
    class Widget;
    class Window;
}

/// @brief Base abstract widget class.
class sfml_widgets::Widget
{
public:
    /// @brief Constructor.
    /// @param view View where widget will be placed.
    Widget(sfml_widgets::View* view);

    /// @brief Destructor.
    virtual ~Widget();

    /// @brief Call window draw method to paint the widget.
    virtual void paint(sfml_widgets::Window& window) = 0;

protected:
    sfml_widgets::View* _view; ///< View where widget placed.
};

#endif // WIDGET_H
