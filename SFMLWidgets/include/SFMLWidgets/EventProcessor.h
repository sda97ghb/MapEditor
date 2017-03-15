#ifndef EVENTPROCESSOR_H
#define EVENTPROCESSOR_H

#include <list>

#include "SFML/Window/Mouse.hpp"

namespace sfml_widgets
{
    class Clickable;
    class EventProcessor;
    class Movable;
}

/// @brief Process events such as mouse press, release or move.
/// @details Call testForClick for all clickable, call grab, move, and release
/// for all movable.
class sfml_widgets::EventProcessor
{
public:
    /// @brief Process mouse press button event.
    void mouseButtonPressedEvent(const sf::Mouse::Button& button,
                                 const sf::Vector2f& cursorPos);
    /// @brief Process mouse release button event.
    void mouseButtonReleasedEvent(const sf::Mouse::Button& button,
                                  const sf::Vector2f& cursorPos);
    /// @brief Process mouse cursor move event.
    void mouseMovedEvent(const sf::Vector2f& cursorPos);

    /// @brief Registry new clickable.
    /// @note If you created clickable but forgot registry it click didn't work.
    void registryClickable(sfml_widgets::Clickable* clickable);

    /// @brief Registry new movable.
    /// @note If you created movable but forgot registry it grab, move, and
    /// release didn't work.
    void registryMovable(sfml_widgets::Movable* movable);

    /// @brief Delete clickable from the list.
    void deleteClickable(sfml_widgets::Clickable* clickable);

    /// @brief Delete movable from the list.
    void deleteMovable(sfml_widgets::Movable* movable);

private:
    std::list<sfml_widgets::Clickable*> _clickables; ///< List of all registred clickable.
    std::list<sfml_widgets::Movable*> _movables; ///< List of all registred movable.
};

#endif // EVENTPROCESSOR_H
