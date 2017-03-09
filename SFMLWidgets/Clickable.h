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

class sfml_widgets::Clickable : public sfml_widgets::Widget
{
public:
    Clickable(sfml_widgets::View* view);

    void setOnClickCallback(const std::function<void()>& callback);

protected:
    std::function<void()> _onClickCallback;

private:
    friend void sfml_widgets::EventProcessor::mouseButtonReleasedEvent(
                const sf::Mouse::Button &button, const sf::Vector2f &cursorPos);
    virtual void testForClick(const sf::Vector2f& cursorPos) = 0;
};

#endif // CLICKABLE_H
