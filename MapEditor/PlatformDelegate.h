#ifndef PLATFORMDELEGATE_H
#define PLATFORMDELEGATE_H

#include "MapEditor/Delegate.h"
#include "MapEditor/Platform.h"
#include "MapEditor/VertexButton.h"

class PlatformDelegate : public Delegate
{
public:
    void reset();
    void setPlatform(Platform& platform);

    void grabButton(const sf::Vector2f& cursorPos);
    void releaseButtons();

    void moveButton(const sf::Vector2f& cursorPos);

    std::vector<VertexButton>& vertexButtons();

    void paint(sf::RenderWindow& window);
    void testForClick(const sf::Vector2f& cursorPos);

private:
    Platform* _platform;

    std::vector<VertexButton> _vertexButtons;
};

#endif // PLATFORMDELEGATE_H
