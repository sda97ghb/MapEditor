#ifndef PLATFORMPROPERTIESDELEGATE_H
#define PLATFORMPROPERTIESDELEGATE_H

#include "SFML/Graphics/RenderWindow.hpp"

#include "MapEditor/Button.h"
#include "MapEditor/Platform.h"

class PlatformPropertiesDelegate
{
public:
    PlatformPropertiesDelegate();

    void paint(sf::RenderWindow& window);

    void setPlatform(Platform& platform);

    void testForClick(const sf::Vector2f& cursorPos);

private:
    Platform* _platform;

    Button _addVertexButton;
    Button _deleteVertexButton;
};

#endif // PLATFORMPROPERTIESDELEGATE_H
