#ifndef PLATFORM_H
#define PLATFORM_H

#include <list>

#include "SFML/Graphics/Texture.hpp"

#include "MapEditor/ClickableConvex.h"
#include "MapEditor/Properted.h"

class Platform : public ClickableConvex, public Properted
{
public:
    Platform();

    void setTexture(const sf::Texture *texture, bool resetRect = false);
    void setTexture(const std::string& filename);

    void setShape(const std::list<sf::Vector2f>& vertexes);

    float width() const;
    float height() const;

    bool canMove;
    int dx;
    int dy;

private:
    sf::Texture _texture;
};


#endif // PLATFORM_H
