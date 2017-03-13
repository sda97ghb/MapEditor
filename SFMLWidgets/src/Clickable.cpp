#include "SFMLWidgets/Clickable.h"
#include "SFMLWidgets/View.h"

sfml_widgets::Clickable::Clickable(View* view)
{
    view->addWidget(this);
    view->eventProcessor().registryClickable(this);
}

void sfml_widgets::Clickable::setOnClickCallback(
        const std::function<void()>& callback)
{
    _onClickCallback = callback;
}
