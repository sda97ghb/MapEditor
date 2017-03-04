#include <iostream>

#include "MapEditor/MainWindow.h"
#include "MapEditor/Model.h"
#include "MapEditor/WorldView.h"

WorldView::WorldView(MainWindow* window)
{
    _window = window;

    setCenter(0.0f, 0.0f);
    // scale view to make 1 physical meter equal to 1 grapical unit
    setSize(36.0f, -21.0f); // (36x21) == (1200x700) / 100 * 3
    setViewport(sf::FloatRect(0.0f, 0.0f, 0.8f, 1.0f)); // 1500 * 0.8 = 1200
}

void WorldView::paint()
{
    {
        Model& model = Model::instance();

        for (Platform& platform : model.platforms())
            _window->draw(platform.shape);
    }

    for (VertexButton& button : _platformDeligate.vertexButtons())
        _window->draw(button);

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

    _platformDeligate.setPlatform(Model::instance().platforms().back());

    _platformDeligate.grabButton(cursorPos);
}

void WorldView::mouseReleasedEvent(const sf::Event::MouseButtonEvent& event)
{
    sf::Vector2f cursorPos = _window->mapPixelToCoords(sf::Vector2i(event.x,
                                                                    event.y));
    (void)cursorPos;
    _platformDeligate.releaseButtons();
}

void WorldView::mouseMovedEvent(const sf::Event::MouseMoveEvent& event)
{
    sf::Vector2f cursorPos = _window->mapPixelToCoords(sf::Vector2i(event.x,
                                                                    event.y));

    _platformDeligate.moveButton(cursorPos);
}
