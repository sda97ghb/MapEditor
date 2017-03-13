#ifndef MOVABLE_H
#define MOVABLE_H

#include <functional>

#include "SFMLWidgets/EventProcessor.h"
#include "SFMLWidgets/Widget.h"

namespace sfml_widgets
{
    class Movable;
    class View;
}

class sfml_widgets::Movable : sfml_widgets::Widget
{
public:
    Movable(sfml_widgets::View* view);

    void setOnGrabCallback(const std::function<void ()>& onGrabCallback);
    void setOnReleaseCallback(const std::function<void ()>& onReleaseCallback);
    void setOnMoveCallback(const std::function<void ()>& onMoveCallback);

protected:
    std::function<void()> _onGrabCallback;
    std::function<void()> _onReleaseCallback;
    std::function<void()> _onMoveCallback;

    bool _canMove;
    float _dx;
    float _dy;

private:
    friend void sfml_widgets::EventProcessor::mouseButtonPressedEvent(
            const sf::Mouse::Button &button, const sf::Vector2f &cursorPos);
    friend void sfml_widgets::EventProcessor::mouseButtonReleasedEvent(
            const sf::Mouse::Button &button, const sf::Vector2f &cursorPos);
    friend void sfml_widgets::EventProcessor::mouseMovedEvent(
            const sf::Vector2f &cursorPos);

    virtual void grab(const sf::Vector2f& cursorPos) = 0;
    virtual void release();
    virtual void move(const sf::Vector2f& cursorPos) = 0;
};

#endif // MOVABLE_H
