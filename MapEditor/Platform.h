#ifndef PLATFORM_H
#define PLATFORM_H

#include <list>

#include "MapEditor/ClickableConvex.h"
#include "MapEditor/Properted.h"

class Platform : public ClickableConvex, public Properted
{
public:
    Platform();

    void setShape(const std::list<sf::Vector2f>& vertexes);

    bool canMove;
    int dx;
    int dy;
};


#endif // PLATFORM_H
