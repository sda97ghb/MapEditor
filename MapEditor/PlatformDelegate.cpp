#include "PlatformDelegate.h"

PlatformDelegate::PlatformDelegate()
{
}

void PlatformDelegate::setPlatform(Platform& platform)
{
    _platform = &platform;

    _vertexButtons.clear();

    uint32_t _numOfButtons = platform.shape.getPointCount();
    for (uint32_t i = 0; i < _numOfButtons; ++ i)
    {
        _vertexButtons.emplace_back();
        VertexButton& button = _vertexButtons.back();

        button.setPosition(platform.shape.getPoint(i));

        button.setOnMoveCallback([&platform, &button, i] () {
            platform.shape.setPoint(i, button.getPosition());
        });

//        button.grab(cursorPos);
    }
}

void PlatformDelegate::grabButton(const sf::Vector2f& cursorPos)
{

}

void PlatformDelegate::releaseButtons()
{

}

void PlatformDelegate::moveButton(const sf::Vector2f& cursorPos)
{

}
