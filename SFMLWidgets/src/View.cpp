#include "SFMLWidgets/View.h"
#include "SFMLWidgets/Widget.h"
#include "SFMLWidgets/Window.h"

sfml_widgets::View::View(Window* window) :
    _window(window)
{
    _window->addView(this);
}

sfml_widgets::View::~View()
{
    for (Widget* widget : _widgets)
        delete widget;
}

sfml_widgets::EventProcessor& sfml_widgets::View::eventProcessor()
{
    return _eventProcessor;
}

void sfml_widgets::View::addWidget(sfml_widgets::Widget* widget)
{
    _widgets.push_back(widget);
}

void sfml_widgets::View::deleteWidget(sfml_widgets::Widget* widget)
{
    auto widgetIter = std::find(_widgets.begin(), _widgets.end(), widget);
    auto widgetIterEnd = widgetIter;
    std::advance(widgetIterEnd, 1);
    _widgets.erase(widgetIter, widgetIterEnd);
    delete widget;
}

std::list<sfml_widgets::Widget*>&sfml_widgets::View::widgets()
{
    return _widgets;
}
