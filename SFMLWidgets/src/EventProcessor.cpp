#include "SFMLWidgets/Clickable.h"
#include "SFMLWidgets/EventProcessor.h"
#include "SFMLWidgets/Movable.h"

void sfml_widgets::EventProcessor::mouseButtonPressedEvent(
        const sf::Mouse::Button& button, const sf::Vector2f& cursorPos)
{
    if (button == sf::Mouse::Button::Left)
    {
        for (sfml_widgets::Movable* movable : _movables)
            movable->grab(cursorPos);
    }
}

void sfml_widgets::EventProcessor::mouseButtonReleasedEvent(
        const sf::Mouse::Button& button, const sf::Vector2f& cursorPos)
{
    if (button == sf::Mouse::Button::Left)
    {
        for (sfml_widgets::Clickable* clickable : _clickables)
            clickable->testForClick(cursorPos);
        for (sfml_widgets::Movable* movable : _movables)
            movable->release();
    }
}

void sfml_widgets::EventProcessor::mouseMovedEvent(const sf::Vector2f& cursorPos)
{
    for (sfml_widgets::Movable* movable : _movables)
        movable->move(cursorPos);
}

void sfml_widgets::EventProcessor::registryClickable(
        sfml_widgets::Clickable* clickable)
{
    _clickables.push_back(clickable);
}

void sfml_widgets::EventProcessor::registryMovable(
        sfml_widgets::Movable* movable)
{
    _movables.push_back(movable);
}
