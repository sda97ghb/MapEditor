#ifndef POINTTESTER_H
#define POINTTESTER_H

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/ConvexShape.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

namespace sfml_widgets
{
    class PointTester;
}

/// @brief Test whether is a point on a shape or not.
class sfml_widgets::PointTester
{
public:
    /// @brief Test whether is a point on a circle or not.
    static bool test(const sf::Vector2f& point, const sf::CircleShape& shape);

    /// @brief Test whether is a point on a polygon or not.
    static bool test(sf::Vector2f point, const sf::ConvexShape& shape);

    /// @brief Test whether is a point on a rectangle or not.
    static bool test(const sf::Vector2f& point, const sf::RectangleShape& shape);
};

#endif // POINTTESTER_H
