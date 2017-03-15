#include "SFMLWidgets/Movable.h"
#include "SFMLWidgets/View.h"

sfml_widgets::Movable::Movable(View* view) :
    Widget(view),
    _canMove(false),
    _dx(0.0f),
    _dy(0.0f)
{
    view->eventProcessor().registryMovable(this);
}

sfml_widgets::Movable::~Movable()
{
    _view->eventProcessor().deleteMovable(this);
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

bool sfml_widgets::Movable::testForRelease()
{
    if (!_canMove)
        return false;

    _onReleaseCallback();
    _canMove = false;
    return true;
}
