#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <functional>

#include "SFMLWidgets/EventProcessor.h"
#include "SFMLWidgets/Widget.h"

namespace sfml_widgets
{
    class Clickable;
    class View;
}

/// @brief Abstract clickable object. Base class for all objects that should
/// have behaviour similar to button.
/// @note This class don't know anything about shape of button. You should use
/// ClickableRectangle, ClickableConvex, ClickableCircle or inherited from them
/// classes.
class sfml_widgets::Clickable : public sfml_widgets::Widget
{
public:
    /// @brief Constructor.
    /// @details Place button on given view and registry it in view's window.
    Clickable(sfml_widgets::View* view);

    /// @brief Set callback for click action.
    /// @param [in] callback Lambda or
    void setOnClickCallback(const std::function<void()>& callback);

protected:
    std::function<void()> _onClickCallback; ///< On click event callback.

private:
    // Allow EventProcessor to click this button.
    friend void sfml_widgets::EventProcessor::mouseButtonReleasedEvent(
                const sf::Mouse::Button &button, const sf::Vector2f &cursorPos);
    /// @brief Test if cursor is on the button make click, otherwise don't do
    /// anything.
    virtual void testForClick(const sf::Vector2f& cursorPos) = 0;
};

#endif // CLICKABLE_H
