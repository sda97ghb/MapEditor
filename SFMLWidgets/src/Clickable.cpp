#include "SFMLWidgets/Clickable.h"
#include "SFMLWidgets/View.h"

sfml_widgets::Clickable::Clickable(View* view) :
    Widget(view)
{
    view->eventProcessor().registryClickable(this);
}

sfml_widgets::Clickable::~Clickable()
{
    _view->eventProcessor().deleteClickable(this);
}

void sfml_widgets::Clickable::setOnClickCallback(
        const std::function<void()>& callback)
{
    _onClickCallback = callback;
}
