#include <iostream>
#include "SFMLWidgets/Button.h"
#include "SFMLWidgets/Window.h"

sfml_widgets::Button::Button(sfml_widgets::View* view) :
    sfml_widgets::ClickableRectangle(view)
{
    setOutlineThickness(2.0f);
    setFillColor(sf::Color(200, 200, 200));

    const std::string FONTS_DIR = "C:/Projects/Builds/build-GameMapEditor-Desktop_Qt_5_7_0_MinGW_32bit-Debug/MapEditor/debug/Fonts";
    _font.loadFromFile(FONTS_DIR + "/open-sans/OpenSans-Regular.ttf");
    _text.setFont(_font);
    _text.setCharacterSize(12);
    _text.setFillColor(sf::Color::Black);
}

void sfml_widgets::Button::setFillColor(const sf::Color& color)
{
    sf::Color outlineColor = color;
    outlineColor.r = static_cast<uint8_t>(outlineColor.r * 0.6);
    outlineColor.g = static_cast<uint8_t>(outlineColor.g * 0.6);
    outlineColor.b = static_cast<uint8_t>(outlineColor.b * 0.6);
    setOutlineColor(outlineColor);
    sf::RectangleShape::setFillColor(color);
}

void sfml_widgets::Button::setText(const std::string& text)
{
    _text.setString(text);
}

void sfml_widgets::Button::setText(const std::wstring& text)
{
    _text.setString(text);
}

std::string sfml_widgets::Button::text() const
{
    return _text.getString();
}

void sfml_widgets::Button::paint(sfml_widgets::Window& window)
{
    window.draw(*this);

    sf::FloatRect textBounds = _text.getLocalBounds();
    sf::Vector2f pos = this->getPosition();
    pos += this->getSize() / 2.0f;
    pos -= sf::Vector2f(textBounds.width, textBounds.height) / 2.0f;
    _text.setPosition(pos);
    window.draw(_text);
}
