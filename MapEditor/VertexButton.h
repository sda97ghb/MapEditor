#ifndef VERTEX_H
#define VERTEX_H

#include "MapEditor/MovableButton.h"

class VertexButton : public MovableButton
{
public:
    VertexButton();

    void setPosition(float x, float y);
    void setPosition(const sf::Vector2f& position);

    const sf::Vector2f getPosition() const;
};

#endif // VERTEX_H
