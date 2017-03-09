#include "SFMLWidgets/PointTester.h"

bool sfml_widgets::PointTester::test(const sf::Vector2f& point,
                                     const sf::CircleShape& shape)
{
    float radius = shape.getRadius();
    sf::Vector2f vec = point - shape.getPosition() - sf::Vector2f(radius, radius);
    return vec.x * vec.x + vec.y * vec.y <= radius * radius;
}

bool sfml_widgets::PointTester::test(sf::Vector2f point,
                                     const sf::ConvexShape& shape)
{
    if (shape.getPointCount() < 3)
        return false;

    point -= shape.getPosition();

    auto isPositive = [] (float v) -> bool
    {
        return v >= 0.0f;
    };

    auto crossProduction = [] (sf::Vector2f p1, sf::Vector2f p2) -> float
    {
        return p1.x * p2.y - p1.y * p2.x;
    };

    auto angle = [point, crossProduction, isPositive]
    (sf::Vector2f p1, sf::Vector2f p2) -> float
    {
        return crossProduction(p2 - p1, point - p1);
    };

    bool flag = isPositive(angle(shape.getPoint(shape.getPointCount() - 1),
                                 shape.getPoint(0)));

    for (uint32_t i = 1; i < shape.getPointCount(); ++ i)
        if (isPositive(angle(shape.getPoint(i - 1), shape.getPoint(i))) != flag)
            return false;

    return true;
}

bool sfml_widgets::PointTester::test(const sf::Vector2f& point,
                                     const sf::RectangleShape& shape)
{
    sf::Vector2f pos = shape.getPosition();
    sf::Vector2f size = shape.getSize();
    return point.x >= pos.x &&
           point.x <= pos.x + size.x &&
           point.y >= pos.y &&
           point.y <= pos.y + size.y;
}
