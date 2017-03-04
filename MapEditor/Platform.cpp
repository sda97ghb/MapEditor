#include "MapEditor/Platform.h"

Platform::Platform() :
    canMove(false),
    dx(0),
    dy(0)
{
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(100.0, 100.0f);
}

void Platform::setShape(const std::list<sf::Vector2f>& vertexes)
{
    shape.setPointCount(vertexes.size());

    int i = 0;
    for (const sf::Vector2f& vertex : vertexes)
        shape.setPoint(i++, vertex);
}

void Platform::grab(float mouseX, float mouseY)
{
    dx = shape.getPosition().x - mouseX;
    dy = shape.getPosition().y - mouseY;
    canMove = true;
}

void Platform::release()
{
    canMove = false;
}

void Platform::move(float mouseX, float mouseY)
{
    shape.setPosition(mouseX + dx, mouseY + dy);
}
