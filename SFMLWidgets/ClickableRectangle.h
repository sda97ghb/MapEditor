#ifndef CLICKABLERECTANGLE_H
#define CLICKABLERECTANGLE_H

#include "SFML/Graphics/RectangleShape.hpp"

#include "SFMLWidgets/Clickable.h"

namespace sfml_widgets
{
    class ClickableRectangle;
    class Window;
}

class sfml_widgets::ClickableRectangle : public sfml_widgets::Clickable,
                                         public sf::RectangleShape
{
public:
    ClickableRectangle(sfml_widgets::View* view);

private:
    void testForClick(const sf::Vector2f& cursorPos);

    void paint(sfml_widgets::Window& window);
};

#endif // CLICKABLERECTANGLE_H
