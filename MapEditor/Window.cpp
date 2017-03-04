#include "MapEditor/Window.h"

Window::Window(int width, int height, const std::string& title) :
    sf::RenderWindow(sf::VideoMode(width, height), title,
                     sf::Style::Titlebar | sf::Style::Close)
{
}

void Window::mouseMovedEvent(const sf::Event::MouseMoveEvent& event)
{
    (void)event;
}

void Window::mousePressedEvent(const sf::Event::MouseButtonEvent& event)
{
    (void)event;
}

void Window::mouseReleasedEvent(const sf::Event::MouseButtonEvent& event)
{
    (void)event;
}

void Window::keyPressedEvent(const sf::Event::KeyEvent& event)
{
    (void)event;
}

void Window::keyReleasedEvent(const sf::Event::KeyEvent& event)
{
    (void)event;
}

void Window::run()
{
    while (isOpen())
    {
        sf::Event event;
        while (pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed :
                    close();
                    break;
                case sf::Event::MouseButtonPressed :
                    mousePressedEvent(event.mouseButton);
                    break;
                case sf::Event::MouseButtonReleased :
                    mouseReleasedEvent(event.mouseButton);
                    break;
                case sf::Event::MouseMoved :
                    mouseMovedEvent(event.mouseMove);
                case sf::Event::KeyPressed :
                    keyPressedEvent(event.key);
                case sf::Event::KeyReleased :
                    keyReleasedEvent(event.key);
                default :
                    break;
            }
        }

        paint();
    }
}
