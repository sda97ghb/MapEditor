#ifndef PLATFORMDELEGATE_H
#define PLATFORMDELEGATE_H

#include "MapEditor/VertexButton.h"
#include "MapEditor/Platform.h"

class PlatformDelegate
{
public:
    PlatformDelegate();

    void setPlatform(Platform& platform);

    void grabButton(const sf::Vector2f& cursorPos);
    void releaseButtons();

    void moveButton(const sf::Vector2f& cursorPos);

private:
    Platform* _platform;

    std::list<VertexButton> _vertexButtons;
};

#endif // PLATFORMDELEGATE_H
