#include "SFMLWidgets/Widget.h"
#include "SFMLWidgets/Window.h"

sfml_widgets::Widget::Widget(sfml_widgets::View* view)
{
    _view = view;
    _view->addWidget(this);
}

sfml_widgets::Widget::~Widget()
{
}
