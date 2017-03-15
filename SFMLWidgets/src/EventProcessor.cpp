#include <algorithm>

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
            if (clickable->testForClick(cursorPos))
                break;
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

void sfml_widgets::EventProcessor::deleteClickable(
        sfml_widgets::Clickable* clickable)
{
    auto clickableIter = std::find(_clickables.begin(), _clickables.end(),
                                   clickable);
    if (clickableIter == _clickables.end())
        return;
    _clickables.erase(clickableIter);
}

void sfml_widgets::EventProcessor::deleteMovable(sfml_widgets::Movable* movable)
{
    auto movableIter = std::find(_movables.begin(), _movables.end(), movable);
    if (movableIter == _movables.end())
        return;
    _movables.erase(movableIter);
}
