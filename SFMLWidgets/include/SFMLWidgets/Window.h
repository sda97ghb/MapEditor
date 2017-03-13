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

class sfml_widgets::Window : public sf::RenderWindow
{
public:
    Window(uint32_t width, uint32_t height,
           const std::string& title, uint32_t style = sf::Style::Default,
           const sf::ContextSettings& settings = sf::ContextSettings());

    ~Window();

    void run();

    void mouseButtonPressedEvent(const sf::Event::MouseButtonEvent& event);
    void mouseButtonReleasedEvent(const sf::Event::MouseButtonEvent& event);
    void mouseMovedEvent(const sf::Event::MouseMoveEvent& event);

    void setClearColor(const sf::Color& color);

protected:
    friend sfml_widgets::View::View(sfml_widgets::Window*);
    void addView(sfml_widgets::View* view);
    std::list<sfml_widgets::View*> _views;

    sf::Color _clearColor;
};

#endif // WINDOW_H
