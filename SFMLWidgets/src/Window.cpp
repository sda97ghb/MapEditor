#include "SFMLWidgets/Widget.h"
#include "SFMLWidgets/Window.h"

sfml_widgets::Window::Window(uint32_t width, uint32_t height,
                             const std::string& title, uint32_t style,
                             const sf::ContextSettings& settings) :
    sf::RenderWindow(sf::VideoMode(width, height), title, style, settings),
    _clearColor(sf::Color::Black)
{
}

sfml_widgets::Window::~Window()
{
    for (sfml_widgets::View* view : _views)
        delete view;
}

void sfml_widgets::Window::run(float fps)
{
    float frameDelay = 1000.0f / fps;
    _frameClock.restart();
    while (isOpen())
        if (_frameClock.getElapsedTime().asMilliseconds() > frameDelay)
        {
            _frameClock.restart();
            update();
        }
}

void sfml_widgets::Window::mouseButtonPressedEvent(
        const sf::Event::MouseButtonEvent& event)
{
    sf::Vector2i cursorPos(event.x, event.y);

    for (sfml_widgets::View* viewPtr : _views)
    {
        sfml_widgets::View& view = *viewPtr;
        setView(view);
        sfml_widgets::EventProcessor& eventProcessor = view.eventProcessor();
        eventProcessor.mouseButtonPressedEvent(event.button,
                                               mapPixelToCoords(cursorPos));
    }
}

void sfml_widgets::Window::mouseButtonReleasedEvent(
        const sf::Event::MouseButtonEvent& event)
{
    sf::Vector2i cursorPos(event.x, event.y);

    for (sfml_widgets::View* viewPtr : _views)
    {
        sfml_widgets::View& view = *viewPtr;
        setView(view);
        sfml_widgets::EventProcessor& eventProcessor = view.eventProcessor();
        eventProcessor.mouseButtonReleasedEvent(event.button,
                                                mapPixelToCoords(cursorPos));
    }
}

void sfml_widgets::Window::mouseMovedEvent(
        const sf::Event::MouseMoveEvent& event)
{
    sf::Vector2i cursorPos(event.x, event.y);

    for (sfml_widgets::View* viewPtr : _views)
    {
        sfml_widgets::View& view = *viewPtr;
        setView(view);
        sfml_widgets::EventProcessor& eventProcessor = view.eventProcessor();
        eventProcessor.mouseMovedEvent(mapPixelToCoords(cursorPos));
    }
}

void sfml_widgets::Window::setClearColor(const sf::Color& color)
{
    _clearColor = color;
}

void sfml_widgets::Window::onUpdate()
{
    ;
}

void sfml_widgets::Window::onPaint()
{
    ;
}

void sfml_widgets::Window::update()
{
    sf::Event event;
    while (pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::MouseButtonPressed :
                mouseButtonPressedEvent(event.mouseButton);
                break;
            case sf::Event::MouseButtonReleased :
                mouseButtonReleasedEvent(event.mouseButton);
                break;
            case sf::Event::MouseMoved :
                mouseMovedEvent(event.mouseMove);
                break;
            case sf::Event::Closed :
                close();
                break;
            default :
                break;
        }
    }

    onUpdate();

    clear(_clearColor);

    for (sfml_widgets::View* view : _views)
    {
        setView(*view);
        for (sfml_widgets::Widget* widget : view->widgets())
            widget->paint(*this);
    }

    onPaint();

    display();
}

void sfml_widgets::Window::addView(sfml_widgets::View* view)
{
    _views.push_back(view);
}
