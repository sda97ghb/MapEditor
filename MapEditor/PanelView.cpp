#include <iostream>

#include "MapEditor/Model.h"
#include "MapEditor/PanelView.h"

PanelView::PanelView(Window* window) :
    _window(window)
{
    setSize(300.0f, 700.0f);
    setCenter(150.0f, 350.0f);
    setViewport(sf::FloatRect(0.8f, 0.0f, 0.2f, 1.0f)); // 1500 * 0.2 = 300
}

void PanelView::paint()
{
    Model::Index index = Model::instance().currentIndex();

    switch (index.type)
    {
        case Model::Index::Type::platform :
        {
            Platform& platform = *static_cast<Platform*>(index.object);
            _platformPropertiesDelegate.setPlatform(platform);
            _platformPropertiesDelegate.paint(*_window);
        } break;
        case Model::Index::Type::null :
            break;
    }

    sf::RectangleShape splitter;
    splitter.setFillColor(sf::Color(0x002222FF));
    splitter.setPosition(0.0f, 0.0f);
    splitter.setSize(sf::Vector2f(3.0f, getSize().y));
    _window->draw(splitter);

//    sf::Vertex line[2] = {sf::Vertex(sf::Vector2f(0.0f, 0.0f)),
//                          sf::Vertex(sf::Vector2f(0.0f, 0.0f))};
//    _window->draw(line, 2, sf::Lines);

//    sf::CircleShape zero;
//    zero.setFillColor(sf::Color::Red);
//    zero.setRadius(2.0f);
//    zero.setPosition(0.0f, 0.0f);
//    _window->draw(zero);
}

void PanelView::mouseReleasedEvent(const sf::Event::MouseButtonEvent& event)
{
    sf::Vector2f cursorPos = _window->mapPixelToCoords(sf::Vector2i(event.x, event.y));
    Model::Index index = Model::instance().currentIndex();

    switch (index.type)
    {
        case Model::Index::Type::platform :
            _platformPropertiesDelegate.testForClick(cursorPos);
            break;
        case Model::Index::Type::null :
            break;
    }
}
