#include <iostream>

#include "MapEditor/MainWindow.h"
#include "MapEditor/Model.h"
#include "MapEditor/WorldView.h"

WorldView::WorldView(MainWindow* window) :
    _numOfButtons(0)
{
    _window = window;

    setCenter(0.0f, 0.0f);
    // scale view to make 1 physical meter equal to 1 grapical unit
    setSize(36.0f, -21.0f); // (36x21) == (1200x700) / 100 * 3
    setViewport(sf::FloatRect(0.0f, 0.0f, 0.8f, 1.0f)); // 1500 * 0.8 = 1200
}

void WorldView::paint()
{
    Model& model = Model::instance();

    for (Platform& platform : model.platforms())
        _window->draw(platform.shape);

    for (uint32_t i = 0; i < _numOfButtons; ++ i)
        _window->draw(_button[i]);

    sf::CircleShape zero;
    zero.setFillColor(sf::Color::Red);
    zero.setRadius(0.1f);
    zero.setPosition(0.0f, 0.0f);
    _window->draw(zero);
}

void WorldView::mousePressedEvent(const sf::Event::MouseButtonEvent& event)
{
    sf::Vector2f cursorPos = _window->mapPixelToCoords(sf::Vector2i(event.x,
                                                                    event.y));

    Platform& platform = Model::instance().platforms().back();
    _numOfButtons = platform.shape.getPointCount();
    for (uint32_t i = 0; i < _numOfButtons; ++ i)
    {
        _button[i].setPosition(platform.shape.getPoint(i));

        _button[i].setOnMoveCallback([&platform, this, i] () {
            platform.shape.setPoint(i, _button[i].getPosition());
        });

        _button[i].grab(cursorPos);
    }
}

void WorldView::mouseReleasedEvent(const sf::Event::MouseButtonEvent& event)
{
    sf::Vector2f cursorPos = _window->mapPixelToCoords(sf::Vector2i(event.x,
                                                                    event.y));
    (void)cursorPos;
    for (uint32_t i = 0; i < _numOfButtons; ++ i)
        _button[i].release();
}

void WorldView::mouseMovedEvent(const sf::Event::MouseMoveEvent& event)
{
    sf::Vector2f cursorPos = _window->mapPixelToCoords(sf::Vector2i(event.x,
                                                                    event.y));

    for (uint32_t i = 0; i < _numOfButtons; ++ i)
        _button[i].move(cursorPos);
}
