#ifndef POINTTESTER_H
#define POINTTESTER_H

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/ConvexShape.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

namespace sfml_widgets
{
    class PointTester;
}

class sfml_widgets::PointTester
{
public:
    static bool test(const sf::Vector2f& point, const sf::CircleShape& shape);
    static bool test(sf::Vector2f point, const sf::ConvexShape& shape);
    static bool test(const sf::Vector2f& point, const sf::RectangleShape& shape);
};

#endif // POINTTESTER_H
