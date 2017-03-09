#include <iostream>

#include "MapEditor/Model.h"
#include "MapEditor/PlatformDelegate.h"

void PlatformDelegate::reset()
{
    _platform = nullptr;
    _vertexButtons.clear();
}

void PlatformDelegate::setPlatform(Platform& platform)
{
    _platform = &platform;

    if (vertexButtons().size() != platform.getPointCount())
        _vertexButtons.resize(platform.getPointCount());

    for (uint32_t i = 0; i < platform.getPointCount(); ++ i)
    {
        VertexButton& button = _vertexButtons[i];

        button.setPosition(platform.getPoint(i));

        button.setOnMoveCallback([&platform, &button, i] () {
            platform.setPoint(i, button.getPosition());
            platform.setTextureRect(sf::IntRect(0, 0,
                                                16 * platform.width(),
                                                16 * platform.height()));
//            Model::instance().notifyChanged(Index(Index::Type::platform, &platform));
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

std::vector<VertexButton>& PlatformDelegate::vertexButtons()
{
    return _vertexButtons;
}

void PlatformDelegate::paint(sf::RenderWindow& window)
{
    (void)window;
}

void PlatformDelegate::testForClick(const sf::Vector2f& cursorPos)
{
    (void)cursorPos;
}
