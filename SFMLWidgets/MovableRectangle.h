#ifndef MOVABLERECTANGLE_H
#define MOVABLERECTANGLE_H

#include "SFML/Graphics/RectangleShape.hpp"

#include "SFMLWidgets/Movable.h"

namespace sfml_widgets
{
    class MovableRectangle;
}

class sfml_widgets::MovableRectangle : public sfml_widgets::Movable,
                                       public sf::RectangleShape
{
public:
    MovableRectangle(sfml_widgets::View* view);

private:
    void grab(const sf::Vector2f& cursorPos);
    void move(const sf::Vector2f &cursorPos);

    void paint(sfml_widgets::Window &window);
};

#endif // MOVABLERECTANGLE_H
