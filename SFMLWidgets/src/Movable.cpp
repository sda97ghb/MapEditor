#include "SFMLWidgets/Movable.h"
#include "SFMLWidgets/View.h"

sfml_widgets::Movable::Movable(View* view)
{
    view->addWidget(this);
    view->eventProcessor().registryMovable(this);
}

void sfml_widgets::Movable::setOnGrabCallback(const std::function<void ()>& callback)
{
    _onGrabCallback = callback;
}

void sfml_widgets::Movable::setOnReleaseCallback(const std::function<void ()>& callback)
{
    _onReleaseCallback = callback;
}

void sfml_widgets::Movable::setOnMoveCallback(const std::function<void ()>& callback)
{
    _onMoveCallback = callback;
}

void sfml_widgets::Movable::release()
{
    _canMove = false;
    _onReleaseCallback();
}
