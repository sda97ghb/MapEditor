#include <iostream>

#include "SFML/Graphics/Text.hpp"

#include "MapEditor/Model.h"
#include "MapEditor/PlatformPropertiesDelegate.h"

PlatformPropertiesDelegate::PlatformPropertiesDelegate()
{
    _addVertexButton.setPosition(10.0f, 80.0f);
    _addVertexButton.setSize(30.0f, 30.0f);
    _addVertexButton.setFillColor(sf::Color(34, 177, 76));
    _addVertexButton.setCallback([this] () {
        if (_platform->getPointCount() < 3)
        {
            std::list<sf::Vector2f> vertexes = {sf::Vector2f(-1.0, -1.0),
                                                sf::Vector2f( 1.0, -1.0),
                                                sf::Vector2f( 1.0,  1.0),
                                                sf::Vector2f(-1.0,  1.0)};
            _platform->setShape(vertexes);
        }
        else
        {
            _platform->setPointCount(_platform->getPointCount() + 1);
            uint32_t lastNum = _platform->getPointCount() - 1;
            _platform->setPoint(lastNum,
                _platform->getPoint(lastNum - 1) + sf::Vector2f(0.5f, -0.5f));
        }
        Model::instance().notifyChanged(Index(Index::Type::platform, _platform));
    });

    _deleteVertexButton.setPosition(50.0f, 80.0f);
    _deleteVertexButton.setSize(30.0f, 30.0f);
    _deleteVertexButton.setFillColor(sf::Color(225, 47, 55));
    _deleteVertexButton.setCallback([this] () {
        if (_platform->getPointCount() <= 3)
            return;
        _platform->setPointCount(_platform->getPointCount() - 1);
        Model::instance().notifyChanged(Index(Index::Type::platform, _platform));
    });

    _font.loadFromFile("C:/Projects/GameMapEditor/Fonts/open-sans/OpenSans-Light.ttf");
}

void PlatformPropertiesDelegate::paint(sf::RenderWindow& window)
{
    sf::Text text;
    text.setFont(_font);
    text.setCharacterSize(16u);
    text.setFillColor(sf::Color::White);

    text.setPosition(10.0f, 10.0f);
    text.setString("Current platform:");
    window.draw(text);

    text.setPosition(10.0f, 30.0f);
    text.setString(std::to_string((int)_platform));
    window.draw(text);

    if (_platform == nullptr)
        return;

    int i = 1;
    std::list<std::string> intProperties = _platform->intProperties();
    for (std::string& property : intProperties)
    {
        text.setPosition(10.0f, 30.0f + 20.0f * static_cast<float>(i++));
        text.setString(std::to_string(_platform->getInt(property)));
        window.draw(text);
    }

    window.draw(_addVertexButton);
    window.draw(_deleteVertexButton);
}

void PlatformPropertiesDelegate::setPlatform(Platform& platform)
{
    _platform = &platform;
}

void PlatformPropertiesDelegate::testForClick(const sf::Vector2f& cursorPos)
{
    _addVertexButton.testForClick(cursorPos);
    _deleteVertexButton.testForClick(cursorPos);
}
