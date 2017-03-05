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
    Index index = Model::instance().currentIndex();

    switch (index.type)
    {
        case Index::Type::platform :
        {
            Platform& platform = *static_cast<Platform*>(index.object);
            _platformPropertiesDelegate.setPlatform(platform);
            _platformPropertiesDelegate.paint(*_window);
        } break;
        case Index::Type::null :
            break;
    }

    sf::RectangleShape splitter;
    splitter.setFillColor(sf::Color(50, 50, 50));
    splitter.setPosition(0.0f, 0.0f);
    splitter.setSize(sf::Vector2f(2.0f, getSize().y));
    _window->draw(splitter);
}

void PanelView::mouseReleasedEvent(const sf::Event::MouseButtonEvent& event)
{
    sf::Vector2f cursorPos = _window->mapPixelToCoords(sf::Vector2i(event.x, event.y));
    Index index = Model::instance().currentIndex();

    switch (index.type)
    {
        case Index::Type::platform :
            _platformPropertiesDelegate.testForClick(cursorPos);
            break;
        case Index::Type::null :
            break;
    }
}
