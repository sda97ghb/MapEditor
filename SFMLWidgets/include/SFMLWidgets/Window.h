#ifndef WINDOW_H
#define WINDOW_H

#include <list>

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

#include "SFMLWidgets/View.h"

namespace sfml_widgets
{
    class Window;
}

/// @brief Window class.
class sfml_widgets::Window : public sf::RenderWindow
{
public:
    /// @brief Create window with given parameters.
    Window(uint32_t width, uint32_t height,
           const std::string& title, uint32_t style = sf::Style::Default,
           const sf::ContextSettings& settings = sf::ContextSettings());

    /// @brief Automatically delete all views.
    ~Window();

    /// @brief Run window. Stop flow until window is closed.
    void run();

    /// @brief Call mouse press event processing for all event processors.
    void mouseButtonPressedEvent(const sf::Event::MouseButtonEvent& event);

    /// @brief Call mouse release event processing for all event processors.
    void mouseButtonReleasedEvent(const sf::Event::MouseButtonEvent& event);

    /// @brief Call mouse move event processing for all event processors.
    void mouseMovedEvent(const sf::Event::MouseMoveEvent& event);

    /// @brief Set background color for window.
    void setClearColor(const sf::Color& color);

    virtual void update();

protected:
    // Allow view regisrty itself.
    friend sfml_widgets::View::View(sfml_widgets::Window*);

    /// @brief Registry new view.
    void addView(sfml_widgets::View* view);

    std::list<sfml_widgets::View*> _views; ///< List of all views.

    sf::Color _clearColor; ///< Background color.
};

#endif // WINDOW_H
