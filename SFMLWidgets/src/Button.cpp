#include "SFMLWidgets/Button.h"

sfml_widgets::Button::Button(sfml_widgets::View* view) :
    sfml_widgets::ClickableRectangle(view)
{
    setOutlineThickness(2.0f);
    setFillColor(sf::Color(200, 200, 200));
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
