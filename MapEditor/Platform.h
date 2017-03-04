#ifndef PLATFORM_H
#define PLATFORM_H

#include <list>

#include "SFML/Graphics/ConvexShape.hpp"

struct Platform
{
    Platform();

    void setShape(const std::list<sf::Vector2f>& vertexes);

    void grab(float mouseX, float mouseY);
    void release();

    void move(float mouseX, float mouseY);

    sf::ConvexShape shape;
    bool canMove;
    int dx;
    int dy;

private:

};


#endif // PLATFORM_H
