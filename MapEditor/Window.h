#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class Window : public sf::RenderWindow
{
public:
    Window(int width, int height, const std::string& title);

    virtual void mouseMovedEvent(const sf::Event::MouseMoveEvent& event);
    virtual void mousePressedEvent(const sf::Event::MouseButtonEvent& event);
    virtual void mouseReleasedEvent(const sf::Event::MouseButtonEvent& event);

    virtual void keyPressedEvent(const sf::Event::KeyEvent& event);
    virtual void keyReleasedEvent(const sf::Event::KeyEvent& event);

    virtual void paint() = 0;

    virtual void run() final;
};

#endif // WINDOW_H
