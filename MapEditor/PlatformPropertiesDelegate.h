#ifndef PLATFORMPROPERTIESDELEGATE_H
#define PLATFORMPROPERTIESDELEGATE_H

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

#include "MapEditor/Button.h"
#include "MapEditor/Delegate.h"
#include "MapEditor/Platform.h"

class PlatformPropertiesDelegate : public Delegate
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

    sf::Font _font;
};

#endif // PLATFORMPROPERTIESDELEGATE_H
