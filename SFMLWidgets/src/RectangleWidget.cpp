#include "SFMLWidgets/RectangleWidget.h"
#include "SFMLWidgets/Window.h"

sfml_widgets::RectangleWidget::RectangleWidget(sfml_widgets::View* view)
{
    view->addWidget(this);
}

void sfml_widgets::RectangleWidget::paint(sfml_widgets::Window& window)
{
    window.draw(*this);
}
