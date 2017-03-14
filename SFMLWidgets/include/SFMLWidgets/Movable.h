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

/// @brief Abstract movable widget that can be grabbed with mouse and moved to
/// another place. Call onGrub, onMove, and onRelease callbacks.
/// @note This class don't know anything about shape. You should use
/// MovableRectangle, MovableConvex, MovableCircle, or inherited from them
/// widgets.
class sfml_widgets::Movable : sfml_widgets::Widget
{
public:
    /// @brief Constructor.
    /// @details Place a button on given view and registry it in view's window.
    Movable(sfml_widgets::View* view);

    /// @brief Set callback for grab action.
    /// @param [in] callback Lambda or regular c++ function.
    void setOnGrabCallback(const std::function<void ()>& callback);

    /// @brief Set callback for release action.
    /// @param [in] callback Lambda or regular c++ function.
    void setOnReleaseCallback(const std::function<void ()>& callback);

    /// @brief Set callback for move action.
    /// @param [in] callback Lambda or regular c++ function.
    void setOnMoveCallback(const std::function<void ()>& callback);

protected:
    std::function<void()> _onGrabCallback;   ///< OnGrab event callback.
    std::function<void()> _onReleaseCallback;///< OnRelease event callback.
    std::function<void()> _onMoveCallback;   ///< OnMove event callback.

    bool _canMove; ///< Defines whether can widget be moved on move action or not.
    float _dx; ///< Offset that will be add to cursor x coordinate to get left position.
    float _dy; ///< Offset that will be add to cursor y coordinate to get top position.

private:
    // Allow EventPorcessor to grab, move, and release the widget.
    friend void sfml_widgets::EventProcessor::mouseButtonPressedEvent(
            const sf::Mouse::Button &button, const sf::Vector2f &cursorPos);
    friend void sfml_widgets::EventProcessor::mouseButtonReleasedEvent(
            const sf::Mouse::Button &button, const sf::Vector2f &cursorPos);
    friend void sfml_widgets::EventProcessor::mouseMovedEvent(
            const sf::Vector2f &cursorPos);

    /// @brief Test if cursor is on the widget grab it, otherwise don't do
    /// anything.
    virtual void grab(const sf::Vector2f& cursorPos) = 0;

    /// @brief Release the widget without any condition.
    virtual void release();

    /// @brief Move the widget taking into account _dx and _dy.
    virtual void move(const sf::Vector2f& cursorPos) = 0;
};

#endif // MOVABLE_H
