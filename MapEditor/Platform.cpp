#include "MapEditor/Model.h"
#include "MapEditor/Platform.h"

Platform::Platform() :
    canMove(false),
    dx(0),
    dy(0)
{
    addIntProperty("number_of_vertexes",
                   [this] () -> int {
                       return getPointCount();
                   },
                   [this] (int count) -> void {
                       setPointCount(count);
                   });
}

void Platform::setTexture(const sf::Texture* texture, bool resetRect)
{
    sf::ConvexShape::setTexture(texture, resetRect);
}

void Platform::setTexture(const std::string& filename)
{
    _texture.loadFromFile(filename);
    sf::ConvexShape::setTexture(&_texture);
}

void Platform::setShape(const std::list<sf::Vector2f>& vertexes)
{
    setInt("number_of_vertexes", vertexes.size());

    setPointCount(vertexes.size());

    int i = 0;
    for (const sf::Vector2f& vertex : vertexes)
        setPoint(i++, vertex);
}

float Platform::width() const
{
    if (getPointCount() == 0)
        return 0.0f;

    sf::Vector2f left = getPoint(0);
    sf::Vector2f right = getPoint(0);

    for (uint32_t i = 0; i < getPointCount(); ++ i)
    {
        sf::Vector2f point = getPoint(i);
        if (point.x < left.x)
            left = point;
        if (point.x > right.x)
            right = point;
    }

    return right.x - left.x;
}

float Platform::height() const
{
    if (getPointCount() == 0)
        return 0.0f;

    sf::Vector2f top = getPoint(0);
    sf::Vector2f bottom = getPoint(0);

    for (uint32_t i = 0; i < getPointCount(); ++ i)
    {
        sf::Vector2f point = getPoint(i);
        if (point.y < bottom.y)
            bottom = point;
        if (point.y > top.y)
            top = point;
    }

    return top.y - bottom.y;
}
