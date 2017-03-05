#include <iostream>

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

#include "MapEditor/PlatformPropertiesDelegate.h"

PlatformPropertiesDelegate::PlatformPropertiesDelegate()
{
    _addVertexButton.setPosition(20.0f, 80.0f);
    _addVertexButton.setSize(150.0f, 30.0f);
    _addVertexButton.setCallback([this] () {
        std::list<sf::Vector2f> vertexes = {sf::Vector2f(-1.0, -1.0),
                                            sf::Vector2f( 1.0, -1.0),
                                            sf::Vector2f( 1.0,  1.0),
                                            sf::Vector2f(-1.0,  1.0)};
        _platform->setShape(vertexes);
    });
}

void PlatformPropertiesDelegate::paint(sf::RenderWindow& window)
{
    sf::Text text;
    sf::Font font;
    font.loadFromFile("C:/Projects/GameMapEditor/Fonts/open-sans/OpenSans-Light.ttf");
    text.setFont(font);
    text.setCharacterSize(16u);
    text.setFillColor(sf::Color::White);

    text.setPosition(3.0f, 5.0f);
    text.setString("Current platform:");
    window.draw(text);

    text.setPosition(3.0f, 25.0f);
    text.setString(std::to_string((int)_platform));
    window.draw(text);

    if (_platform == nullptr)
        return;

    int i = 1;
    std::list<std::string> intProperties = _platform->intProperties();
    for (std::string& property : intProperties)
    {
        text.setPosition(3.0f, 25.0f + 20.0f * static_cast<float>(i++));
        text.setString(std::to_string(_platform->getInt(property)));
        window.draw(text);
    }

    window.draw(_addVertexButton);
}

void PlatformPropertiesDelegate::setPlatform(Platform& platform)
{
    _platform = &platform;
}

void PlatformPropertiesDelegate::testForClick(const sf::Vector2f& cursorPos)
{
    _addVertexButton.testForClick(cursorPos);
}
