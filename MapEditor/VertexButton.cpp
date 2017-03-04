#include "VertexButton.h"

VertexButton::VertexButton()
{
    setSize(sf::Vector2f(0.3f, 0.3f));
    setFillColor(sf::Color(255, 127, 0));
}

void VertexButton::setPosition(float x, float y)
{
    sf::Vector2f size = getSize();
    size.x /= 2.0f;
    size.y /= 2.0f;
    Transformable::setPosition(x - size.x, y - size.y);
}

void VertexButton::setPosition(const sf::Vector2f& position)
{
    sf::Vector2f size = getSize();
    size.x /= 2.0f;
    size.y /= 2.0f;
    Transformable::setPosition(position - size);
}

const sf::Vector2f VertexButton::getPosition() const
{
    sf::Vector2f size = getSize();
    size.x /= 2.0f;
    size.y /= 2.0f;
    return Transformable::getPosition() + size;
}
