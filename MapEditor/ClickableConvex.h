#ifndef CLICKABLECONVEX_H
#define CLICKABLECONVEX_H

#include <functional>

#include "SFML/Graphics/ConvexShape.hpp"

class ClickableConvex : public sf::ConvexShape
{
public:
    void testForClick(const sf::Vector2f& cursorPos);

    void setOnClickCallback(const std::function<void()>& callback);

protected:
    std::function<void()> _onClickCallback;
};

#endif // CLICKABLECONVEX_H
