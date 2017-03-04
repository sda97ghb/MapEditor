#include "MapEditor/CoordinateTranslation.h"

sf::Vector2f translate(sf::Vector2f pos)
{
    pos.y *= -1;
    return pos;
}
