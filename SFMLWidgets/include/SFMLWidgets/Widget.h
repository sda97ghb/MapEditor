#ifndef WIDGET_H
#define WIDGET_H

namespace sfml_widgets
{
    class Widget;
    class Window;
}

class sfml_widgets::Widget
{
public:
    virtual ~Widget();
    virtual void paint(sfml_widgets::Window& window) = 0;
};

#endif // WIDGET_H
