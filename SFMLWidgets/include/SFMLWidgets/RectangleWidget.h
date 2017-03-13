#ifndef RECTANGLEWIDGET_H
#define RECTANGLEWIDGET_H

#include "SFML/Graphics/RectangleShape.hpp"

#include "SFMLWidgets/Widget.h"

namespace sfml_widgets
{
    class RectangleWidget;
    class View;
}

class sfml_widgets::RectangleWidget : public sfml_widgets::Widget,
                                      public sf::RectangleShape
{
public:
    RectangleWidget(sfml_widgets::View* view);

private:
    void paint(sfml_widgets::Window& window);
};

#endif // RECTANGLEWIDGET_H
