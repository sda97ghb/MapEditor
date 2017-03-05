#include "MapEditor/Model.h"
#include "MapEditor/Platform.h"

Platform::Platform() :
    canMove(false),
    dx(0),
    dy(0)
{
    setInt("number_of_vertexes", 0);
}

void Platform::setShape(const std::list<sf::Vector2f>& vertexes)
{
    setInt("number_of_vertexes", vertexes.size());

    setPointCount(vertexes.size());

    int i = 0;
    for (const sf::Vector2f& vertex : vertexes)
        setPoint(i++, vertex);
}
