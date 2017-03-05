#include "MapEditor/PlatformDelegate.h"

void PlatformDelegate::setPlatform(Platform& platform)
{
    _platform = &platform;

    _vertexButtons.clear();

    for (uint32_t i = 0; i < platform.getPointCount(); ++ i)
    {
        _vertexButtons.emplace_back();
        VertexButton& button = _vertexButtons.back();

        button.setPosition(platform.getPoint(i));

        button.setOnMoveCallback([&platform, &button, i] () {
            platform.setPoint(i, button.getPosition());
        });
    }
}

void PlatformDelegate::grabButton(const sf::Vector2f& cursorPos)
{
    for (VertexButton& button : _vertexButtons)
        button.grab(cursorPos);
}

void PlatformDelegate::releaseButtons()
{
    for (VertexButton& button : _vertexButtons)
        button.release();
}

void PlatformDelegate::moveButton(const sf::Vector2f& cursorPos)
{
    for (VertexButton& button : _vertexButtons)
        button.move(cursorPos);
}

std::list<VertexButton>& PlatformDelegate::vertexButtons()
{
    return _vertexButtons;
}
